// execv.c: replace a process with an executable file

#include <unistd.h>  /* read() write() */                                                   
#include <string.h>  /* strlen() */
#include <stdlib.h>  /* exit() */

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        write(1, argv[i], strlen(argv[i]));
        if (i + 1 < argc)
            write(1, " ", 1); 
        else
            write(1, "\n", 1); 
    }   
    exit(0);
}
