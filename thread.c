#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *myThread(void *args);

int main(){
  pthread_t thread_id;
  printf("Printing before the thread starts\n");
  pthread_create(&thread_id, NULL, myThread, NULL);
  pthread_join(thread_id,NULL);
  printf("Printing after thread\n");
  sleep(5);
  exit(0);

  return 0;
}

void *myThread(void *args){
  for(int i=0;i<5;i++){
    printf("Hello from Thread %d time(s)\n",i+1);
    sleep(1);
  }
  return NULL;
}