#include <stdio.h>
#include "main.h"

typedef unsigned char byte;

// x : 11100110 -> 01110011 -> 10111001
byte rightrot(byte x, byte n) {
	for (int i = 0; i < n; i++) {
		byte lastB = x & 1;
		x = (x >> 1) | (lastB << 7);
	}
	return x;
	
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
	byte x = rightrot(230, 2);
	printf("%d", x);
	return 0;
}