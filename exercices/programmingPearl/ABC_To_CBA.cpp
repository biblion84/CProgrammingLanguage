#include <stdio.h>
void reverse(char *vec, int start, int end){
	int s, e;
	for (s = start, e = end; s < e; ++s, --e){
		char temp = vec[s];
		vec[s] = vec[e];
		vec[e] = temp;
	}
}

// To rotate a vector i position we do 3 reversal [0, i) [i, end) [0, end)
void rotateSolution(char *vec, int i, int end) {
	// Reverse [0, i)
	// Reverse [i, len)
	// Reverse [0, len)
	// That rotate the vector i place
	reverse(vec, 0, i - 1);
	reverse(vec, i, end - 1);
	reverse(vec, 0, end - 1);
	
}

// transform abc to cba
void solve(char *vec, int i, int j, int len){
	rotateSolution(vec, i, len);
	rotateSolution(vec + (len - i), j, i);
}

int main(){
	char vec[9] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '\0' };
	
	solve(vec, 5, 2, 8);
	printf("%s\n", vec);
}