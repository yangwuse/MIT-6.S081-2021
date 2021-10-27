#include <stdio.h>
#include <stdlib.h>

// return the value of the integer x rotated to the right by n positions
int rightrot(int x, int n)
{
	// save bits of p ranging from [0, n-1]
	int a = x;
	a = a & ~(~0 << n);	
	// left shif 32-n positions
	a = a << (32 - n);

	// get bits of p ranging from [n, 31] 
	int b = x;
	b = (b >> n) & ~(~0 << (32 - n)); 

	return a | b;
}


int main() 
{
	int x = 0xffffff10;
	// 10ffffff
	printf("%0x\n", rightrot(x, 8));
	exit(0);
}
