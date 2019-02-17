// SERVER

#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

// struct for message queue
struct mesg {
	long mesg_type;
	char mesg_text[2]; // First char will be input, second will be unique ID of client
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
		if(showMsgs)printf("Char Received is : %c \n", m_in.mesg_text[0]);
		if(showMsgs)printf("Char Received from: %d \n", m_in.mesg_text[1]);

		// Do needed changes to message
		if(m_in.mesg_text[0] >= 'a' && m_in.mesg_text[0] <= 'z'){
			m_in.mesg_text[0] = m_in.mesg_text[0] + 'A' - 'a';
		}else if(m_in.mesg_text[0] >= 'A' && m_in.mesg_text[0] <= 'Z'){
			m_in.mesg_text[0] = m_in.mesg_text[0] + 'a' - 'A';
		}
	
		// Send result
		m_in.mesg_type = m_in.mesg_text[1];
		msgsnd(msgid, &m_in, sizeof(m_in), 0);

		gettimeofday(&stop, NULL); // Store time as soon as reply is sent
		if(showMsgs)printf("Replied\n");
		if(doPerf)printf("%lu\n", stop.tv_usec - start.tv_usec);
	
	}

	return 0; 
} 

