#include <stdio.h>
#include <stdlib.h>
#include <string.h>


bool isClosing(char c) {
	return c == ')' || c == '}' || c == ']' || c == '>';
}

bool isOpening(char c) {
	return c == '(' || c == '{' || c == '[' || c == '<';
}

static char stack[200] = {};
static char *sp = stack;

void push(char n) {
	*sp++ = n;
}

char pop() {
	if (sp != stack) {
		return *--sp;
	} else {
		return 0;
	}
}

int partition(long long *a, int low, int high){
	long long pivot = a[high];
	
	int i = low - 1;
	
	for (int j = low; j <= high; ++j){
		if (a[j] <= pivot) {
			i++;
			long long temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	return i;
}

void quicksort(long long *a, int low, int high){
	if (low >= 0 && high >= 0 && low < high){
		int p = partition(a, low, high);
		
		quicksort(a, low, p - 1);
		quicksort(a, p + 1, high);
	}
}

char getClosing(char c) {
	switch (c) {
		case '(' :
			return ')';
		case '{' :
			return '}';
		case '[' :
			return ']';
		case '<':
			return '>';
	}
	return '\0';
}

int main() {
	FILE *f = fopen("input.txt", "r");
	char buf[300];
	int total = 0;
	long long scores[100] = {};
	int scoreIdx = 0;
	while (fgets(buf, 300, f)) {
		sp = stack; // reset the stack
		bool incomplete = false;
		for (char *c = buf; *c != '\0' && *c != '\n'; c++) {
			if (isOpening(*c)) {
				push(getClosing(*c));
			} else { // isClosing then
				char expected = pop();
				if (*c != expected) {
					if (*c == ')') {
						total += 3;
					} else if (*c == '}') {
						total += 57;
					} else if (*c == ']') {
						total += 1197;
					} else if (*c == '>') {
						total += 25137;
					}
					incomplete = true;
					break;
				}
			}
		}
		if (incomplete) {
			continue;
		}
		// That mean the line is correct but incomplete if we're here
		char c = 0;
		long long score = 0;
		while ((c = pop()) != 0) {
			long long before = score;
			score *= 5;
			if (score < before) {
				printf("OVERFLOW");
			}
			switch (c) {
				case ')': {
					score += 1;
				} break;
				case ']': {
					score += 2;
				} break;
				case '}': {
					score += 3;
				} break;
				case '>': {
					score += 4;
				} break;
			}
		}
		scores[scoreIdx++] = score;
	}
	
	quicksort(scores, 0, 99);
	for (int i = 0; i < 100; i++) {
		printf("%lld \n", scores[i]);
	}
	int middle = 100 - scoreIdx + (scoreIdx / 2);
	printf("MIDDLE %lld \n", scores[middle]);
	
	printf("%d total \n", total);
	
	
}