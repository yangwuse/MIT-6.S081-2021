// fork.c: create a new process

#include <unistd.h>  /* fork() */
#include <stdio.h>   /* printf() */                                                         
#include <stdlib.h>  /* exit() */

int main()
{
    int pid = fork();
    printf("fork() returned %d\n", pid);
    if (pid == 0)  
        printf("child\n");
    else
        printf("parent\n");
    exit(0);
}
