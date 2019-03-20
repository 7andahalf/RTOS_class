# Co-Routines

A Co Routine simulation is implemented in C. A program using Co Routines is simply a program where at a given time only a unique portion of code is being executed, no matter the threads it has.

# Implementation

The co-routine is implemented using Mutex locks, which make sure that only one portion of program is being executed. Provided this guarantee, there is no need to consider race conditions between these portions of code. Hence simple global variables can be used for data transfer.

# Simple co-routine test
The output of the simple co-routine test is expected as follows,
```
print_mesg co-routine #0 recieved message A
print_digit co-routine #4 recieved message 1
print_mesg co-routine #1 recieved message B
print_digit co-routine #3 recieved message 2
print_mesg co-routine #2 recieved message C
print_mesg co-routine #1 recieved message X
print_digit co-routine #3 recieved message 3
print_mesg co-routine #2 recieved message Z
```

# Snake and ladder game
Following is the output of snake and ladder game
```
Player 0 at 0 playing a turn
	Player 0 rolled a 2
	Player 0 is at location 2
Player 1 at 0 playing a turn
	Player 1 rolled a 5
	Player 1 climbed a ladder
	Player 1 is at location 11
Player 2 at 0 playing a turn
	Player 2 rolled a 4
	Player 2 is at location 4
Player 3 at 0 playing a turn
	Player 3 rolled a 2
	Player 3 is at location 2
Player 0 at 2 playing a turn
	Player 0 rolled a 6
	Player 0 is at location 8
Player 1 at 11 playing a turn
	Player 1 rolled a 2
	Player 1 bit by a snake
	Player 1 is at location 2
Player 2 at 4 playing a turn
	Player 2 rolled a 5
	Player 2 is at location 9
Player 3 at 2 playing a turn
	Player 3 rolled a 1
	Player 3 is at location 3
Player 0 at 8 playing a turn
	Player 0 rolled a 4
	Player 0 bit by a snake
	Player 0 is at location 1
Player 1 at 2 playing a turn
	Player 1 rolled a 2
	Player 1 is at location 4
Player 2 at 9 playing a turn
	Player 2 rolled a 3
	Player 2 bit by a snake
	Player 2 is at location 1
Player 3 at 3 playing a turn
	Player 3 rolled a 2
	Player 3 climbed a ladder
	Player 3 is at location 11
Player 0 at 1 playing a turn
	Player 0 rolled a 3
	Player 0 is at location 4
Player 1 at 4 playing a turn
	Player 1 rolled a 2
	Player 1 is at location 6
Player 2 at 1 playing a turn
	Player 2 rolled a 6
	Player 2 is at location 7
Player 3 at 11 playing a turn
	Player 3 rolled a 5
	Player 3 is at location 16
Player 0 at 4 playing a turn
	Player 0 rolled a 1
	Player 0 climbed a ladder
	Player 0 is at location 11
Player 1 at 6 playing a turn
	Player 1 rolled a 1
	Player 1 is at location 7
Player 2 at 7 playing a turn
	Player 2 rolled a 5
	Player 2 bit by a snake
	Player 2 is at location 1
Player 3 at 16 playing a turn
	Player 3 rolled a 5
	Player 3 is at location 21
Player 0 at 11 playing a turn
	Player 0 rolled a 6
	Player 0 is at location 17
Player 1 at 7 playing a turn
	Player 1 rolled a 3
	Player 1 climbed a ladder
	Player 1 is at location 19
Player 2 at 1 playing a turn
	Player 2 rolled a 4
	Player 2 climbed a ladder
	Player 2 is at location 11
Player 3 at 21 playing a turn
	Player 3 rolled a 4
	Player 3 climbed a ladder
	Player 3 climbed a ladder
	Player 3 is at location 60
Player 0 at 17 playing a turn
	Player 0 rolled a 3
	Player 0 climbed a ladder
	Player 0 is at location 31
Player 1 at 19 playing a turn
	Player 1 rolled a 3
	Player 1 is at location 22
Player 2 at 11 playing a turn
	Player 2 rolled a 3
	Player 2 bit by a snake
	Player 2 is at location 3
Player 3 at 60 playing a turn
	Player 3 rolled a 2
	Player 3 is at location 62
Player 0 at 31 playing a turn
	Player 0 rolled a 2
	Player 0 is at location 33
Player 1 at 22 playing a turn
	Player 1 rolled a 2
	Player 1 is at location 24
Player 2 at 3 playing a turn
	Player 2 rolled a 6
	Player 2 is at location 9
Player 3 at 62 playing a turn
	Player 3 rolled a 1
	Player 3 is at location 63
Player 0 at 33 playing a turn
	Player 0 rolled a 1
	Player 0 is at location 34
Player 1 at 24 playing a turn
	Player 1 rolled a 1
	Player 1 climbed a ladder
	Player 1 climbed a ladder
	Player 1 is at location 60
Player 2 at 9 playing a turn
	Player 2 rolled a 6
	Player 2 climbed a ladder
	Player 2 is at location 30
Player 3 at 63 playing a turn
	Player 3 rolled a 4
	Player 3 is at location 67
Player 0 at 34 playing a turn
	Player 0 rolled a 2
	Player 0 climbed a ladder
	Player 0 is at location 51
Player 1 at 60 playing a turn
	Player 1 rolled a 5
	Player 1 is at location 65
Player 2 at 30 playing a turn
	Player 2 rolled a 2
	Player 2 is at location 32
Player 3 at 67 playing a turn
	Player 3 rolled a 5
	Player 3 is at location 72
Player 0 at 51 playing a turn
	Player 0 rolled a 4
	Player 0 bit by a snake
	Player 0 climbed a ladder
	Player 0 is at location 31
Player 1 at 65 playing a turn
	Player 1 rolled a 4
	Player 1 is at location 69
Player 2 at 32 playing a turn
	Player 2 rolled a 4
	Player 2 climbed a ladder
	Player 2 is at location 51
Player 3 at 72 playing a turn
	Player 3 rolled a 6
	Player 3 bit by a snake
	Player 3 is at location 30
Player 0 at 31 playing a turn
	Player 0 rolled a 3
	Player 0 is at location 34
Player 1 at 69 playing a turn
	Player 1 rolled a 2
	Player 1 is at location 71
Player 2 at 51 playing a turn
	Player 2 rolled a 3
	Player 2 is at location 54
Player 3 at 30 playing a turn
	Player 3 rolled a 3
	Player 3 is at location 33
Player 0 at 34 playing a turn
	Player 0 rolled a 6
	Player 0 bit by a snake
	Player 0 is at location 4
Player 1 at 71 playing a turn
	Player 1 rolled a 1
	Player 1 is at location 72
Player 2 at 54 playing a turn
	Player 2 rolled a 6
	Player 2 is at location 60
Player 3 at 33 playing a turn
	Player 3 rolled a 5
	Player 3 is at location 38
Player 0 at 4 playing a turn
	Player 0 rolled a 2
	Player 0 is at location 6
Player 1 at 72 playing a turn
	Player 1 rolled a 3
	Player 1 is at location 75
Player 2 at 60 playing a turn
	Player 2 rolled a 3
	Player 2 is at location 63
Player 3 at 38 playing a turn
	Player 3 rolled a 4
	Player 3 is at location 42
Player 0 at 6 playing a turn
	Player 0 rolled a 3
	Player 0 is at location 9
Player 1 at 75 playing a turn
	Player 1 rolled a 3
	Player 1 bit by a snake
	Player 1 is at location 30
Player 2 at 63 playing a turn
	Player 2 rolled a 5
	Player 2 is at location 68
Player 3 at 42 playing a turn
	Player 3 rolled a 2
	Player 3 is at location 44
Player 0 at 9 playing a turn
	Player 0 rolled a 4
	Player 0 bit by a snake
	Player 0 is at location 2
Player 1 at 30 playing a turn
	Player 1 rolled a 4
	Player 1 is at location 34
Player 2 at 68 playing a turn
	Player 2 rolled a 3
	Player 2 is at location 71
Player 3 at 44 playing a turn
	Player 3 rolled a 4
	Player 3 is at location 48
Player 0 at 2 playing a turn
	Player 0 rolled a 3
	Player 0 climbed a ladder
	Player 0 is at location 11
Player 1 at 34 playing a turn
	Player 1 rolled a 6
	Player 1 bit by a snake
	Player 1 is at location 4
Player 2 at 71 playing a turn
	Player 2 rolled a 5
	Player 2 is at location 76
Player 3 at 48 playing a turn
	Player 3 rolled a 4
	Player 3 is at location 52
Player 0 at 11 playing a turn
	Player 0 rolled a 2
	Player 0 bit by a snake
	Player 0 is at location 2
Player 1 at 4 playing a turn
	Player 1 rolled a 6
	Player 1 climbed a ladder
	Player 1 is at location 19
Player 2 at 76 playing a turn
	Player 2 rolled a 1
	Player 2 is at location 77
Player 3 at 52 playing a turn
	Player 3 rolled a 4
	Player 3 is at location 56
Player 0 at 2 playing a turn
	Player 0 rolled a 1
	Player 0 is at location 3
Player 1 at 19 playing a turn
	Player 1 rolled a 4
	Player 1 is at location 23
Player 2 at 77 playing a turn
	Player 2 rolled a 3
	Player 2 climbed a ladder
	Player 2 bit by a snake
	Player 2 is at location 60
Player 3 at 56 playing a turn
	Player 3 rolled a 4
	Player 3 is at location 60
Player 0 at 3 playing a turn
	Player 0 rolled a 3
	Player 0 is at location 6
Player 1 at 23 playing a turn
	Player 1 rolled a 3
	Player 1 is at location 26
Player 2 at 60 playing a turn
	Player 2 rolled a 4
	Player 2 is at location 64
Player 3 at 60 playing a turn
	Player 3 rolled a 3
	Player 3 is at location 63
Player 0 at 6 playing a turn
	Player 0 rolled a 2
	Player 0 is at location 8
Player 1 at 26 playing a turn
	Player 1 rolled a 1
	Player 1 is at location 27
Player 2 at 64 playing a turn
	Player 2 rolled a 1
	Player 2 is at location 65
Player 3 at 63 playing a turn
	Player 3 rolled a 3
	Player 3 is at location 66
Player 0 at 8 playing a turn
	Player 0 rolled a 3
	Player 0 is at location 11
Player 1 at 27 playing a turn
	Player 1 rolled a 1
	Player 1 is at location 28
Player 2 at 65 playing a turn
	Player 2 rolled a 4
	Player 2 is at location 69
Player 3 at 66 playing a turn
	Player 3 rolled a 6
	Player 3 is at location 72
Player 0 at 11 playing a turn
	Player 0 rolled a 3
	Player 0 bit by a snake
	Player 0 is at location 3
Player 1 at 28 playing a turn
	Player 1 rolled a 2
	Player 1 is at location 30
Player 2 at 69 playing a turn
	Player 2 rolled a 1
	Player 2 is at location 70
Player 3 at 72 playing a turn
	Player 3 rolled a 1
	Player 3 is at location 73
Player 0 at 3 playing a turn
	Player 0 rolled a 3
	Player 0 is at location 6
Player 1 at 30 playing a turn
	Player 1 rolled a 1
	Player 1 is at location 31
Player 2 at 70 playing a turn
	Player 2 rolled a 2
	Player 2 is at location 72
Player 3 at 73 playing a turn
	Player 3 rolled a 5
	Player 3 bit by a snake
	Player 3 is at location 30
Player 0 at 6 playing a turn
	Player 0 rolled a 5
	Player 0 is at location 11
Player 1 at 31 playing a turn
	Player 1 rolled a 1
	Player 1 is at location 32
Player 2 at 72 playing a turn
	Player 2 rolled a 1
	Player 2 is at location 73
Player 3 at 30 playing a turn
	Player 3 rolled a 6
	Player 3 climbed a ladder
	Player 3 is at location 51
Player 0 at 11 playing a turn
	Player 0 rolled a 4
	Player 0 climbed a ladder
	Player 0 is at location 30
Player 1 at 32 playing a turn
	Player 1 rolled a 5
	Player 1 is at location 37
Player 2 at 73 playing a turn
	Player 2 rolled a 3
	Player 2 is at location 76
Player 3 at 51 playing a turn
	Player 3 rolled a 5
	Player 3 is at location 56
Player 0 at 30 playing a turn
	Player 0 rolled a 6
	Player 0 climbed a ladder
	Player 0 is at location 51
Player 1 at 37 playing a turn
	Player 1 rolled a 4
	Player 1 climbed a ladder
	Player 1 is at location 60
Player 2 at 76 playing a turn
	Player 2 rolled a 6
	Player 2 is at location 82
Player 3 at 56 playing a turn
	Player 3 rolled a 3
	Player 3 is at location 59
Player 0 at 51 playing a turn
	Player 0 rolled a 4
	Player 0 bit by a snake
	Player 0 climbed a ladder
	Player 0 is at location 31
Player 1 at 60 playing a turn
	Player 1 rolled a 1
	Player 1 is at location 61
Player 2 at 82 playing a turn
	Player 2 rolled a 5
	Player 2 is at location 87
Player 3 at 59 playing a turn
	Player 3 rolled a 3
	Player 3 is at location 62
Player 0 at 31 playing a turn
	Player 0 rolled a 2
	Player 0 is at location 33
Player 1 at 61 playing a turn
	Player 1 rolled a 3
	Player 1 is at location 64
Player 2 at 87 playing a turn
	Player 2 rolled a 3
	Player 2 climbed a ladder
	Player 2 is at location 95
Player 3 at 62 playing a turn
	Player 3 rolled a 2
	Player 3 is at location 64
Player 0 at 33 playing a turn
	Player 0 rolled a 4
	Player 0 is at location 37
Player 1 at 64 playing a turn
	Player 1 rolled a 6
	Player 1 is at location 70
Player 2 at 95 playing a turn
	Player 2 rolled a 5
	Player 2 is at location 100
Player 2 wins!
Player 3 at 64 playing a turn
	Player 3 rolled a 6
	Player 3 is at location 70
Player 0 at 37 playing a turn
	Player 0 rolled a 5
	Player 0 is at location 42
Player 1 at 70 playing a turn
	Player 1 rolled a 4
	Player 1 is at location 74
Player 3 at 70 playing a turn
	Player 3 rolled a 4
	Player 3 is at location 74
Player 0 at 42 playing a turn
	Player 0 rolled a 2
	Player 0 is at location 44
Player 1 at 74 playing a turn
	Player 1 rolled a 4
	Player 1 bit by a snake
	Player 1 is at location 30
Player 3 at 74 playing a turn
	Player 3 rolled a 6
	Player 3 climbed a ladder
	Player 3 bit by a snake
	Player 3 is at location 60
Player 0 at 44 playing a turn
	Player 0 rolled a 4
	Player 0 is at location 48
Player 1 at 30 playing a turn
	Player 1 rolled a 6
	Player 1 climbed a ladder
	Player 1 is at location 51
Player 3 at 60 playing a turn
	Player 3 rolled a 4
	Player 3 is at location 64
Player 0 at 48 playing a turn
	Player 0 rolled a 2
	Player 0 climbed a ladder
	Player 0 is at location 60
Player 1 at 51 playing a turn
	Player 1 rolled a 4
	Player 1 bit by a snake
	Player 1 climbed a ladder
	Player 1 is at location 31
Player 3 at 64 playing a turn
	Player 3 rolled a 5
	Player 3 is at location 69
Player 0 at 60 playing a turn
	Player 0 rolled a 6
	Player 0 is at location 66
Player 1 at 31 playing a turn
	Player 1 rolled a 4
	Player 1 bit by a snake
	Player 1 bit by a snake
	Player 1 is at location 3
Player 3 at 69 playing a turn
	Player 3 rolled a 1
	Player 3 is at location 70
Player 0 at 66 playing a turn
	Player 0 rolled a 6
	Player 0 is at location 72
Player 1 at 3 playing a turn
	Player 1 rolled a 5
	Player 1 is at location 8
Player 3 at 70 playing a turn
	Player 3 rolled a 6
	Player 3 is at location 76
Player 0 at 72 playing a turn
	Player 0 rolled a 6
	Player 0 bit by a snake
	Player 0 is at location 30
Player 1 at 8 playing a turn
	Player 1 rolled a 3
	Player 1 is at location 11
Player 3 at 76 playing a turn
	Player 3 rolled a 5
	Player 3 is at location 81
Player 0 at 30 playing a turn
	Player 0 rolled a 4
	Player 0 is at location 34
Player 1 at 11 playing a turn
	Player 1 rolled a 3
	Player 1 bit by a snake
	Player 1 is at location 3
Player 3 at 81 playing a turn
	Player 3 rolled a 6
	Player 3 is at location 87
Player 0 at 34 playing a turn
	Player 0 rolled a 4
	Player 0 is at location 38
Player 1 at 3 playing a turn
	Player 1 rolled a 6
	Player 1 is at location 9
Player 3 at 87 playing a turn
	Player 3 rolled a 1
	Player 3 is at location 88
Player 0 at 38 playing a turn
	Player 0 rolled a 1
	Player 0 is at location 39
Player 1 at 9 playing a turn
	Player 1 rolled a 5
	Player 1 bit by a snake
	Player 1 is at location 3
Player 3 at 88 playing a turn
	Player 3 rolled a 6
	Player 3 is at location 94
Player 0 at 39 playing a turn
	Player 0 rolled a 5
	Player 0 is at location 44
Player 1 at 3 playing a turn
	Player 1 rolled a 4
	Player 1 is at location 7
Player 3 at 94 playing a turn
	Player 3 rolled a 1
	Player 3 is at location 95
Player 0 at 44 playing a turn
	Player 0 rolled a 6
	Player 0 climbed a ladder
	Player 0 is at location 60
Player 1 at 7 playing a turn
	Player 1 rolled a 3
	Player 1 climbed a ladder
	Player 1 is at location 19
Player 3 at 95 playing a turn
	Player 3 rolled a 2
	Player 3 is at location 97
Player 0 at 60 playing a turn
	Player 0 rolled a 3
	Player 0 is at location 63
Player 1 at 19 playing a turn
	Player 1 rolled a 4
	Player 1 is at location 23
Player 3 at 97 playing a turn
	Player 3 rolled a 2
	Player 3 bit by a snake
	Player 3 is at location 60
Player 0 at 63 playing a turn
	Player 0 rolled a 6
	Player 0 is at location 69
Player 1 at 23 playing a turn
	Player 1 rolled a 6
	Player 1 is at location 29
Player 3 at 60 playing a turn
	Player 3 rolled a 5
	Player 3 is at location 65
Player 0 at 69 playing a turn
	Player 0 rolled a 3
	Player 0 is at location 72
Player 1 at 29 playing a turn
	Player 1 rolled a 3
	Player 1 is at location 32
Player 3 at 65 playing a turn
	Player 3 rolled a 2
	Player 3 is at location 67
Player 0 at 72 playing a turn
	Player 0 rolled a 3
	Player 0 is at location 75
Player 1 at 32 playing a turn
	Player 1 rolled a 2
	Player 1 is at location 34
Player 3 at 67 playing a turn
	Player 3 rolled a 5
	Player 3 is at location 72
Player 0 at 75 playing a turn
	Player 0 rolled a 3
	Player 0 bit by a snake
	Player 0 is at location 30
Player 1 at 34 playing a turn
	Player 1 rolled a 5
	Player 1 is at location 39
Player 3 at 72 playing a turn
	Player 3 rolled a 1
	Player 3 is at location 73
Player 0 at 30 playing a turn
	Player 0 rolled a 5
	Player 0 bit by a snake
	Player 0 bit by a snake
	Player 0 is at location 3
Player 1 at 39 playing a turn
	Player 1 rolled a 6
	Player 1 bit by a snake
	Player 1 is at location 6
Player 3 at 73 playing a turn
	Player 3 rolled a 3
	Player 3 is at location 76
Player 0 at 3 playing a turn
	Player 0 rolled a 4
	Player 0 is at location 7
Player 1 at 6 playing a turn
	Player 1 rolled a 4
	Player 1 climbed a ladder
	Player 1 is at location 19
Player 3 at 76 playing a turn
	Player 3 rolled a 6
	Player 3 is at location 82
Player 0 at 7 playing a turn
	Player 0 rolled a 2
	Player 0 is at location 9
Player 1 at 19 playing a turn
	Player 1 rolled a 4
	Player 1 is at location 23
Player 3 at 82 playing a turn
	Player 3 rolled a 5
	Player 3 is at location 87
Player 0 at 9 playing a turn
	Player 0 rolled a 5
	Player 0 bit by a snake
	Player 0 is at location 3
Player 1 at 23 playing a turn
	Player 1 rolled a 6
	Player 1 is at location 29
Player 3 at 87 playing a turn
	Player 3 rolled a 6
	Player 3 is at location 93
Player 0 at 3 playing a turn
	Player 0 rolled a 5
	Player 0 is at location 8
Player 1 at 29 playing a turn
	Player 1 rolled a 6
	Player 1 bit by a snake
	Player 1 bit by a snake
	Player 1 is at location 3
Player 3 at 93 playing a turn
	Player 3 rolled a 6
	Player 3 bit by a snake
	Player 3 is at location 60
Player 0 at 8 playing a turn
	Player 0 rolled a 1
	Player 0 is at location 9
Player 1 at 3 playing a turn
	Player 1 rolled a 2
	Player 1 climbed a ladder
	Player 1 is at location 11
Player 3 at 60 playing a turn
	Player 3 rolled a 3
	Player 3 is at location 63
Player 0 at 9 playing a turn
	Player 0 rolled a 2
	Player 0 is at location 11
Player 1 at 11 playing a turn
	Player 1 rolled a 6
	Player 1 is at location 17
Player 3 at 63 playing a turn
	Player 3 rolled a 2
	Player 3 is at location 65
Player 0 at 11 playing a turn
	Player 0 rolled a 4
	Player 0 climbed a ladder
	Player 0 is at location 30
Player 1 at 17 playing a turn
	Player 1 rolled a 2
	Player 1 is at location 19
Player 3 at 65 playing a turn
	Player 3 rolled a 3
	Player 3 is at location 68
Player 0 at 30 playing a turn
	Player 0 rolled a 3
	Player 0 is at location 33
Player 1 at 19 playing a turn
	Player 1 rolled a 4
	Player 1 is at location 23
Player 3 at 68 playing a turn
	Player 3 rolled a 4
	Player 3 is at location 72
Player 0 at 33 playing a turn
	Player 0 rolled a 1
	Player 0 is at location 34
Player 1 at 23 playing a turn
	Player 1 rolled a 4
	Player 1 is at location 27
Player 3 at 72 playing a turn
	Player 3 rolled a 3
	Player 3 is at location 75
Player 0 at 34 playing a turn
	Player 0 rolled a 5
	Player 0 is at location 39
Player 1 at 27 playing a turn
	Player 1 rolled a 2
	Player 1 is at location 29
Player 3 at 75 playing a turn
	Player 3 rolled a 2
	Player 3 is at location 77
Player 0 at 39 playing a turn
	Player 0 rolled a 6
	Player 0 bit by a snake
	Player 0 is at location 6
Player 1 at 29 playing a turn
	Player 1 rolled a 3
	Player 1 is at location 32
Player 3 at 77 playing a turn
	Player 3 rolled a 3
	Player 3 climbed a ladder
	Player 3 bit by a snake
	Player 3 is at location 60
Player 0 at 6 playing a turn
	Player 0 rolled a 5
	Player 0 is at location 11
Player 1 at 32 playing a turn
	Player 1 rolled a 5
	Player 1 is at location 37
Player 3 at 60 playing a turn
	Player 3 rolled a 5
	Player 3 is at location 65
Player 0 at 11 playing a turn
	Player 0 rolled a 1
	Player 0 bit by a snake
	Player 0 is at location 1
Player 1 at 37 playing a turn
	Player 1 rolled a 1
	Player 1 is at location 38
Player 3 at 65 playing a turn
	Player 3 rolled a 4
	Player 3 is at location 69
Player 0 at 1 playing a turn
	Player 0 rolled a 4
	Player 0 climbed a ladder
	Player 0 is at location 11
Player 1 at 38 playing a turn
	Player 1 rolled a 6
	Player 1 is at location 44
Player 3 at 69 playing a turn
	Player 3 rolled a 1
	Player 3 is at location 70
Player 0 at 11 playing a turn
	Player 0 rolled a 3
	Player 0 bit by a snake
	Player 0 is at location 3
Player 1 at 44 playing a turn
	Player 1 rolled a 4
	Player 1 is at location 48
Player 3 at 70 playing a turn
	Player 3 rolled a 1
	Player 3 is at location 71
Player 0 at 3 playing a turn
	Player 0 rolled a 6
	Player 0 is at location 9
Player 1 at 48 playing a turn
	Player 1 rolled a 3
	Player 1 is at location 51
Player 3 at 71 playing a turn
	Player 3 rolled a 6
	Player 3 is at location 77
Player 0 at 9 playing a turn
	Player 0 rolled a 5
	Player 0 bit by a snake
	Player 0 is at location 3
Player 1 at 51 playing a turn
	Player 1 rolled a 6
	Player 1 is at location 57
Player 3 at 77 playing a turn
	Player 3 rolled a 5
	Player 3 is at location 82
Player 0 at 3 playing a turn
	Player 0 rolled a 1
	Player 0 is at location 4
Player 1 at 57 playing a turn
	Player 1 rolled a 6
	Player 1 is at location 63
Player 3 at 82 playing a turn
	Player 3 rolled a 6
	Player 3 is at location 88
Player 0 at 4 playing a turn
	Player 0 rolled a 3
	Player 0 is at location 7
Player 1 at 63 playing a turn
	Player 1 rolled a 5
	Player 1 is at location 68
Player 3 at 88 playing a turn
	Player 3 rolled a 4
	Player 3 is at location 92
Player 0 at 7 playing a turn
	Player 0 rolled a 3
	Player 0 climbed a ladder
	Player 0 is at location 19
Player 1 at 68 playing a turn
	Player 1 rolled a 1
	Player 1 is at location 69
Player 3 at 92 playing a turn
	Player 3 rolled a 3
	Player 3 is at location 95
Player 0 at 19 playing a turn
	Player 0 rolled a 2
	Player 0 is at location 21
Player 1 at 69 playing a turn
	Player 1 rolled a 4
	Player 1 is at location 73
Player 3 at 95 playing a turn
	Player 3 rolled a 4
	Player 3 bit by a snake
	Player 3 is at location 60
Player 0 at 21 playing a turn
	Player 0 rolled a 5
	Player 0 is at location 26
Player 1 at 73 playing a turn
	Player 1 rolled a 3
	Player 1 is at location 76
Player 3 at 60 playing a turn
	Player 3 rolled a 6
	Player 3 is at location 66
Player 0 at 26 playing a turn
	Player 0 rolled a 3
	Player 0 is at location 29
Player 1 at 76 playing a turn
	Player 1 rolled a 1
	Player 1 is at location 77
Player 3 at 66 playing a turn
	Player 3 rolled a 6
	Player 3 is at location 72
Player 0 at 29 playing a turn
	Player 0 rolled a 4
	Player 0 is at location 33
Player 1 at 77 playing a turn
	Player 1 rolled a 5
	Player 1 is at location 82
Player 3 at 72 playing a turn
	Player 3 rolled a 3
	Player 3 is at location 75
Player 0 at 33 playing a turn
	Player 0 rolled a 5
	Player 0 is at location 38
Player 1 at 82 playing a turn
	Player 1 rolled a 5
	Player 1 is at location 87
Player 3 at 75 playing a turn
	Player 3 rolled a 6
	Player 3 is at location 81
Player 0 at 38 playing a turn
	Player 0 rolled a 5
	Player 0 is at location 43
Player 1 at 87 playing a turn
	Player 1 rolled a 4
	Player 1 is at location 91
Player 3 at 81 playing a turn
	Player 3 rolled a 2
	Player 3 is at location 83
Player 0 at 43 playing a turn
	Player 0 rolled a 2
	Player 0 bit by a snake
	Player 0 is at location 6
Player 1 at 91 playing a turn
	Player 1 rolled a 1
	Player 1 is at location 92
Player 3 at 83 playing a turn
	Player 3 rolled a 5
	Player 3 is at location 88
Player 0 at 6 playing a turn
	Player 0 rolled a 6
	Player 0 bit by a snake
	Player 0 is at location 1
Player 1 at 92 playing a turn
	Player 1 rolled a 1
	Player 1 is at location 93
Player 3 at 88 playing a turn
	Player 3 rolled a 3
	Player 3 is at location 91
Player 0 at 1 playing a turn
	Player 0 rolled a 5
	Player 0 is at location 6
Player 1 at 93 playing a turn
	Player 1 rolled a 1
	Player 1 is at location 94
Player 3 at 91 playing a turn
	Player 3 rolled a 1
	Player 3 is at location 92
Player 0 at 6 playing a turn
	Player 0 rolled a 6
	Player 0 bit by a snake
	Player 0 is at location 1
Player 1 at 94 playing a turn
	Player 1 rolled a 3
	Player 1 is at location 97
Player 3 at 92 playing a turn
	Player 3 rolled a 5
	Player 3 is at location 97
Player 0 at 1 playing a turn
	Player 0 rolled a 1
	Player 0 is at location 2
Player 1 at 97 playing a turn
	Player 1 rolled a 3
	Player 1 is at location 100
Player 1 wins!
Player 3 at 97 playing a turn
	Player 3 rolled a 3
	Player 3 is at location 100
Player 3 wins!
Player 0 at 2 playing a turn
	Player 0 rolled a 4
	Player 0 is at location 6
Player 0 at 6 playing a turn
	Player 0 rolled a 1
	Player 0 is at location 7
Player 0 at 7 playing a turn
	Player 0 rolled a 3
	Player 0 climbed a ladder
	Player 0 is at location 19
Player 0 at 19 playing a turn
	Player 0 rolled a 1
	Player 0 climbed a ladder
	Player 0 is at location 31
Player 0 at 31 playing a turn
	Player 0 rolled a 1
	Player 0 is at location 32
Player 0 at 32 playing a turn
	Player 0 rolled a 3
	Player 0 bit by a snake
	Player 0 bit by a snake
	Player 0 is at location 3
Player 0 at 3 playing a turn
	Player 0 rolled a 6
	Player 0 is at location 9
Player 0 at 9 playing a turn
	Player 0 rolled a 4
	Player 0 bit by a snake
	Player 0 is at location 2
Player 0 at 2 playing a turn
	Player 0 rolled a 5
	Player 0 is at location 7
Player 0 at 7 playing a turn
	Player 0 rolled a 3
	Player 0 climbed a ladder
	Player 0 is at location 19
Player 0 at 19 playing a turn
	Player 0 rolled a 6
	Player 0 climbed a ladder
	Player 0 climbed a ladder
	Player 0 is at location 60
Player 0 at 60 playing a turn
	Player 0 rolled a 4
	Player 0 is at location 64
Player 0 at 64 playing a turn
	Player 0 rolled a 6
	Player 0 is at location 70
Player 0 at 70 playing a turn
	Player 0 rolled a 4
	Player 0 is at location 74
Player 0 at 74 playing a turn
	Player 0 rolled a 5
	Player 0 is at location 79
Player 0 at 79 playing a turn
	Player 0 rolled a 2
	Player 0 is at location 81
Player 0 at 81 playing a turn
	Player 0 rolled a 3
	Player 0 is at location 84
Player 0 at 84 playing a turn
	Player 0 rolled a 5
	Player 0 is at location 89
Player 0 at 89 playing a turn
	Player 0 rolled a 4
	Player 0 is at location 93
Player 0 at 93 playing a turn
	Player 0 rolled a 2
	Player 0 is at location 95
Player 0 at 95 playing a turn
	Player 0 rolled a 6
	Player 0 is at location 101
Player 0 wins!
WINNERS
	 1st place : player 2
	 2nd place : player 1
	 3rd place : player 3
	 4th place : player 0
Total time taken: 39829
```

# Performance

The snake and ladder game was run several times to get the running time, following are the results

| # Run | Time taken (uS)
|-----------|---------|
| 1         |  36040  |
| 2         |   31813 |
| 3         |  38615  |
| 4         |   30303 |
| 5         |  30652  |
