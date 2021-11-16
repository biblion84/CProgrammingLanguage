#include <stdio.h>
#include <stdlib.h>

void reverse(char *vec, int start, int end){
	int s, e;
	for (s = start, e = end; s < e; ++s, --e){
		char temp = vec[s];
		vec[s] = vec[e];
		vec[e] = temp;
	}
}

// To rotate a vector i position we do 3 reversal [0, i) [i, end) [0, end)
void rotateSolution(char *vec, int i, int len) {
	// Reverse [0, i)
	// Reverse [i, len)
	// Reverse [0, len)
	// That rotate the vector i place
	reverse(vec, 0, i - 1);
	reverse(vec, i, len - 1);
	reverse(vec, 0, len - 1);
	
}


int main(int argc, char *argv[]) {
	char vec[9] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '\0' };
	int i = 3;
	
	rotateSolution(vec, i, 8);
	printf("%s\n", vec);
}