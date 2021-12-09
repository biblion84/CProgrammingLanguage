#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_Y 100
#define SIZE_X 100

int main() {
	FILE *f = fopen("input.txt", "r");
	char buf[300];
	
	int hm[SIZE_Y][SIZE_X] = {};
	
	int y = 0;
	while (fgets(buf, 300, f)) {
		int x = 0;
		for (char *c = buf; *c != '\0' && *c != '\n'; c++){
			hm[y][x++] = *c - '0';
		}
		y++;
	}
	
	int total = 0;
	for (y = 0; y < SIZE_Y; y++) {
		for (int x = 0; x < SIZE_X; x++){
			bool smaller = true;
			int v = hm[y][x];
			if (y - 1 >= 0 && hm[y-1][x] <= v) {
				smaller = false;
			} else if (y + 1 < SIZE_Y && hm[y+1][x] <= v) {
				smaller = false;
			} else if (x - 1 >= 0 && hm[y][x-1] <= v) {
				smaller = false;
			} else if (x + 1 < SIZE_X && hm[y][x+1] <= v) {
				smaller = false;
			}
			if (smaller) {
				total += v + 1;
			}
		}
	}
	
	printf("Ok Total : %d\n", total);
}