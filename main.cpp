#include <stdio.h>


void rotate(char *vec, int i){
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


void rotateInPlace(char *vec, int i){
	int len = 8;
	int secIndex = 0;
	
	for (int j = 0; j < len; ++j){
		int index = j + i;
		if (index >= len){
			index = secIndex++;
		}
		// Maybe can't do that ? Are we overwriting the cursor ahead of us ? 
		char temp = vec[j];
		vec[j] = vec[secIndex];
		vec[secIndex] = temp;
	}
}


int main(int argc, char *argv[]) {
	char vec[9] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '\0' };
	int i = 3;

	rotateInPlace(vec, i);
	printf("%s\n", vec);
}