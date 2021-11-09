#include <stdio.h>

#define swap(t,x,y) \
t temp = x; \
	x = y; \
		y = x;
	
	int main() {
		int l = 0;
		int v = 10;
		swap(int, l, v);
		printf("%d", l);
		char pattern[] = "hello";
	}