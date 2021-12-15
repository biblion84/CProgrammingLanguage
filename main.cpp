#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

const int INIT_LEN = 100;
const int LEN = INIT_LEN * 5;
const int MAX = 1 << 30;

// Should use a heap
// I hope djisktra won't read my code
int smallest(int *distances, bool *visited) {
	int min = 1 << 30;
	int index = 0;

	for (int i = 0; i < LEN * LEN; i++) {
		if (distances[i] < min && !visited[i]) {
			min = distances[i];
			index = i;
		}
	}

	return index;
}

int main() {
	FILE *f = fopen("input.txt", "r");
	char buffer[300] = {};

	int *table = (int *)malloc(LEN * LEN * sizeof(int));
	{
		int y = 0;
		while (fgets(buffer, 300, f) != 0) {
			for (int x = 0; buffer[x] != '\0'; x++) {
				table[y * LEN + x] = buffer[x] - '0';
			}
			++y;
		}
	}
	for (int y = 0; y < INIT_LEN; y++){
		for (int x = 0; x < INIT_LEN; x++) {
			for (int yy = 0; yy < 5; yy++) {
				for (int xx = 0; xx < 5; xx++) {
					int newY = y + (yy * INIT_LEN);
					int newX = x + (xx * INIT_LEN);
					int value = table[y * LEN + x] + yy + xx;
					if (value > 9) {
						value = 1 + (value % 10);
					}
					table[newY * LEN + newX] = value;
				}
			}
		}
	}
#if 0
	printf("\n");
	printf("\n");
	
	for (int y = 0; y < LEN; y++) {
		for (int x = 0; x < LEN; x++) {
			printf("%d", table[y * LEN + x]);
		}
		printf("\n");
	}
	printf("\n");
		printf("\n");
#endif
	

	int *distances  = (int *)malloc(LEN * LEN * sizeof(int));
	bool *visited  = (bool *)malloc(LEN * LEN * sizeof(bool));

	for (int i = 0; i < LEN * LEN; i++) {
		distances[i] = MAX;
		visited[i] = false;
	}

	distances[0] = 0; // The distance from the start is 0

	for (int i = 0; i < (LEN * LEN) - 1; i++) {
		int cur = smallest(distances, visited);
		
		visited[cur] = true;
		
		int currentX = cur % LEN;
		int previousX = -1;
		if (currentX > 0) {
			previousX = cur - 1;
		}

		int nextX = -1;
		if (currentX < LEN - 1) {
			nextX = cur + 1;
		}
		int previousY = cur - LEN;
		int nextY = cur + LEN;

		int t[4] = { previousY, previousX, nextY, nextX };
		for (int n = 0; n < 4; n++) {
			int next = t[n];
			if (next >= 0 && next < LEN * LEN) {
				if (!visited[next] && (distances[cur] + table[next]) < distances[next] ) {
					distances[next] = distances[cur] + table[next];
				}
			}
		}
	}

	//for (int y = 0; y < LEN; y++){
	//	for (int x = 0; x < LEN; x++) {
	//		printf("%3d ", distances[y * LEN + x]);
	//	}
	//	printf("\n");
	//}
	printf("%d", distances[(LEN * LEN) - 1]);

	printf("Ok\n");

}
