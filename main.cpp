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

int partition(int *a, int low, int high){
	int pivot = a[high];
	
	int i = low - 1;
	
	for (int j = low; j <= high; ++j){
		if (a[j] <= pivot) {
			i++;
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	return i;
}

void quicksort(int *a, int low, int high){
	if (low >= 0 && high >= 0 && low < high){
		int p = partition(a, low, high);
		
		quicksort(a, low, p - 1);
		quicksort(a, p + 1, high);
	}
}

int main(){

	FILE *f = fopen("input.txt", "r");
	char buf[10000];
	int positions[1000] = {};
	int idx = 0;

	while (fgets(buf, 10000, f)) {
		char *line = buf;
		while (true) {
			char n[5];
			line = getWord(n, line);
			if (n[0] >= '0' && n[0] <= '9') {
				positions[idx++] = atoi(n);
			} else {
				break;
			}
		}
	}
	
	for (int i = 0; i < idx; i++) {
		printf("%d, ", positions[i]);
	}
	printf("\n");
	quicksort(positions, 0, idx - 1);
	
	for (int i = 0; i < idx; i++) {
		printf("%d, ", positions[i]);
	}
	printf("\n");

	int median = positions[idx / 2];
	
	int difference = 0;

	for (int i = 0; i < idx; i++) {
		difference += abs(positions[i] - median);
	}

	printf("fuel used : %d\n", difference);


	

	printf("OK\n");

}




