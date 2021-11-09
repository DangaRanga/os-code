#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

sem_t s; 
void* sThread(void* arg);
int tc;

int main() 
{ 
	//initialize semaphore at address pointed to by s
	// 1 in this case is the initial value for the semaphore
	// 0 means that the semaphore is shared between threads of a process
	sem_init(&s, 0, 1); 
	pthread_t tid1,tid2; 

	pthread_create(&tid1,NULL,sThread,NULL); 
	pthread_create(&tid2,NULL,sThread,NULL); 
	pthread_join(tid1,NULL); 
	pthread_join(tid2,NULL); 
    //destroys the semaphore at the address sq
	sem_destroy(&s); 
	return 0; 
}

void* sThread(void* arg) 
{ 
    unsigned long i = 0; 
    tc += 1;
    //decrement if greater than zero else block
	sem_wait(&s); 
	printf("Operation %d started...\n", tc); 

    for(i=0; i<5;i++){
        printf("I am performing a critical operation using a semaphore \n");
        sleep(1);
    }
	printf("Operation %d is finished \n", tc);
	//increments (unlock) so sem_wait threads/processes can be woken up 
	sem_post(&s); 
    return NULL;
} 


 
