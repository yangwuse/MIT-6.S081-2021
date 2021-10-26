#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) 
{
    if (argc < 2) {
      fprintf(2, "usage: sleep secs\n");
      exit(1);
    }

    int secs = atoi(argv[1]);
    sleep(secs);
    
    exit(0);
}
