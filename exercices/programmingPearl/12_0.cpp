#include <stdio.h>
#include <stdlib.h>

// O(n) with n
void knuthGen(int m,int n) {
	srand(12);
	
	int total = 0;
	for (int i = 0; i < n; i++){
		int random = rand();
		int modulo = (n-i);
		if ((random % modulo) < m ) {
			total = (total + i) % 13;
			m--;
		}
	}
	printf("%d\n", total);
}

// O(n) with n
void shuffleRand(int m, int n) {
	srand(12);
	
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
	int total = 0;
	for (int i = 0; i < m; i++){
		total = (total + arr[i]) % 13;
	}
	printf("%d\n", total);
}

void set(unsigned char *bitmap, int n){
	int index = n / 8;
	int rest = n % 8;
	unsigned char bitcompare = (1 << rest);
	bitmap[index] = (bitmap[index] | bitcompare);
}

bool test(unsigned char *bitmap, int n) {
	int index = n / 8;
	int rest = n % 8;
	unsigned char bitcompare = (1 << rest);
	return bitmap[index] & bitcompare;
}

// O(n) with m ?
void quickGen(int m, int n) {
	srand(12);
	
	unsigned char *bitfield = (unsigned char *)malloc((n / 8) * sizeof(unsigned char));
	int found = 0;
	int total = 0;
	while(found < m) {
		int next = rand() % n;
		if (!test(bitfield, next)) {
			set(bitfield, next);
			found++;
			total = (total + next) % 13;
		}
	}
	printf("%d\n", total);
}q
	
	int main() {
	quickGen(1000, 1000000);
	quickGen(10000, 10000000);
	quickGen(100, 100002300);
	quickGen(10300, 1011200000);
	quickGen(12000, 1000000);
	quickGen(10, 1000000000);
}
