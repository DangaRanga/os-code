#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<time.h>

#define SHARED 0

void *putItem(void *arg);
void *buyItem(void *arg);

sem_t empty, full, sm;
char * buy;

void *putItem(void *str){
    time_t now;
    char * string = str;
    int item;

    printf("%s: Shelving thread started...\n", string);
    char fruits[6][10] = {"Mango", "Banana", "Apple", "Cherry","Plum","Kiwi"};

    for(item=0; item<6;item++){
		//check on empty space first 
		
       sem_wait(&empty); //shows the number of empty spaces or spaces free
       sem_wait(&sm);
       buy=fruits[item];
       sem_post(&sm);
       sem_post(&full); //signalling full will wake consumer up since it's checking full to see if it can consumer/buy
       time(&now);
       printf("%s: Placed %s on the shelf at time %ld ..\n", string, fruits[item], now);
       sleep(1);
    }

}

void *buyItem(void *str){
    time_t now;
    int consumed;
    char * string = str;
    printf("%s: Buying thread started...\n", string);
    for(consumed=0; consumed<2;consumed++){
		//check on full first
        sem_wait(&full); // shows the number of items in the buffer
        sem_wait(&sm);
        time(&now);
        printf("%s: Thread buying %s at time %ld \n", string, buy, now);
        sem_post(&sm);
        sem_post(&empty); //signals that an empty space is in the buffer
    }
}

int main(){
    pthread_t ptid, ctid1, ctid2, ctid3;

    sem_init(&empty, SHARED, 1); // empty is intialized to 1 because in the beginning a space is free.
    sem_init(&full, SHARED, 0); //full is  initialized to zero as not items in the buffer in the beginning
    sem_init(&sm, SHARED, 1);


    char * shelver1 = "Shelver 1";
    pthread_create(&ptid, NULL, putItem,(void *) shelver1);

    char * buyer1 = "Buyer 1";
    pthread_create(&ctid1, NULL, buyItem,(void *) buyer1);

    char * buyer2 = "Buyer 2";
    pthread_create(&ctid2, NULL, buyItem,(void *) buyer2);

    char * buyer3 = "Buyer 3";
    pthread_create(&ctid3, NULL, buyItem,(void *) buyer3);

    pthread_join(ptid, NULL);
    pthread_join(ctid1, NULL);
    pthread_join(ctid2, NULL);
    pthread_join(ctid3, NULL);

    sem_destroy(&sm);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}
