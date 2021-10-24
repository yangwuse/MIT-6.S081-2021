#include <unistd.h>  /* read() write() */
#include <stdlib.h>  /* exit() */
                                                                                            
int main()
{
    char buf[64];
    int n;
    while ( (n = read(0, buf, sizeof(buf))) > 0 ) 
        write(1, buf, n); 
    exit(0);
}
