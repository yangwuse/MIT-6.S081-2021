#include <unistd.h>  /* fork() execv() */
#include <stdio.h>   /* printf() */
#include <stdlib.h>  /* exit() */

// forkexecv.c: fork then execv

int main()
{
    int pid, status;

    pid = fork();
    if (pid == 0) {
        char *argv[] = { "echo", "THIS", "IS", "ECHO", 0 };
        execv("/bin/echo", argv);
        printf("execv failed\n");
        exit(1);
    } else {
        printf("parent waiting\n");
        wait(&status);
        printf("the child exited with status %d\n", status);
    }   
                                                                                            
    exit(0);
}
