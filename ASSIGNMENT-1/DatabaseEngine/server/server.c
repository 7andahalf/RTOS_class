// SERVER

#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <fcntl.h>

// struct for message queue
struct mesg {
	long mesg_type;
	char mesg_text[102]; // First char will be from, second will be a flag, rest 100 is data
};

// Message queue ID
int msgid;

// For Ctrl + C to delete queue and exit
void sig_handler(int signo)
{
	if (signo == SIGINT){
		printf("Exiting");
		msgctl(msgid, IPC_RMID, NULL);
    		exit(0);
	}
}

int main(){

	// Whether to show messages recvd/sent
	int showMsgs = 0;

	// Whether to do performance analysis
	int doPerf = 1;

	// Assign signal catcher
	if (signal(SIGINT, sig_handler) == SIG_ERR)
  		printf("\ncan't catch SIGINT\n");
	
	// Key
	key_t key;
	key = ftok("vinay_imt2015523", 22); 

	// Create queue
	msgid = msgget(key, 0666 | IPC_CREAT);
	
	// Loop for server
	while(1){
		// for performance analysis
		struct timeval stop, start;

		// Recieve request
		struct mesg m_in;
		msgrcv(msgid, &m_in, sizeof(m_in), 1, 0); 
		gettimeofday(&start, NULL); // Store time as soon as message recieved
		if(showMsgs)printf("File request Received is : %s \n", m_in.mesg_text+2);
		if(showMsgs)printf("Req Received from: %d \n", m_in.mesg_text[0]);

		// Send result
		m_in.mesg_type = m_in.mesg_text[0];
		int input_fd = open(m_in.mesg_text+2, O_RDONLY);
		if (input_fd == -1) {
			strcpy(m_in.mesg_text+2, "Data not found");
			m_in.mesg_text[1] = 1;
			msgsnd(msgid, &m_in, sizeof(m_in), 0);
			if(showMsgs)printf("File not found\n");
		}else{
		
			int readBytes = 0;
			int i = 0;
			
			// Send file chunk by chunk
			while((readBytes = read(input_fd, m_in.mesg_text+2, 100)) > 0){
				if(readBytes < 100){ // If file reading is done set flag and send
					m_in.mesg_text[1] = 1;
					for(i = readBytes; i < 100; i++) (m_in.mesg_text+2)[i] = ' '; 
				}
				msgsnd(msgid, &m_in, sizeof(m_in), 0);
			}

			close(input_fd);
		}

		gettimeofday(&stop, NULL); // Store time as soon as reply is sent
		if(showMsgs)printf("Replied\n");
		if(doPerf)printf("%lu\n", stop.tv_usec - start.tv_usec);
	
	}

	return 0; 
} 

