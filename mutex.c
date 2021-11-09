#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[3];
int tc;
pthread_mutex_t lock;


void* myThread(void *arg);


int main(void)
{
    int i = 0;
    int r;
    tc = 0;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("Cannot initialize mutex");
        return -1;
    }

    for (int i=0;i<3;i++) 
    {
        r = pthread_create(&(tid[i]), NULL, &myThread, NULL);
        if (r != 0)
            printf("Cannot Create Thread");
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    //tc += 1;
    pthread_join(tid[2], NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}

void* myThread(void *arg)
{
    pthread_mutex_lock(&lock);

    unsigned long i = 0;
    tc += 1;
    printf("Operation %d started\n", tc);

    for(i=0; i<5;i++){
        printf("I am performing a critical operation.... \n");
        sleep(1);
    }
    printf("Operation %d is finished.\n", tc);
    pthread_mutex_unlock(&lock);
    return NULL;
}


