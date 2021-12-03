#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 5
#define FILE_SIZE 12



int charToInt(char *input) {
	int result;
	for (int i = 0; i < INPUT_SIZE; i++) {
		if (input[i] == '1') {
			result = (result | (1 << ((INPUT_SIZE - 1) - i)));
		}
	}
	return result;
}

void cp(char *s, char *t) {
	while ((*s++ = *t++) != 0)
		;
}


int main(){

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
		if (totalSet[i] > mean) {
			msb[i] = '1';
			lsb[i] = '0';
		} else {
			msb[i] = '0';
			lsb[i] = '1';
		}
	}

	
	//char found[INPUT_SIZE + 1];
	//char subString[INPUT_SIZE + 1];
	//char fileString[INPUT_SIZE + 1];
	//
	//int msbNumber = 0;
	//for (int i = INPUT_SIZE - 1; i > 0 && !msbNumber; i--){
	//	cp(subString, msb);
	//	subString[i] = '\0';
	//	for (int j = 0; j < FILE_SIZE; j++){
	//		cp(fileString, input[j] );
	//		fileString[i] = '\0';
	//		printf("Compare %s and %s\n", fileString, subString);
	//		if (strcmp(fileString, subString) == 0) {
	//			int currentNumber = charToInt(input[j]);
	//			printf("%d, %d\n", currentNumber, msbNumber);
	//			printf("%s\n", input[j]);
	//			if (currentNumber > msbNumber) {
	//				msbNumber = currentNumber;
	//				cp(found, input[j]);
	//			}
	//		}
	//	}
	//}

	//char lsbFound[INPUT_SIZE + 1];
	//
	//int lsbNumber = 1 << (INPUT_SIZE + 1);
	//int sentinel = lsbNumber;
	//for (int i = INPUT_SIZE - 1; i > 0 && lsbNumber != sentinel; i--){
	//	cp(subString, lsb);
	//	subString[i] = '\0';
	//	for (int j = 0; j < FILE_SIZE; j++){
	//		cp(fileString, input[j] );
	//		fileString[i] = '\0';
	//		printf("Compare %s and %s\n", fileString, subString);
	//		if (strcmp(fileString, subString) == 0) {
	//			int currentNumber = charToInt(input[j]);
	//			printf("%d, %d\n", currentNumber, lsbNumber);
	//			printf("%s\n", input[j]);
	//			if (currentNumber < lsbNumber) {
	//				lsbNumber = currentNumber;
	//				cp(lsbFound, input[j]);
	//			}
	//		}
	//	}
	//}
	
	printf("\n\n%d\n",  charToInt("10111"));
//
//	printf("\n%s = %d\n", found, msbNumber);
//	printf("\n%s = %d\n", lsbFound, lsbNumber);

}
