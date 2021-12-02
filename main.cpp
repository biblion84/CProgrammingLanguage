#include <stdio.h>
#include <stdlib.h>

void knuthGen() {
	srand(12);

	int m  = 10;
	int n = 100;
	for (int i = 0; i < n; i++){
		int random = rand();
		int modulo = (n-i);
		printf("chance to pick : %.2f\n", (float)m/(float)(n-i) );
		if ((random % modulo) < m ) {
			printf("%d\n", i);
			m--;
		}
	}
}

void shuffleRand() {
	srand(12);
	int m  = 10;
	int n = 100;

	int *arr = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < n; i++) {
		int nIndex = rand() % n;
		int temp = arr[i];
		arr[i] = arr[nIndex];
		arr[nIndex] = temp;
	}

	for (int i = 0; i < m; i++){
		printf("%d\n", arr[i]);
	}
}
