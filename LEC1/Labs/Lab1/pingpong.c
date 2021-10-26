#include "kernel/types.h"
#include "user/user.h"

int main() 
{
    int p[2];
    int pid;
    char ch;

    pipe(p);
    pid = fork();
    if (pid == 0) {
        read(p[0], &ch, 1);
        if (ch == '*')
            printf("%d: received ping\n", getpid());
        else {
            fprintf(2, "child read failed\n");
            exit(1);
        }

        write(p[1], "*", 1);
        exit(0);
    } else {
        write(p[1], "*", 1);
        wait((int*) 0);
        read(p[0], &ch, 1);
        if (ch == '*') 
            printf("%d: received pong\n", getpid());
        else {
            fprintf(2, "parent read failed\n");
            exit(1);
        }
        exit(0);
    }
}
