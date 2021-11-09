#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

    // Initializing and declaring values to be used
    int i, j;
    j = 0;
    pid_t cpid;

    printf("Ready to fork...\n");

    // Retrieve id of process currently running
    printf("Parent pid = %d\n", getpid());

    // Creates a child process, where the first value will be 0
    i = fork();
    if (i == 0)
    {
        printf("The child executes this code.\n");

        // Loops and prints processes currently running
        for (i = 0; i < 5; i++)
            j = j + i;
        printf("Child j=%d\n", j);
    }
    else
    {
        cpid = wait(NULL);
        printf("The parent executes this code.\n");
        for (i = 0; i < 3; i++)
            j = j + i;
        printf("Parent j=%d\n", j);
        printf("Child pid = %d\n", cpid);
    }
}
