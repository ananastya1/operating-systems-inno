#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define N 5

typedef struct thread
{
    pthread_t thread_id;
    int thread_num;
    char message[256];
} Thread;

void *thread_start(void *thread)
{
    Thread *my_data = (Thread *)thread;
    int order = my_data->thread_num;
    printf("%li %s\n", my_data->thread_id, my_data->message);
    return NULL;
}

int main(int argc, char *argv[])
{
    int i;
    Thread thread[N];
    for (i = 0; i < N; i++)
    {
        thread[i].thread_num = i;
        strcpy(thread[i].message, "Hello from thread ");
        char *temp = (char *)malloc(8);
        sprintf(temp, "%d", i);
        strcpy(thread[i].message, strcat(thread[i].message, temp));
        pthread_create(&(thread[i].thread_id), NULL, thread_start, (void *)(thread + i));
        printf("Thread %i is created\n", thread[i].thread_num);
        pthread_join(thread[i].thread_id, NULL);
    }

    return 0;
}