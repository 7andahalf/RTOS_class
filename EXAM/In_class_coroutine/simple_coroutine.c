#include<stdio.h> 
#include<string.h> 
#include<pthread.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<time.h> 

////////////// UTILITY FUNCTIONS

// Delay in seconds
void delay(int number_of_seconds) 
{ 
    long int milli_seconds = 1000000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
} 

////////////// CO-ROUTINE FUNCTIONS

// Variables
#define MAXCOROUTINES 100
pthread_t thread_id[MAXCOROUTINES]; 
long int thread_count = 0;
pthread_mutex_t thread_locks[MAXCOROUTINES]; 
pthread_mutex_t main_lock;
char mesg[100] = "\0";

// Init all variables
void cr_init(){
	
	int i = 0; 
	for(i = 0; i < 100; i++){
		pthread_mutex_init(&(thread_locks[i]), NULL);
		pthread_mutex_lock(&(thread_locks[i]));
	}

	pthread_mutex_lock(&main_lock);
}

// Create a co-routine by passing function pointer
int cr_create(void *(*f)(void *)){
	pthread_create(&(thread_id[thread_count++]), NULL, f, NULL);
	pthread_mutex_lock(&main_lock);
	return thread_count - 1;
}

// Send data to a co routine and continue execution
void cr_send(int cr_id, char * msg){
	strcpy(mesg, msg);
	pthread_mutex_unlock(&(thread_locks[cr_id]));
	pthread_mutex_lock(&main_lock);
}

// Breakpoints within functions
void cr_breakpoint(int cr_id){
	pthread_mutex_unlock(&main_lock);
	pthread_mutex_lock(&(thread_locks[cr_id]));
}

// Kill a co routine
void cr_kill(int cr_id){
	pthread_cancel(thread_id[cr_id]);
	pthread_mutex_destroy(&(thread_locks[cr_id])); 
}

////////////// CO-ROUTINES
void* print_mesg(void *arg) 
{ 
	int cr_id = thread_count - 1;
	
	while(1){
		cr_breakpoint(cr_id);
		printf("print_mesg co-routine #%d recieved message %s\n", cr_id, mesg);  
	}

	return NULL; 
} 

void* print_digit(void *arg) 
{ 
	int cr_id = thread_count - 1;
	
	while(1){
		cr_breakpoint(cr_id);
		printf("print_digit co-routine #%d recieved message %s\n", cr_id, mesg);  
	}

	return NULL; 
} 


////////////// MAIN

int main(void) 
{ 	
	// Init
	cr_init();

	// Create some co routines 
	int cr1 = cr_create(&print_mesg);
	int cr2 = cr_create(&print_mesg);
	int cr3 = cr_create(&print_mesg);
	int cr4 = cr_create(&print_digit);
	int cr5 = cr_create(&print_digit);
	
	// Send some messages to co routines
	cr_send(cr1, "A");
	cr_send(cr5, "1");
	cr_send(cr2, "B");
	cr_send(cr4, "2");
	cr_send(cr3, "C");
	cr_send(cr2, "X");
	cr_send(cr4, "3");
	cr_send(cr3, "Z");

	// Kill the routines
	cr_kill(cr1);
	cr_kill(cr2);
	cr_kill(cr3);
	cr_kill(cr4);
	cr_kill(cr5);
		
	return 0; 
} 

