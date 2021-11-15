#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>

void *mycalloc(int n, size_t size) {
	size_t totalSize = n*size;
	void *result = malloc(totalSize);
	char *presult = (char*)result;
	for (int i = 0; i < totalSize; i++){
		*presult++ = 0;
	}
	return result;
}

int main(int argc, char *argv[]) {
	int *ints = (int*)mycalloc(100, sizeof(int));
	for (int i = 0; i < 100; i++){
		printf("%d\n", *(ints + i));
	}
}
