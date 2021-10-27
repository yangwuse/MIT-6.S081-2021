#include <stdio.h>
#include <stdlib.h>

// return x with the n bits that begin at position p set to
// the rigthmost n bits of y, leaving the other bits unchanged
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	// save bits of p with position 0~n-1
	int a = x;
	a = a & ~(~0 << (p+1-n));	
	// set bits of p to 0 with position 0~p
	// resume the original bits position
	int b = x;
	b = (b >> (p+1)) << (p+1);

	// save bits of y with position 0~n-1, and left move p+1-n position
	y = (y & ~(~0 << n)) << (p+1-n);

	return (a | b | y); 
}


int main() 
{
	unsigned char x = 0b1111;
	unsigned char y = 0b1000;
	printf("%0x\n", setbits(x, 2, 2, y));
	exit(0);
}
