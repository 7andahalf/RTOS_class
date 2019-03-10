// SERVER

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h> 
#include <netinet/in.h> 

int main(){

	// Whether to show messages recvd/sent
	int showMsgs = 0;

	// Whether to do performance analysis
	int doPerf = 1;

	// Start server
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
	
	// Loop for server
	while(1){
		// for performance analysis
		struct timeval stop, start;

		if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))>=0){ // Wait
			if(fork() == 0){
	 			while(1){
					char buffer[10] = {0}; 
					valread = read( new_socket , buffer, 10); 

					gettimeofday(&start, NULL); // Store time as soon as message recieved
					if(showMsgs)printf("Char Received is : %c \n", buffer[0]);

					// Do needed changes to message
					if(buffer[0] >= 'a' && buffer[0] <= 'z'){
						buffer[0] = buffer[0] + 'A' - 'a';
					}else if(buffer[0] >= 'A' && buffer[0] <= 'Z'){
						buffer[0] = buffer[0] + 'a' - 'A';
					}
	
					// Send result
					send(new_socket , buffer , 2 , 0 );

					gettimeofday(&stop, NULL); // Store time as soon as reply is sent
					if(showMsgs)printf("Replied\n");
					if(doPerf)printf("%lu\n", stop.tv_usec - start.tv_usec);
				}
			}	
		}
	}

	return 0; 
} 

