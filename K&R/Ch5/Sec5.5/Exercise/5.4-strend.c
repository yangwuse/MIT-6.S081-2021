#include <stdio.h>
#include <stdlib.h>

// return 1 if t occurs in the end of s, or return 0
int strend(char *s, char *t)
{
	int lens = 0, lent = 0;
	while (*s++)
		lens++;
	while (*t++)
		lent++;

	if (lens < lent)
		return 0;

	s--;
	t--;
	while (lent--)
		if (*s-- != *t--)
			return 0;

	return 1;
}

int main() 
{
	char s[] = "hello world";
	char t1[] = " wold";
	char t2[] = " world";
	
	int rc = strend(s, t1);
	printf("%d\n", rc);
	rc = strend(s, t2);
	printf("%d\n", rc);

	exit(0);
}
