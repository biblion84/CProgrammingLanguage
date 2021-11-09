#include "main.h"

static int stack[200];
static int *sp = stack;

void push(int n) {
	*sp++ = n;
}

int pop() {
	return *--sp;
}

int isOperator(char c) {
	return c == '+' || c == '-' || c == '/' || c == '*' || c == '%';
}

int main(int argc, char *argv[]) {
	int value = 0;
	*argv++;
	while (--argc > 0) {
		if (isOperator(*argv[0])) {
			switch (*argv[0]) {
				case '+' : {
					push(pop() + pop());
				} break;
				case '*' : {
					push(pop() * pop());
				} break;
				case '/' : {
					int v = pop();
					push(pop() / v);
				} break;
				case '%' : {
					int v = pop();
					push(pop() % v);
				} break;
			}
		} else {
			push((int)atof(*argv));
		}
		*argv++;
	}
	
	printf("result : %d", pop());
}