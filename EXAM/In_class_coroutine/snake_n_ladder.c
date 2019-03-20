#include<stdio.h> 
#include<string.h> 
#include<pthread.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<time.h> 
#include <sys/time.h>

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

////////////// HELPERS FOR SNAKE & LADDER
int player_locs[100];
int snakes[10] = {12, 13, 14, 35, 40, 45, 55, 78, 85, 99};
int snake_dest[10] = {1, 2, 3, 14, 4, 6, 20, 30, 50, 60};
int ladder[10] = {5, 10, 15, 20, 25, 36, 41, 50, 80, 90};
int ladder_dest[10] = {11, 19, 30, 31, 41, 51, 60, 60, 99, 95};
int player_win[100];
int wins[100];
int wincnt = 0;

// Rolls a die
int roll_dice(){
	return (rand()%6) + 1;
}

int get_index(int v, int * l, int len){
	int i = 0;
	for(i = 0; i < len; i++){
		if(l[i] == v) return i;	
	}
	return -1;
}

////////////// CO-ROUTINES FOR SNAKE & LADDER
// Plays a round
void* player(void *arg) 
{ 
	int cr_id = thread_count - 1;
	int player_id = cr_id;
	player_locs[player_id] = 0;
	player_win[player_id] = 0;
	
	while(1){
		cr_breakpoint(cr_id);
		printf("Player %d at %d playing a turn\n", cr_id, player_locs[player_id]);
		int die_roll = roll_dice();
		printf("\tPlayer %d rolled a %d\n", cr_id, die_roll);
		player_locs[player_id] += die_roll;

		while(1){
			// exit if no snakes or ladders
			if(get_index(player_locs[player_id], snakes, 10) == -1 && get_index(player_locs[player_id], ladder, 10) == -1){
				break;
			// Check for snake
			}else if(get_index(player_locs[player_id], snakes, 10) != -1){
				int i = get_index(player_locs[player_id], snakes, 10);
				player_locs[player_id] = snake_dest[i];
				printf("\tPlayer %d bit by a snake\n", cr_id);
			// Check for ladder
			}else if(get_index(player_locs[player_id], ladder, 10) != -1){
				int i = get_index(player_locs[player_id], ladder, 10);
				player_locs[player_id] = ladder_dest[i];	
				printf("\tPlayer %d climbed a ladder\n", cr_id);
			}	
		}
		
		// Print location
		printf("\tPlayer %d is at location %d\n", cr_id, player_locs[player_id]);

		// Check for win
		if(player_locs[player_id] >= 100){
			printf("Player %d wins!\n", cr_id);
			wins[wincnt++] = player_id;
			player_win[player_id] = 1;
			while(1){
				cr_breakpoint(cr_id);
			}
		}
	
	}

	return NULL; 
} 

////////////// MAIN

int main(void) 
{ 	
	struct timeval stop, start;

	// Init
	cr_init();
	gettimeofday(&start, NULL);

	// Create some co routines 
	int p1 = cr_create(&player);
	int p2 = cr_create(&player);
	int p3 = cr_create(&player);
	int p4 = cr_create(&player);
	
	// Send some messages to co routines
	while(player_win[p1] == 0 | player_win[p2] == 0 | player_win[p3] == 0 | player_win[p4] == 0){
		//delay(1);
		if(player_win[p1] == 0)cr_send(p1, "Play");
		if(player_win[p2] == 0)cr_send(p2, "Play");
		if(player_win[p3] == 0)cr_send(p3, "Play");
		if(player_win[p4] == 0)cr_send(p4, "Play");
	}

	// Winners
	printf("WINNERS\n");
	printf("\t 1st place : player %d\n", wins[0]);
	printf("\t 2nd place : player %d\n", wins[1]);
	printf("\t 3rd place : player %d\n", wins[2]);
	printf("\t 4th place : player %d\n", wins[3]);

	// Kill the routines
	cr_kill(p1);
	cr_kill(p2);
	cr_kill(p3);
	cr_kill(p4);

	gettimeofday(&stop, NULL);
	printf("Total time taken: %lu\n", stop.tv_usec - start.tv_usec);
		
	return 0; 
} 

