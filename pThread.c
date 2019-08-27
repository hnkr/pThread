#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *dummy_thread_function_A(void *ptrVarToWrite)
{
    static int i = 0;
    printf("Received Parameter:%s\r\n", (char *)ptrVarToWrite);
    i++;
    sleep(1);
    pthread_exit((void *)&i);
}

void *dummy_thread_function_B(void *ptrVarToWrite)
{
    static int i = 0;
    printf("Received Parameter:%s\r\n", (char *)ptrVarToWrite);
    i++;
    sleep(1);
    pthread_exit((void *)&i);
}


int main(void)
{
    pthread_t thread_A, thread_B, thread_B_again;
    void *ptrThread_A_RetVal, *ptrThread_B_RetVal;
    printf("\r\n*****     Posix Thread Discovery     *****\r\n");
    if(0 != pthread_create(&thread_A, NULL, dummy_thread_function_A, "from Thread_A")){
        printf("Thread_A can not be created!\r\n");
        return EXIT_FAILURE;
    }
    if(0 != pthread_create(&thread_B, NULL, dummy_thread_function_B, "from Thread_B")){
        printf("Thread_B can not be created!\r\n");
        return EXIT_FAILURE;
    }
    if(0 != pthread_create(&thread_B_again, NULL, dummy_thread_function_B, "from Thread_B AGAIN!")){
        printf("Thread_B (AGAIN) can not be created!\r\n");
        return EXIT_FAILURE;
    }
    pthread_join(thread_A, &ptrThread_A_RetVal); //wait until thread_A terminates / cancels or returns. The return value will be stored in ptrThread_A_RetVal.
    printf("Thread A return Val:%d\r\n", *(int *)ptrThread_A_RetVal);
    pthread_join(thread_B, &ptrThread_B_RetVal); //wait until thread_B terminates / cancels or returns. The return value will be stored in ptrThread_B_RetVal.
    printf("Thread B return Val:%d\r\n", *(int *)ptrThread_B_RetVal);
    pthread_join(thread_B_again, &ptrThread_B_RetVal); //wait until thread_B terminates / cancels or returns. The return value will be stored in ptrThread_B_RetVal.
    printf("Thread B (AGAIN) return Val:%d\r\n", *(int *)ptrThread_B_RetVal);

    return EXIT_SUCCESS;
}