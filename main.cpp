#include <stdio.h>
#include <stdlib.h>

int main() {
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
