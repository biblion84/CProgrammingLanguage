#include <stdio.h>

int atEnd(char *s, char *t) {
	int tLen;
	for (tLen = 0; *(t+tLen) != '\0'; tLen++);
	char *sEnd;
	for (sEnd = s; *sEnd != '\0'; sEnd++);
	for (char *start = sEnd - tLen; start >= s && start <= sEnd; start++) {
		if (*start != *t) {
			return 0;
		}
		t++;
	}
	return 1;
	
}


int main() {
	char s[] = "Hello BaaaaaaHla.";
	char e[] = "Hola.";
	
	printf("%d", atEnd(s, e));
}