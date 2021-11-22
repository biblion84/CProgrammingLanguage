#include <stdio.h>
#define ArrayCount(Array) ((int)(sizeof(Array) / sizeof((Array)[0])))
#define MAX(A, B) ((A) > (B) ? (A) : (B))

#define INT_MIN -2147483648

unsigned int seed;
/* The state word must be initialized to non-zero */
unsigned int random()
{
	/* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
	unsigned int x = seed;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return seed = x;
}

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

inline int max(int a, b){
	if (a > b){
		return a;
	} else {
		return b;
	}
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
		lsum = max(lsum, sum);
	}
	
	// find right max
	sum = 0;
	rsum = INT_MIN;
	for (int i = pivot + 1; i <= h; i++){ // [pivot, h]
		sum += a[i];
		rsum = max(rsum, sum);
	}
	
	return max(rsum + lsum, max(maxSumNlogNNegative(a, l, pivot),maxSumNlogNNegative(a, pivot + 1, h))) ;
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
	int maxendinghere = a[0];
	
	for (int i = 1; i < len; i++){
		maxendinghere = MAX(maxendinghere + a[i], a[i]);
		maxsofar = MAX(maxsofar, maxendinghere);
	}
	
	return maxsofar;
}


void scaffolding(){
	seed = 42;
	int runs = 10;
	int size = 100;
	
	int a[100];
	for (int i = 0; i < runs; i++){
		for (int j = 0; j < size; j++) {
			a[j] = (int)(random() % 200);
			if (random() % 4) {
				a[j] = -a[j];
			}
		}
		int quadraticSolution = maxSumQuadraticNegative(a, size);
		int logSolution = maxSumNlogNNegative(a, 0, size - 1);
		int linearSolution = maxSumLinearNegative(a, size);
		
		printf("Quad %d, log %d, Linear %d\n", quadraticSolution, logSolution, linearSolution);
	}
}

int main(){
	scaffolding();
	//int a[] = {-33, -12, -11, -3, -100 };
	//
	//	printf("%d\n", maxSumQuadraticNegative(a, ArrayCount(a)));
	//	printf("%d\n", maxSumNlogNNegative(a, 0, ArrayCount(a) - 1));
	//	printf("%d\n", maxSumLinearNegative(a, ArrayCount(a)));
	printf("OK\n");
	return 0;
}