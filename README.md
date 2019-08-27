# pThread
- How to create a thread,
- What is the functionality of pthread_join?

## Requirements
- pThread library 
- Ubuntu OS
- gcc

## Compile & Run
- Compile:
    - gcc pThread.c -Wall -o pThread -lpthread
- Run:
    - ./pThread

## Working Principle
When it starts running, 
- 3 threads are be created(started).
- Thread A uses its own function
- Thread B and Thread B AGAIN use the same function.
- pthread_join is used to wait for the thread to finish its job before finishing the program.
- On the stdout, you will see the output messages below: <br />

*****     Posix Thread Discovery     *****
Received Parameter:from Thread_A <br />
Received Parameter:from Thread_B <br />
Received Parameter:from Thread_B AGAIN! <br />
Thread A return Val:1 <br />
Thread B return Val:2 <br />
Thread B (AGAIN) return Val:2 <br />

As seen above, the value of both 'Thread B return Val' and 'Thread B (AGAIN) return Val' are 2. <br />
The thread function of these 2 threads return the value of the variable which is defined as 'static'. <br />
When the Thread_B and Thread_B AGAIN threads are created, the value of this variable will be incremented. <br />






