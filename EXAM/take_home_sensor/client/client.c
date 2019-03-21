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

// Delay in mili seconds
void delay(int number_of_mili_seconds) 
{ 
    long int milli_seconds = 1000 * number_of_mili_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
} 

// Main
int main(int argc, char const *argv[]) 
{ 
	// Create socket
	struct sockaddr_in address; 
	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) return -1; // Create socket
	memset(&serv_addr, '0', sizeof(serv_addr)); 
	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(6000); // Server port
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) return -1;
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) return -1; // Connect
	
	// Last read time
	int last_read = 10000;

	// Run forever
	while(1){
		// Request for reading
		delay(100);
		char *hell = "GET"; 
		send(sock , hell , strlen(hell) , 0 ); 
		char buff[1024] = {0}; 
		valread = read( sock , buff, 1024); 

		// last edit part
		char dat_e[1024];
		int buff_cnt = 0;
		int dat_e_cnt = 0;
		
		// data part
		char dat_p[1024];
		int dat_p_cnt = 0;
		dat_p[dat_p_cnt++]=',';
		while(buff[buff_cnt++] != '|') dat_p[dat_p_cnt++] = buff[buff_cnt-1];
		dat_p[dat_p_cnt++]='\n';
		dat_p[dat_p_cnt++]='\0';
		while(buff[buff_cnt++] != '\0') dat_e[dat_e_cnt++] = buff[buff_cnt-1];
		dat_e[dat_e_cnt] = '\0';
		int lst = atoi(dat_e);

		// If current version of reading is new, write it to file
		if(lst < last_read){
			struct timeval stop;
			gettimeofday(&stop, NULL);
			long int timestamp = stop.tv_sec*1000 + (stop.tv_usec - (lst*1000))/1000;
			char timenow_s[50]; 
			sprintf(timenow_s, "%ld", timestamp); 
			char * to_file = strcat(timenow_s, dat_p);

			FILE * fptr = fopen("data.csv", "a");
			fprintf(fptr,"%s", to_file);
   			fclose(fptr);
			printf("%ld : %s : %d\n",timestamp, buff, lst);
		}
		last_read = lst;
	}
	return 0; 
} 

