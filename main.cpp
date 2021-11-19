#include <stdio.h>
#define ArrayCount(Array) ((int)(sizeof(Array) / sizeof((Array)[0])))
#define MAX(A, B) (A > B ? A : B)


int maxSumQuadratic(int *a, int len){ // can't use array count on a pointer. thus need len
	int maxSum = 0;
	for (int i = 0; i < len; ++i){
		int sum = 0;
		for (int j = i; j < len; ++j){
			sum += a[j];
			if (sum > maxSum){
				maxSum = sum;
			}
		}
	}
	return maxSum;
}

int maxSumNlogN(int *a, int l, int h){
	if (l > h){
		return 0;
	} else if (l == h) {
		return MAX(a[l], 0);
	}

	int pivot = (l + h) / 2;

	int sum, lsum, rsum;
	// find left max
	lsum = sum = 0; // [pivot, l]
	for (int i = pivot; i >= l; i--){
		sum += a[i];
		lsum = MAX(lsum, sum);
	}

	// find right max
	rsum = sum = 0;
	for (int i = pivot + 1; i <= h; i++){ // [pivot, h]
		sum += a[i];
		rsum = MAX(rsum, sum);
	}

	return MAX(rsum + lsum, MAX(maxSumNlogN(a, l, pivot),maxSumNlogN(a, pivot + 1, h))) ;
}


int maxSumLinear(int *a, int len) {
	int maxsofar = 0;
	int maxendinghere = 0;

	for (int i = 0; i < len; i++){
		maxendinghere = MAX(maxendinghere + a[i], 0);
		maxsofar = MAX(maxsofar, maxendinghere);
	}

	return maxendinghere;
}

int main(){
	int a[] = { -95, 95, 3, -8, -13, 25, 33, 55, -500, 30 };

	printf("%d\n", maxSumQuadratic(a, ArrayCount(a)));
	printf("%d\n", maxSumNlogN(a, 0, ArrayCount(a) - 1));
	printf("%d\n", maxSumLinear(a, ArrayCount(a)));
	printf("OK\n");
	return 0;
}