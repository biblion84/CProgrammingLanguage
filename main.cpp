#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 5
#define FILE_SIZE 12




void cp(char *s, char *t) {
	while ((*s++ = *t++) != 0)
		;
}

int charToInt(char *input) {
	int result = 0;
	for (int i = 0; i < INPUT_SIZE; i++) {
		if (input[i] == '1') {
			result = (result | (1 << ((INPUT_SIZE - 1) - i)));
		}
	}
	return result;
}

int count(char **input) {
	int result = 0;
	for (int i = 0; i < FILE_SIZE; i++){
		if (input[i])
			result++;
	}
	return result;
}

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

	char msb[INPUT_SIZE + 1];
	char lsb[INPUT_SIZE + 1];
	int mean = total / 2;
	for (int i = 0; i < INPUT_SIZE; i++) {
		if (totalSet[i] >= mean) {
			msb[i] = '1';
			lsb[i] = '0';
		} else {
			msb[i] = '0';
			lsb[i] = '1';
		}
	}

	char *oxygen[FILE_SIZE];
	char *scrubber[FILE_SIZE];
	for (int i = 0; i < FILE_SIZE; i++){
		oxygen[i] = input[i];
		scrubber[i] = input[i];
	}

	char oxygenResult[INPUT_SIZE + 1];
	for (int i = 0; i < INPUT_SIZE ; i++) {
		int zero = 0;
		int one = 0;
		printf("for the %d number\n", i);
		for (int j = 0; j < FILE_SIZE; j++) {
			if (!oxygen[j]) continue;
			printf("%s \n", oxygen[j]);

			if (oxygen[j][i] == '1'){
				one++;
			} else {
				zero++;
			}
		}
		printf("\nXX 0:%d 1:%dXX\n", zero, one);
		char winner = one < zero ? '0' : '1';
		for (int j = 0; j < FILE_SIZE; j++) {
			if (!oxygen[j]) continue;

			if (oxygen[j][i] != winner){
				oxygen[j] = 0;
			}
		}
		oxygenResult[i] = winner;
		
	}

	oxygenResult[INPUT_SIZE] = '\0';
	scrubberResult[INPUT_SIZE] = '\0';
	printf("%s %d\n" , oxygenResult, charToInt(oxygenResult));
	printf("%s %d\n" , scrubberResult, charToInt(scrubberResult));

	
}


