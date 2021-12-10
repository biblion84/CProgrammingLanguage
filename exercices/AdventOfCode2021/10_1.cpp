#include <stdio.h>
#include <stdlib.h>
#include <string.h>


bool isClosing(char c) {
	return c == ')' || c == '}' || c == ']' || c == '>';
}

bool isOpening(char c) {
	return c == '(' || c == '{' || c == '[' || c == '<';
}

static char stack[200];
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
	while (fgets(buf, 300, f)) {
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
					break;
				}
			}
		}
	}
	printf("%d total \n", total);
	
	
}