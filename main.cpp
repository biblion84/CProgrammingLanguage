#include <stdio.h>
#include <stdlib.h>


void rotate(char *vec, int i){ // using len(vec) * sizeof(int) extra bytes
	char cpvec[9];
	int secondaryIndex = 0;
	
	for (int j = 0; j < 8; ++j){
		int index = i + j;
		
		if (index >= 8) {
			index = secondaryIndex++;
		}
		
		cpvec[j] = vec[index];
	}
	cpvec[8] = '\0';
	
	for (int x = 0; x < 8; ++x){
		vec[x] = cpvec[x];
	}
}


void rotateInPlace(char *vec, int i){ // Only using i * sizeof(int) extra bytes
	int len = 8;
	char *tempVec = (char *)malloc(i * sizeof(int));
	for (int j = 0; j < i; ++j){
		tempVec[j] = vec[j];
	}
	
	for (int j = 0; j < len; ++j){
		int index = j + i;
		if (index >= len){
			break;
		}

		char temp = vec[j];
		vec[j] = vec[index];
		vec[index] = temp;
	}

	for (int j = 0; j < i; ++j){
		int index = (len - i) + j;
		vec[index] = tempVec[j];
	}
	free(tempVec);
}


int main(int argc, char *argv[]) {
	char vec[9] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '\0' };
	int i = 3;

	rotateInPlace(vec, i);
	printf("%s\n", vec);
}