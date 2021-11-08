#include <stdio.h>
#include "main.h"

void expand(const char s[], char s2[]) {
	int i2 = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '-') {
			char start = s[i-1];
			char end = s[i + 1];
			for (char c = start + 1; c < end; c++) {
				s2[i2++] = c;
			}
		} else {
			s2[i2++] = s[i];
		}
	}
}

/* print the longest input line */
int main() {
	char s[] = "0-90-9";
	char s2[MAXLINE];
	expand(s, s2);
	printf("%s", s2);
	return 0;
}
