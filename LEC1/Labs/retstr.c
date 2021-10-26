#include <stdio.h>
#include <stdlib.h>

char *
getstr()
{
    // return heap memory addr
    char *str = malloc(6);
    strcpy(str, "hello");
    // dont forget 0
    str[5] = 0;
    return str;
}

char *
getstr2()
{
    // return static memory addr
    // dont need 0
    static char buf[] = "hello";
    return buf;
}

int main()
{
    printf("%s\n", getstr());
    exit(0);
}
