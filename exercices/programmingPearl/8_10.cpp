#include <stdio.h>
#define ArrayCount(Array) ((int)(sizeof(Array) / sizeof((Array)[0])))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define MIN(A, B) ((B) > (A) ? (B) : (A))

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
int closestToZero(int a, int b){
	int absA = a;
	int absB = b;
	if (a < 0) {
		absA = -a; // We don't handle INT_MIN but who care ? 
	}
	if (b < 0) {
		absB = -b;
	}
	
	if (absA < absB){
		return a;
	} else {
		return b;
	}
	
}

int closestToZeroQuadratic(int *a, int len){ // can't use array count on a pointer. thus need len
	int maxSum = a[0];
	for (int i = 0; i < len; ++i){
		int sum = 0;
		for (int j = i; j < len; ++j){
			sum += a[j];
			maxSum = closestToZero(sum, maxSum);
		}
	}
	return maxSum;
}

int closestToZeroLog(int *a, int l, int h){
	if (l > h){
		return INT_MIN;
	} else if (l == h) {
		return a[l];
	}
	
	int pivot = (l + h) / 2;
	
	int sum, lsum, rsum;
	// find left max
	sum = a[pivot]; // [pivot, l]
	lsum = a[pivot];
	for (int i = pivot - 1; i >= l; i--){
		sum += a[i];
		lsum = closestToZero(lsum, sum);
	}
	
	// find right max
	sum = a[pivot + 1];
	rsum = a[pivot + 1];
	for (int i = pivot + 2; i <= h; i++){ // [pivot, h]
		sum += a[i];
		rsum = closestToZero(rsum, sum);
	}
	
	return closestToZero(rsum + lsum, closestToZero(closestToZeroLog(a, l, pivot),closestToZeroLog(a, pivot + 1, h))) ;
}


int closestToZeroLinear(int *a, int len) {
	int maxsofar = a[0];
	int maxendinghere = a[0];
	
	for (int i = 1; i < len; i++){
		maxendinghere = closestToZero(maxendinghere + a[i], a[i]);
		maxsofar = closestToZero(maxsofar, maxendinghere);
	}
	
	return maxsofar;
}


//void scaffolding(){
//	seed = 42;
//	int runs = 10;
//	int size = 100;
//
//	int a[100];
//	for (int i = 0; i < runs; i++){
//		for (int j = 0; j < size; j++) {
//			a[j] = (int)(random() % 200);
//			if (random() % 4) {
//				a[j] = -a[j];
//			}
//		}
//		int quadraticSolution = maxSumQuadraticNegative(a, size);
//		int logSolution = maxSumNlogNNegative(a, 0, size - 1);
//		int linearSolution = maxSumLinearNegative(a, size);
//		
//		printf("Quad %d, log %d, Linear %d\n", quadraticSolution, logSolution, linearSolution);
//	}
//}

int main(){
	//scaffolding();
	int a[] = {-33, -12, -11, -3, -100, 102 };
	//
	
	// the quadratics algorithm is working, the other are not
	printf("%d\n", closestToZeroQuadratic(a, ArrayCount(a)));
	printf("%d\n", closestToZeroLog(a, 0, ArrayCount(a) -1));
	printf("%d\n", closestToZeroLinear(a, ArrayCount(a)));
	//	printf("%d\n", maxSumNlogNNegative(a, 0, ArrayCount(a) - 1));
	//	printf("%d\n", maxSumLinearNegative(a, ArrayCount(a)));
	printf("OK\n");
	return 0;
}