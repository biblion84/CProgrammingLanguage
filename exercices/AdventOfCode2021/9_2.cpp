#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_Y 100
#define SIZE_X 100

int hm[SIZE_Y][SIZE_X] = {};
bool visited[SIZE_Y][SIZE_X] = {};

int followGradient(int y, int x) {
	if (visited[y][x]) {
		return 0;
	} else {
		visited[y][x] = true;
	}
	int total = 1;
	int v = hm[y][x];
	//printf("+1 value found : %d\n", v);
	if (y - 1 >= 0 && hm[y-1][x] > v && hm[y-1][x] != 9) {
		total += followGradient(y-1, x);
	}
	if (y + 1 < SIZE_Y && hm[y+1][x] > v && hm[y+1][x] != 9) {
		total += followGradient(y+1, x);
	}
	if (x - 1 >= 0 && hm[y][x-1] > v && hm[y][x-1] != 9) {
		total += followGradient(y, x-1);
	} 
	if (x + 1 < SIZE_X && hm[y][x+1] > v && hm[y][x+1] != 9) {
		total += followGradient(y, x+1);
	}
	return total;
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

int main() {
	FILE *f = fopen("input.txt", "r");
	char buf[300];
	
	{
		int y = 0;
		while (fgets(buf, 300, f)) {
			int x = 0;
			for (char *c = buf; *c != '\0' && *c != '\n'; c++) {
				hm[y][x++] = *c - '0';
			}
			y++;
		}
	}
	
	
	struct lowPoints {
		int x;
		int y;
	};
	
	lowPoints lp[300] = {};
	int lpIdx = 0;
	for (int y = 0; y < SIZE_Y; y++) {
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
				lp[lpIdx++] = lowPoints { x, y };
			}
		}
	}
	int sizes[300] = {};
	int sizesIdx = 0;
	int total = 0;
	
	for (int i = 0; i < lpIdx; i++) {
		int x = lp[i].x;
		int y = lp[i].y;
		sizes[sizesIdx++] = followGradient(y, x);
		//printf("size for %d : %d\n", hm[y][x], sizes[sizesIdx - 1]);
	}
	
	quicksort(sizes, 0, 299);
	
	for (int i = 0; i < 300; i++){
		printf("%d\n", sizes[i]);
	}
	int result = sizes[299] * sizes[298] * sizes[297];
	printf("result : %d\n", result);
}