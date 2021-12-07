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

#define SIZE 1000000
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
};

int main(){
	
	for (int bench = 0; bench < 1000; bench++) {
		
		FILE *f = fopen("input.txt", "r");
		char buffer[1000];
		int *table = (int *)malloc(SIZE * sizeof(int));
		for (int i = 0; i < SIZE; i++) {
			table[i] = -1;
		}
		
		int idx = 0;
		
		while (fgets(buffer, 1000, f)) {
			char *line = buffer;
			while (true) {
				char n[5];
				line = getWord(n, line);
				if (n[0] > '0' && n[0] <= '9') {
					table[idx] = atoi(n);
					idx++;
				} else {
					break;
				}
			}
		}
		
		
		//
		//	for (int day = 0; day < 80; day++) {
		//		int currentIndex = idx;
		//		for (int i = 0; i < currentIndex; i++) {
		//			if (table[i] == 0) {
		//				table[i] = 6;
		//				table[idx++] = 8;
		//			} else {
		//				table[i]--;
		//			}
		//		}
		//	}
		//	int fishCount = 0;
		//	for (fishCount = 0; fishCount < SIZE && table[fishCount] != -1; fishCount++);
		//	printf("Fish : %d\n", fishCount);
		
		long long fish[9];
		for (int i = 0; i < 9; i++) {
			fish[i] = 0;
		}
		
		for (int i = 0; i < idx; i++) {
			if (table[i] == -1) break;
			fish[table[i]]++;
		}
		
		for (int day = 0; day < 256; day++) {
			long long temp = fish[0];
			
			for (int i = 0; i < 8; i++) {
				if (fish[i + 1] > 0) {
					fish[i] = fish[i + 1];
				} else {
					fish[i] = 0;
				}
			}
			if (temp > 0) {
				if (fish[6] == -1) {
					fish[6] = temp;
				} else {
					fish[6] += temp;
				}
				fish[8] = temp;
			} else {
				fish[8] = 0;
			}
			
		}
		
		long long result = 0;
		for (int i = 0; i < 9; i++) {
			//printf("%d : %lld, table %d\n", i, fish[i], table[i]);
			result += fish[i];
		}
		
		printf("Result : %lld\n", result);
		fclose(f);
		free(table);
	}
	
	
	//printf("0K\n");
}




