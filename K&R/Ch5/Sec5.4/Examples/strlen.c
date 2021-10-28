#include <stdio.h>
#include <stdlib.h>

size_t strlen(char *s);

int main() 
{
	printf("%d\n", strlen("hello"));
	printf("%d\n", sizeof(size_t));
	exit(0);
}

size_t strlen(char *s)
{
	char *p = s;
	while (*p != '\0')
		p++;
	return p - s;
}
