// CLIENT CODE

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/time.h>

// struct for message queue
struct mesg {
	long mesg_type;
	char mesg_text[2]; // First char will be input, second will be unique ID of client
};

int main(){
	// unique ID for each client
	int uid = 5;
	
	// Whether to show messages recvd/sent
	int showMsgs = 0;

	// Whether to do performance analysis
	int doPerf = 1;

	// Key
	key_t key;
	key = ftok("vinay_imt2015523", 22);

	// Create message queue
	int msgid; 
	msgid = msgget(key, 0666 | IPC_CREAT);
	
	// Keep sending messages
	while(1){
		// for performance analysis
		struct timeval stop, start;
		
		// Send request
		struct mesg m_out;
		m_out.mesg_type = 1;
		m_out.mesg_text[0] = '$';
		m_out.mesg_text[1] = uid;
		msgsnd(msgid, &m_out, sizeof(m_out), 0);
		gettimeofday(&start, NULL); // Store time as soon as message sent
		if(showMsgs)printf("Char Sent is : %c \n", m_out.mesg_text[0]);

		// Recieve reply
		struct mesg m_in;
		msgrcv(msgid, &m_in, sizeof(m_in), uid, 0);
		gettimeofday(&stop, NULL); // Store time as soon as reply is recieved
		if(showMsgs)printf("Char Received is : %c \n", m_in.mesg_text[0]);
		if(doPerf)printf("%lu\n", stop.tv_usec - start.tv_usec);
	}
	
	return 0; 
} 

