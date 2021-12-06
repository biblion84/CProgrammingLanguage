#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isAlphaNum(int c) 
{
	return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isSpace(int c) {
	return c == ' ' || c == '\t';
}

char * getWord(char *word, char *line) {
	int c = '\0';
	
	
	
	while (isSpace((c = *line++)));
	
	char *wp = word;
	
	do {
		*wp++ = (char)c;
	} while (*line != EOF && *line != '\0' && isAlphaNum((c = *line++)));
	
	*wp = '\0';
	
	return line;
}

#define SIZE 1000
#define SIZE_INPUT 500

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

struct point {
	int sx;
	int ex;
	int sy;
	int ey;
}

int main(){
	FILE *f = fopen("input.txt", "r");
	char buffer[300];
	
	int *table = (int *)malloc(SIZE * SIZE * sizeof(int));
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			table[i * SIZE + j] = 0;
		}
	}
	
	point points[SIZE_INPUT];
	
	int idx = 0;
	while (fgets(buffer, 300, f)) {
		char *line = buffer;
		char n[5];
		// 0,9 -> 5,9
		// 0
		line = getWord(n, line);
		points[idx].sx = atoi(n);
		// 9
		line = getWord(n, line);
		points[idx].sy = atoi(n);
		
		// ->
		line = getWord(n, line);
		
		// 5
		line = getWord(n, line);
		points[idx].ex = atoi(n);
		// 9
		line = getWord(n, line);
		points[idx].ey = atoi(n);
		
		idx++;
	}
	
	for (int i = 0; i < SIZE_INPUT; i++) {
		
		
		// lines
		if (points[i].sx == points[i].ex || points[i].sy == points[i].ey) {
			int sx = min(points[i].sx, points[i].ex);
			int ex = max(points[i].sx, points[i].ex);
			int sy = min(points[i].sy, points[i].ey);
			int ey = max(points[i].sy, points[i].ey);
			
			for (int y = sy; y <= ey; y++) {
				for (int x = sx; x <= ex; x++) {
					table[y* SIZE + x]++;
				}
			}
		} else {
			sx = points[i].sx;
			ex = points[i].ex;
			sy = points[i].sy;
			ey = points[i].ey;
			
			int steps = abs(ey - sy);
			int dx = sx < ex ? 1 : -1;
			int dy = sy < ey ? 1 : -1;
			
			for (int s = 0; s <= steps; s++){
				table[(sy + (s * dy)) * SIZE + (sx + (s * dx))]++;
			}
		}
		
	}
	
	int count = 0;
	
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			if (table[y * SIZE + x] >= 2) {
				count++;
			}
		}
	}
	printf("result %d\n", count);
}




