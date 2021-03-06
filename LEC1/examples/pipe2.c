#include <unistd.h>  /* pipe() fork() read() write() */                                            
#include <stdlib.h>  /* exit() */

// pipe2.c: communication between two processes

int main()
{
    int n, pid;
    int fds[2];
    char buf[100];

    // create a pipe, with two FDs in fds[0], fds[1].
    pipe(fds);
    
    pid = fork();
    if (pid == 0) {
        write(fds[1], "this is pipe2\n", 14);
    } else {
        n = read(fds[0], buf, sizeof(buf));
        write(1, buf, n); 
    }   

    exit(0);
}
