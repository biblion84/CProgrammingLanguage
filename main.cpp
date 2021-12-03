#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 12
#define FILE_SIZE 1000

int main(){
	//printf("\n\n%d\n",  charToInt("10111"));
	
	FILE *f = fopen("input.txt", "r");
	char t[300];
	int totalSet[INPUT_SIZE];

	char input[FILE_SIZE][INPUT_SIZE + 1]; // \n
	int inputIndex = 0;
	for (int i = 0; i < INPUT_SIZE; i++) {
		totalSet[i] = 0;
	}
	int total = 0;
	while (fgets(t, 300, f)) {
		total++;
		t[INPUT_SIZE] = '\0'; // remove \n
		strcpy(input[inputIndex], t);
		inputIndex++;
		for (int i = 0; i < INPUT_SIZE; i++) {
			if (t[i] == '1') {
				totalSet[i] ++;
			}
		}
	}
	
}


