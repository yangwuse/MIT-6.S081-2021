#include <unistd.h>    /* pipe() fork() close() dup() execv() write() */
#include <stdlib.h>    /* exit() */
 
// pipe3: pipe and redirect between processes.
                                                                                            
int main() 
{
    int p[2];
    char *argv[] = { "wc", 0 };
    pipe(p);
    if (fork() == 0) {
        close(0);
        dup(p[0]);
        close(p[0]);
        close(p[1]);
        execv("/usr/bin/wc", argv);
    } else {
        close(p[0]);
        write(p[1], "hello world\n", 12);
        close(p[1]);
    }

    exit(0);
}
