#include <stdio.h>
#include "main.h"

void setbits(unsigned x,unsigned p, unsigned n,unsigned y) {
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
	// getbits(x, 4, 3)		x : 01010110
	// x >> (p+1-n))			x : 00010101
	// x >> 2
	// (~0 << n)				    : 11111111 << 3
	// (~0 << n)				    : 11111000
	// ~(~0 << n)				    : 00000111
	// 		00010101
	// &	00000111
	// = 	00000101
}

/* print the longest input line */
int main() {

	return 0;
}