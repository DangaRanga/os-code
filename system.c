#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//LOOK up the system() using man pages

int main(){
    char text[80];
    strcpy(text,"ps");
    system(text);
    return 0;
}