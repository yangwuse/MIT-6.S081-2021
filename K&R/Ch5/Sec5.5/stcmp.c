#include <stdio.h>
#include <stdlib.h>

#define compare(val) val == 0 ? "==" : \
			val > 0 ? ">" : "<" \

// return 0 if s < t, 0 if s == t, > 0 if s > t
int strcmp1(char *s, char *t)
{
	int i;
	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}

// pointer version
int strcmp2(char *s, char *t)
{
	for (; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

int main()
{
	char *s = "hello";
	char *t = "world";
	printf("%s %s %s\n", s, compare(strcmp2(s, t)), t);
	exit(0);
}
