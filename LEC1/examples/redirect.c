#include <unistd.h>    /* fork() close() execv() */                                         
#include <fcntl.h>     /* open() O_* */
#include <stdio.h>
#include <sys/wait.h>  /* wait() */
#include <stdlib.h>    /* exit() */

// redirect.c: run a command with output redirected

int main()
{
    int pid = fork();
    if (pid == 0) {
        close(stdout);
        open("output.txt", O_WRONLY | O_CREAT);

        char *argv[] = { "echo", "this", "is", "redirected", "echo", 0 };
        execv("/bin/echo", argv);
        printf("execv failed\n");
        exit(1);
    } else {
        wait((int *) 0); 
    }   

    exit(0);
}
