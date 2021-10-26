#include <stdio.h>
#include <stdlib.h>

// getbits: get n bits from position p 
unsigned getbits(unsigned x, int p, int n)
{
	return (x  >> (p+1-n)) & ~(~0 << n);
}


int main() 
{
	int n = 01234177;
	// &: set to 0 all but low-order 7 bits of n, to mask off some bits
	n &= 0177;
	// n = 177
	printf("n = 0%o\n", n);


	int x = 0;
	// |: set to 1 in bits that are set to 1 in 0x11, to turn bits on
	x |= 011;
	// x = 11
	printf("x = 0%o\n", x);


	x = 0101;
	// ^: set to 1 in each bit position where its operands are different
	// and 0 where they are the same
	x ^= 0010;
	// x = 111 
	printf("x = 0%o\n", x);


	// ~: set each 1-bit into a 0-bit and vice versa
	// set the last six bits of x to 0
	x &= ~077;
	// x = 100;
	printf("x = 0%o\n", x);

	x = getbits(034, 4, 3);
	// x = 7 
	printf("x = 0%o\n", x);


	exit(0);
}
