#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 10
#define BUFSIZE 100
char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;  // next free position in buf

int getch();
void ungetch(int);
int getint(int *pn);

int main() 
{
	int n, arr[SIZE];
	for (n = 0; n < SIZE && getint(arr+n) != EOF; n++)
		printf("%d ", arr[n]);

	exit(0);
}

// getint: get next integer from input into *pn
int getint(int *pn)
{
	int c, sign, hassign = 0;
	while (isspace(c = getch())) // skip white space
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); // it it not a number
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
		hassign = 1;
	}

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	
	*pn *= sign;
	if (c != EOF) {
		ungetch(c);
	}

	return c;
}

int getch()  // get a (possibly pushed-back) char
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  // push char back on input
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else 
		buf[bufp++] = c;
}
