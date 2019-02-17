// CLIENT CODE

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <fcntl.h>

// struct for message queue
struct mesg {
	long mesg_type;
	char mesg_text[102]; // First char will be from, second will be a flag, rest 100 is data
};

int main(){
	// unique ID for each client
	int uid = 4;
	
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
		m_out.mesg_text[0] = uid;
		m_out.mesg_text[1] = 0;
		strcpy(m_out.mesg_text+2, "file1.txt");
		msgsnd(msgid, &m_out, sizeof(m_out), 0);
		gettimeofday(&start, NULL); // Store time as soon as message sent
		if(showMsgs)printf("File request Sent is : %s \n", m_out.mesg_text+2);

		// Recieve reply
		int output_fd = open(m_out.mesg_text+2, O_WRONLY | O_CREAT, 0644);
		while(1){
			struct mesg m_in;
			msgrcv(msgid, &m_in, sizeof(m_in), uid, 0);
			write(output_fd, m_in.mesg_text+2, 100);
			if(showMsgs)printf("String Received is : %s \n", m_in.mesg_text+2);
			if(m_in.mesg_text[1] == 1) break;
		}
		close(output_fd);

		gettimeofday(&stop, NULL); // Store time as soon as reply is recieved
		if(doPerf)printf("%lu\n", stop.tv_usec - start.tv_usec);
	}
	
	return 0; 
} 

