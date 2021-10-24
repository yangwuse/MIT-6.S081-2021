#include <unistd.h>  /* execv() */                                                          
#include <stdlib.h>  /* exit() */

int main()
{
    char *args[] = {"echo", "hello", "world", 0 };
    execv("/bin/echo", args);
    exit(0);
}
