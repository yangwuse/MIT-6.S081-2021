// open.c: create a file, write to it.

#include <fcntl.h>   /* open() O_* */                                                       
#include <unistd.h>  /* write() */
#include <stdlib.h>  /* exit() */

int main()
{
    int fd = open("output.txt", O_WRONLY | O_CREAT);
    write(fd, "hello world\n", 12);
    exit(0);
}
