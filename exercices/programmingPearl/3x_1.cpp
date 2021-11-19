#include <stdio.h>

#define ArrayCount(Array) (sizeof(Array) / sizeof((Array)[0]))

int binarySearch(int* a, int p, int low, int high){
	if (low > high) {
		return -1;
	}
	int middleIndex = low + ((high - low) / 2);
	//printf("%d index searched, low : %d, high : %d", middleIndex, low, high);
	
	if (p > a[middleIndex]) {
		//printf(" Greater p : %d, i : %d\n", p , a[middleIndex]);
		return binarySearch(a, p, middleIndex + 1, high);
	} else if (p < a[middleIndex]){
		//printf(" Lower p : %d, i : %d\n", p , a[middleIndex]);
		return binarySearch(a, p, low, middleIndex - 1);
	} else { // p == a[middleIndex]
		return middleIndex;
	}
	
}

int main(){
	int power[30];
	for (int i = 1; i < ArrayCount(power); i++) {
		power[i] = 1 << i;
	}
	
	int x = 123;
	int numbers[1000];
	int numbersIndex = 0;
	while (x != 1) {
		numbers[numbersIndex++] = x;
		if (x % 2  == 0){
			x = x / 2;
		} else {
			x = 3 * x + 1;
		}
	}
	
	int *n = numbers;
	for (int i = 0; i < numbersIndex; i++){
		int found = binarySearch(power, numbers[i], 0, ArrayCount(power));
		if (found >= 0){
			printf("%d POWER %d\n", numbers[i], found);
		} else {
			printf("%d\n", numbers[i]);
		}
	}
	
	printf("Stopped\n");
	
}