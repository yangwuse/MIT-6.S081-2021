#include <stdio.h>
#include <stdlib.h>

// copy the string t to the end of s
void strcat(char *s, char *t)
{
	while (*s++) ;
	s--;
	while (*s++ = *t++) ;
}

int main() 
{
	char s[] = "hello";
	char *t = " world";
	
	strcat(s, t);
	printf("%s\n", s);
	exit(0);
}
