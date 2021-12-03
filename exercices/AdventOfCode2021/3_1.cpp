#include <stdio.h>
#include <stdlib.h>

#define INPUT_SIZE 12

int main(){
	
	
	FILE *f = fopen("input.txt", "r");
	char t[300];
	int result[INPUT_SIZE];
	for (int i = 0; i < INPUT_SIZE; i++) {
		result[i] = 0;
	}
	int total = 0;
	while (fgets(t, 300, f)) {
		total++;
		for (int i = 0; i < INPUT_SIZE; i++) {
			if (t[i] == '1') {
				result[i] ++;
			}
		}
	}
	int mean = total / 2;
	unsigned int gamma = 0;
	unsigned int epsilon = 0;
	for (int i = 0; i < INPUT_SIZE; i++) {
		if (result[i] > mean) {
			gamma = (gamma | (1 << ((INPUT_SIZE - 1) - i)));
			printf("1");
		} else {
			printf("0");
			epsilon = (epsilon | (1 << ((INPUT_SIZE - 1) - i)));
		}
	}
	printf("\ngamma : %d \n epsilon %d\n", gamma, epsilon);
	printf("\n result %d\n", gamma * epsilon);
}
