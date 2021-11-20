#include <stdio.h>
#define ArrayCount(Array) ((int)(sizeof(Array) / sizeof((Array)[0])))
#define MAX(A, B) (A > B ? A : B)

#define INT_MIN -2147483648
	

int maxSumQuadraticNegative(int *a, int len){ // can't use array count on a pointer. thus need len
	int maxSum = a[0];
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

int maxSumNlogNNegative(int *a, int l, int h){
	if (l > h){
		return INT_MIN;
	} else if (l == h) {
		return a[l];
	}

	int pivot = (l + h) / 2;

	int sum, lsum, rsum;
	// find left max
	sum = 0; // [pivot, l]
	lsum = INT_MIN;
	for (int i = pivot; i >= l; i--){
		sum += a[i];
		lsum = MAX(lsum, sum);
	}

	// find right max
	sum = 0;
	rsum = INT_MIN;
	for (int i = pivot + 1; i <= h; i++){ // [pivot, h]
		sum += a[i];
		rsum = MAX(rsum, sum);
	}

	return MAX(rsum + lsum, MAX(maxSumNlogNNegative(a, l, pivot),maxSumNlogNNegative(a, pivot + 1, h))) ;
}


int maxSumLinear(int *a, int len) {
	int maxsofar = 0;
	int maxendinghere = 0;

	for (int i = 0; i < len; i++){
		maxendinghere = MAX(maxendinghere + a[i], 0);
		maxsofar = MAX(maxsofar, maxendinghere);
	}

	return maxsofar;
}



int maxSumLinearNegative(int *a, int len) {
	int maxsofar = a[0];
	int maxendinghere = 0;
	
	for (int i = 0; i < len; i++){
		maxendinghere = MAX(maxendinghere + a[i], 0);
		maxsofar = MAX(maxsofar, maxendinghere);
	}
	
	return maxsofar;
}


int main(){
	int a[] = {-33, -12, -11, -3, -100 };

	printf("%d\n", maxSumQuadraticNegative(a, ArrayCount(a)));
	printf("%d\n", maxSumNlogNNegative(a, 0, ArrayCount(a) - 1));
	printf("%d\n", maxSumLinear(a, ArrayCount(a)));
	printf("OK\n");
	return 0;
}