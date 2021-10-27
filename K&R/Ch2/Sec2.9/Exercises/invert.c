#include <stdio.h>
#include <stdlib.h>

// return x with the n bits that begin at position p inverted
unsigned invert(unsigned x, int p, int n)
{
	// save bits of p ranging from [0, p-n]
	unsigned char a = x;
	a = a & ~(~0 << (p+1-n));	
	
	// get bits of p ranging from [p+1-n, p] 
	unsigned char b = x;
	b = (b >> (p+1-n)) & ~(~0 << n); 
	
	// resume the original position and ~
	b = ~(b << (p+1-n));

	return x | b | a;
	
	
}


int main() 
{
	unsigned char x = 0b1001;
	// ff
	printf("%0x\n", invert(x, 2, 2));
	exit(0);
}
