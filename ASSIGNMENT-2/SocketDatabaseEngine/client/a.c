// CLIENT CODE

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 

int main(){
	// Whether to show messages recvd/sent
	int showMsgs = 0;

	// Whether to do performance analysis
	int doPerf = 1;

	struct sockaddr_in address; 
	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) return -1; // Create socket
	memset(&serv_addr, '0', sizeof(serv_addr)); 
	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(6000); // Server port
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) return -1;
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) return -1; // Connect
	
	// Keep sending messages
	while(1){
		// for performance analysis
		struct timeval stop, start;
		
		// Send request
		char *mout = "file2.txt";
		send(sock , mout , strlen(mout) , 0 ); 
		gettimeofday(&start, NULL); // Store time as soon as message sent
		if(showMsgs)printf("File request Sent is : %s \n", mout);

		// Recieve reply
		int output_fd = open(mout, O_WRONLY | O_CREAT, 0644);
		while(1){
			char buff[101] = {0}; 
			valread = read( sock , buff, 101);
			write(output_fd, buff+1, 100);
			if(showMsgs)printf("String Received is : %s \n", buff+1);
			if(buff[0] == 1) break;
		}
		close(output_fd);

		gettimeofday(&stop, NULL); // Store time as soon as reply is recieved
		if(doPerf)printf("%lu\n", stop.tv_usec - start.tv_usec);
	}
	
	return 0; 
} 

