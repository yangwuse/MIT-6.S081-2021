#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// strcpy: copy to s, include '\0', array version
void strcpy1(char *s, char *t)
{
	int i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}

// pointer version
void strcpy2(char *s, char *t)
{
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}

// pointer version 2
void strcpy3(char *s, char *t) 
{
	while ((*s++ = *t++) != '\0')
		;
}

// pointer version 3
void strcpy4(char *s, char *t)
{
	while (*s++ = *t++)
		;
}

int main() 
{
	// p pints to "hello", not copy
	char *p = "hello";

	// array contians "hello" plus '\0'
	// str always points to the same storage, for changing string
	char str[] = "world";

	strcpy4(str, p);
	printf("%s\n", str);

	return 0;
}
