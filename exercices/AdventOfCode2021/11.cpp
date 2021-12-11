#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int o[10][10] = {};
bool flashed[10][10] = {};
int steps = 0;


void flash(int y, int x) {
	steps++;
	for (int yy = -1; yy <= 1; yy++){
		for (int xx = -1; xx <= 1; xx++) {
			if (yy == 0 && xx == 0) {
				continue;
			}
			int newY = y + yy;
			int newX = x + xx;
			if (newY >= 0 && newY < 10 && newX >= 0 && newX < 10) {
				o[newY][newX]++;
			}
		}
	}
	o[y][x] = 0;
}


int main() {
	FILE *f = fopen("input.txt", "r");
	char buf[300];
	
	{
		int y = 0;
		while (fgets(buf, 300, f)) {
			char *line = buf;
			for (int i = 0; i < 10; i++) { // 10x10 grid always
				o[y][i] = *line++ - '0';
			}
			y++;
			
		}
	}
	
	for (int step = 1; step < 1000; step++){
		for (int y = 0; y < 10; y++) {
			for (int x = 0; x < 10; x++) {
				flashed[y][x] = 0;
				o[y][x]++;
			}
		}
		
		int hasFlashed = 0;
		do {
			int oldFlash = hasFlashed;
			hasFlashed = 0;
			for (int y = 0; y < 10; y++){
				for (int x = 0; x < 10; x++) {
					int value = o[y][x];
					if (value > 9) {
						hasFlashed++;
						flashed[y][x] = true;
						flash(y, x);
					}
				}
			}
			for (int y = 0; y < 10; y++) {
				for (int x = 0; x < 10; x++) {
					if (flashed[y][x]) {
						o[y][x] = 0;
					}
				}
			}
			if ((hasFlashed + oldFlash) == 100) {
				printf("%d step\n", step);
				printf("%d flashed", hasFlashed + oldFlash);
				printf("\n");
				for (int y = 0; y < 10; y++) {
					for (int x = 0; x < 10; x++) {
						printf("%d", o[y][x]);
					}
					printf("\n");
				}
				return 0;
			}
		} while (hasFlashed > 0); 
		
		
	}
	printf("Steps : %d\n", steps);
	printf("OK\n");
}
