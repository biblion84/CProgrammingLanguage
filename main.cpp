#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 5



int charToInt(char *input) {
	unsigned int result;
	for (int i = 0; i < INPUT_SIZE; i++) {
		if (input[i] == '1') {
			result = (result | (1 << ((INPUT_SIZE - 1) - i)));
		}
	}
	return (int)result;
}

void cp(char *s, char *t) {
	while ((*s++ = *t++) != 0)
		;
}


int main(){


	FILE *f = fopen("input.txt", "r");
	char t[300];
	int result[INPUT_SIZE];
	char input[1000][INPUT_SIZE + 2]; // \n
	int inputIndex = 0;
	for (int i = 0; i < INPUT_SIZE; i++) {
		result[i] = 0;
	}
	int total = 0;
	while (fgets(t, 300, f)) {
		total++;
		cp(input[inputIndex++], t);
		for (int i = 0; i < INPUT_SIZE; i++) {
			if (t[i] == '1') {
				result[i] ++;
			}
		}
	}

	char msb[INPUT_SIZE + 1];
	char lsb[INPUT_SIZE + 1];
	int mean = total / 2;
	for (int i = 0; i < INPUT_SIZE; i++) {
		if (result[i] > mean) {
			msb[i] = '1';
			lsb[i] = '0';
		} else {
			msb[i] = '0';
			lsb[i] = '1';
		}
	}

	char found[INPUT_SIZE + 1];
	char subString[INPUT_SIZE + 1];
	char fileString[INPUT_SIZE + 1];

	int msbNumber = 0;
	for (int i = INPUT_SIZE; i > 0 && !msbNumber; i--){
		cp(subString, msb);
		subString[i] = '\0';
		for (int j = 0; j < 1000; j++){
			cp(fileString, input[j] );
			fileString[i] = '\0';
			if (strcmp(fileString, subString) == 0) {
				int currentNumber = charToInt(input[j]);
				printf("%d, %d\n", currentNumber, msbNumber);
				printf("%s\n", input[j]);
				if (currentNumber > msbNumber) {
					msbNumber = currentNumber;
					cp(found, input[j]);
				}
			}
		}
	}

	char foundLsb[INPUT_SIZE + 1];
	int lsbNumber = charToInt("111111111111");
	int sentinelValue = lsbNumber;
	for (int i = INPUT_SIZE; i > 0 && lsbNumber != sentinelValue; i--){
		cp(subString, lsb);
		subString[i] = '\0';
		for (int j = 0; j < 1000; j++){
			cp(fileString, input[j] );
			fileString[i] = '\0';
			if (strcmp(fileString, subString) == 0) {
				int currentNumber = charToInt(input[j]);
				if (currentNumber < lsbNumber) {
					lsbNumber = currentNumber;
					cp(foundLsb, input[j]);
				}
			}
		}
	}

	//unsigned int msbV = 0;
	//unsigned int lsbV = 0;
	//for (int i = 0; i < INPUT_SIZE; i++) {
	//	if (found[i] == '1') {
	//		msbV = (msbV | (1 << ((INPUT_SIZE - 1) - i)));
	//	}
	//	if (foundLsb[i] == '1') {
	//		lsbV = (lsbV | (1 << ((INPUT_SIZE - 1) - i)));
	//	}
	//}
	//


	//printf("%s = %d\n",  , msbNumber);
	//printf("lsb : %s = %d\n", foundLsb, lsbNumber);
	//printf("result : %d\n",  lsbNumber * msbNumber);

}
