#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size(buf) sizeof(buf)

int main()
{
    const char *str = "hello";

    char *buf  = malloc(5);

    char buf2[] = "hello";

    char *buf3 = str;

    char buf4[10] = "hello";

    char *buf5 = malloc(5);
    strcpy(buf5, str);

    // 8 6 8 10 8
    printf("buf: %d\n buf2: %d\n buf3: %d\n buf4: %d\n buf5: %d\n",
            size(buf), size(buf2), size(buf3), size(buf4),size(buf5));

    // 5: strlen dont count 0, but sizeof count
    printf("%d\n", strlen(buf2));
    exit(0);
}
