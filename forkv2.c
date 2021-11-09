#include <stdio.h>
#include <unistd.h>

int main()
{
    int i;

    i = getpid();
    printf("Parent=%d\n", i);

    // Create child process
    fork();

    // Create child of child process
    fork();

    // Retrieve process ID for second child process
    i = getpid();
    printf("Who am I? %d\n", i);

    return 0;
}
