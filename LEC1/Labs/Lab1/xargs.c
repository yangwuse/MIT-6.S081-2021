#include "kernel/types.h"
#include "kernel/param.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    char *inputs[100];
    char buf[MAXARG];
    int i = 0, j = 0;
    char ch;
    while (read(0, &ch, 1) > 0) {
        if (ch != '\n')
            buf[i++] = ch;
        else {
            buf[i] = 0;
            i = 0;
            inputs[j] = malloc(strlen(buf) + 1);
            strcpy(inputs[j], buf);
            *(inputs[j] + strlen(buf)) = 0;
            j++;
        }
    }

    char *args[MAXARG];
    for (i = 1; i < argc; i++) {
        args[i-1] = malloc(strlen(argv[i]) + 1);
        strcpy(args[i-1],argv[i]);
        *(args[i-1] + strlen(argv[i])) = 0;
    }

    // be carefull
    i--;
    
    for (j = 0; inputs[j] != 0; j++) {
        args[i] = malloc(strlen(inputs[j]) + 1);
        strcpy(args[i], inputs[j]);
        *(args[i] + strlen(inputs[j])) = 0;
        args[i+1]  = 0;

        if (fork() == 0) {
            exec(argv[1], args);
            printf("%d: exec faild\n", getpid());
            exit(1);
        } else
            wait((int*) 0);

    }
    exit(0);
}
