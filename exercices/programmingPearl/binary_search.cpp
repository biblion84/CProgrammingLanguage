#include <stdio.h>


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
	
	int a[100];
	int j = 0;
	for (int i = 0; i < 100; i++){
		a[i] = j;
		j += 2;
		//printf("%d\n", i);
	}
	for (int i = 0; i < 100; i+= 2){
		int index = binarySearch(a, i, 0, 99);
		if (index == -1){
			printf("Error not found %d\n", i);
		}
	}
	
	
}