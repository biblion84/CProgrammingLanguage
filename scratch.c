#include "main.h"

static int stack[200];
static int *sp = stack;

void push(int n) {
	*(sp++) = n;
}

int pop() {
	return *(sp--);
}

int isOperator(char c) {
	return c == '+' || c == '-' || c == '/' || c == '*' || c == '%';
}

int main(int argc, char *argv[]) {
	/*	int value = 0;
	*argv++;
	while (--argc > 0) {
	printf("%s", *argv);
	if (isOperator(*argv[0])) {
	switch (*argv[0]) {
	case '+' : {
	value = pop() + pop();
	} break;
	}
	} else {
	push((int)atof(*argv));
	}
	*argv++;
	}*/
	for (int i = 1; i < 101; i++) {
		push(i);
	}
	int value = 0;
	for (int i = 1; i < 101; i++) {
		value += pop();
	}
	
	printf("value : %d\n", value);
	
	int v = 0;
	for (int i = 1; i < 101; i++) {
		v += i;
	}
	printf("value2 : %d\n", v);
	
	
	
	
}