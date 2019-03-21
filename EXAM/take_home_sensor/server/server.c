#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>

// A function that prevents any possible edits if the system anticipates a write
// Here the critical time is from file write to 50 ms and after 1950 ms.
// A good read should occur between these time frame, this function reads the modified time of the files
// and waits if currently in the critical time
long int file_wait(char * path){
	struct stat info;
	struct timeval timm;
	long int modification_ms, timmnow, tim_diff;
	
	int go = 0;
	while(go == 0){
		stat(path, &info);
		gettimeofday(&timm, NULL);
		modification_ms = info.st_mtime * 1000 + info.st_mtim.tv_nsec / 1000000;
		timmnow = timm.tv_sec * 1000 + timm.tv_usec/1000;
		tim_diff = timmnow - modification_ms;
		if(tim_diff > 50 && tim_diff < 1950)go = 1;
	}
	return timmnow - modification_ms;
	//printf("%ld %ld %ld\n", modification_ms, timmnow, timmnow - modification_ms);
}


// Main
int main(int argc, char const *argv[]) 
{ 
	// Socket create
	int server_fd, new_socket, valread; 
	struct sockaddr_in address; 
	int opt = 1; 
	int addrlen = sizeof(address); 
	
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) return -1; // Socket file descriptor
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt))) return -1; // attach
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons(6000); // Port address
	if (bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0) return -1; // Bind
	if (listen(server_fd, 3) < 0)  return -1; // Start listening

	// Run forever
	while(1){
		if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))>=0){ // Wait
			if(fork() == 0){
				while(1){
					// New request to read data
					char buffer[1024] = {0}; 
					valread = read( new_socket , buffer, 1024); 
					printf("Request: %s\n",buffer); 
			
					// Wait for a new write
					file_wait("sensor1.txt");
					file_wait("sensor2.txt");
					file_wait("sensor3.txt");
					file_wait("sensor4.txt");
					long int prev_edit = file_wait("sensor5.txt");
					
					// Open files for reading
					FILE * fp[5];
					char res[1024];
					int res_ctr = 0;
					fp[0] = fopen("sensor1.txt", "r");
					fp[1] = fopen("sensor2.txt", "r");
					fp[2] = fopen("sensor3.txt", "r");
					fp[3] = fopen("sensor4.txt", "r");
					fp[4] = fopen("sensor5.txt", "r");
						
					// Create a string to send
					int i = 0;
					for(i = 0; i < 5; i++){
						char ch;
						while((res[res_ctr++] = fgetc(fp[i])) != EOF);
						res[res_ctr-1] = ',';
						fclose(fp[i]);
					}
					res[res_ctr-1] = '|';
					res[res_ctr++] = '\0';
	
					char prev_edit_s[50]; 
					sprintf(prev_edit_s, "%ld", prev_edit - ); 
					char * resp = strcat(res, prev_edit_s);
				
					// send string
					send(new_socket , resp , strlen(resp) , 0 ); 
					printf("Sent reply %s\n",resp);  
				}
			}
		}
	}
	return 0; 
} 

