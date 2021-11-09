#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>


int main(){

    int i,j;
    j=0;
    pid_t cpid; 

    printf("Ready to fork...\n");
    printf("Parent pid = %d\n", getpid()); 
    i=fork();
    if (i == 0){
        printf("The child executes this code.\n");
        for (i=0; i<5; i++)
            j=j+i;
        printf("Child j=%d\n",j);
    } else {
        // cpid = wait(NULL);
        printf("The parent executes this code.\n");
        for (i=0; i<3; i++)
                j=j+i;
        printf("Parent j=%d\n",j);
        // printf("Child pid = %d\n", cpid); 
    }
}
