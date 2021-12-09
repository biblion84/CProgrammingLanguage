#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isAlphaNum(int c) 
{
	return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isSpace(int c) {
	return c == ' ' || c == '\t';
}

int len(char *s){
	int i;
	for (i = 0; s[i] != '\0'; ++i);
	return i;
}

char * getWord(char *word, char *line) {
	int c = '\0';
	
	while (isSpace((c = *line++)));
	
	char *wp = word;
	
	do {
		*wp++ = (char)c;
	} while (*line != EOF && *line != '\0' && isAlphaNum((c = *line++)));
	
	*wp = '\0';
	
	return line;
}

char *findOfLen(int searchLen, char **a, int alen) {
	for (int i = 0; i < alen; i++) {
		if (len(a[i]) == searchLen) {
			return a[i];
		}
	}
	return 0;
}


// Return the first string that contains each of the "contained" char.
char* contains(char **candidates, int candidatesLen, int searchLen, char *contained) {
	char *result = 0;
	for (int i = 0; i < candidatesLen; i++) {
		char *candidate = candidates[i];
		if (len(candidate) != searchLen) {
			continue;
		}
		int similarities = 0;
		for (char *c = contained; *c != '\0'; c++){
			bool found = false;
			for (char *f = candidates[i]; *f != '\0'; f++) {
				if (*c == *f) {
					found = true;
					break;
				}
			}
			if (found) {
				similarities++;
			}
		}
		if (similarities == len(contained)){
			result = candidates[i];
		}
	}
	return result;
}

// Return the first string that contains each of the "contained" char.
char* isContained(char **candidates, int candidatesLen, int searchLen, char *contains) {
	char *result = 0;
	for (int i = 0; i < candidatesLen; i++) {
		char *candidate = candidates[i];
		if (len(candidate) != searchLen) {
			continue;
		}
		int similarities = 0;
		for (char *c = contains; *c != '\0'; c++){
			bool found = false;
			for (char *f = candidates[i]; *f != '\0'; f++) {
				if (*c == *f) {
					found = true;
					break;
				}
			}
			if (found) {
				similarities++;
			}
		}
		if (similarities == searchLen){
			result = candidates[i];
		}
	}
	return result;
}

bool equal(char *a, char *b) {
	if (len(a) != len(b)){
		return false;
	}
	for (char *aa = a; *aa != '\0'; aa++){
		bool found = false;
		for (char *bb = b; *bb != '\0'; bb++) {
			if (*bb == *aa) {
				found = true;
				break;
			}
		}
		if (!found) {
			return false;
		}
	}
	return true;
}

#define INPUT_SIZE 10

int main() {
	
	FILE *f = fopen("input.txt", "r");
	char buf[300];
	
	int count = 0;
	int result = 0;
	while (fgets(buf, 300, f)) {
		char *line = buf;
		char w[10];
		bool secondPart = false;
		char **input = (char **)malloc(INPUT_SIZE * sizeof(char*));
		for (int i = 0; i < INPUT_SIZE; i++) {
			input[i] = (char *)malloc(INPUT_SIZE * sizeof(char));
		}
		int inputIdx = 0;
		
		// left part
		while (isAlphaNum(line[0])) { // till '|'
			line = getWord(w, line);
			strcpy(input[inputIdx++], w);
			//printf("-%s-\n", w);
		}
		char output[4][10] = {};
		int outputIdx = 0;
		line = getWord(w, line); // remove the '|'
		
		// right part
		while (isAlphaNum(line[0])) {
			line = getWord(w, line);
			if (len(w) == 2 || len(w) == 3 || len(w) == 4 || len(w) == 7) {
				count++;
			}
			strcpy(output[outputIdx++], w);
			//printf("-%s-\n", w);
		}
		
		char *one = findOfLen(2, input, INPUT_SIZE);
		char *four = findOfLen(4, input, INPUT_SIZE);
		char *seven = findOfLen(3, input, INPUT_SIZE);
		char *eight = findOfLen(7, input, INPUT_SIZE);
		
		int lenNine = 6;
		char *nine = contains(input, INPUT_SIZE, lenNine, four);
		
		// Remove nine from the pool
		char **left = (char **)malloc((INPUT_SIZE - 1)* sizeof(char *));
		int leftIdx = 0;
		for (int i = 0; i < INPUT_SIZE; i++) {
			if (strcmp(nine, input[i]) != 0){
				left[leftIdx++] = input[i];
			}
		}
		
		int lenZero = 6;
		char *zero = contains(left, INPUT_SIZE - 1, lenZero, one);
		
		// Six is the only value left with a len 6 that is not nine or zero
		char *six = 0;
		int lenSix = 6;
		for (int i = 0; i < INPUT_SIZE; i++) {
			if (len(input[i]) == lenSix){
				if (strcmp(input[i], nine) != 0 && strcmp(input[i], zero) != 0) {
					six = input[i];
					break;
				}
			}
		}
		
		int lenThree = 5;
		char *three = contains(input, INPUT_SIZE, lenThree, one);
		
		int lenFive = 5;
		char *five = isContained(input, INPUT_SIZE, lenFive, six);
		
		int lenTwo = 5;
		char *two = 0;
		for (int i = 0; i < INPUT_SIZE; i++) {
			if (len(input[i]) == lenTwo){
				if (strcmp(input[i], three) != 0 && strcmp(input[i], five) != 0) {
					two = input[i];
					break;
				}
			}
		}
		
		char *inOrder[] = { zero, one, two, three, four, five, six, seven, eight, nine };
		int power = 1;
		int number = 0;
		for (int i = 3; i >= 0; i--){
			for (int j = 0; j < INPUT_SIZE; j++){
				//printf("Comparing -%s- and -%s-\n", output[i], inOrder[j]);
				if (equal(output[i], inOrder[j])) {
					//printf("FOUND!!!\n");
					number += j * power;
					power *= 10;
					break;
				}
			}
		}
		result += number;
		printf("%d number\n", number);
		
	}
	printf("%d\n", result);
	
	
	
	
}






