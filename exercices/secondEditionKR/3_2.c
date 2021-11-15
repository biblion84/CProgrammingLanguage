#include <stdio.h>
#include "main.h"
#define MAXLINE 3000 /* maximum input line length */


void escape(char s[]) {
	
	char buffer[MAXLINE];
	int bufferIndex = 0;
	
	for (int i = 0; i < MAXLINE - 1 && s[i] != '\0'; i++) {
		switch (s[i]) {
			case '\t': {
				buffer[bufferIndex++] = '\\';
				buffer[bufferIndex++] = 't';
			} break;
			case '\n': {
				buffer[bufferIndex++] = '\\';
				buffer[bufferIndex++] = 'n';
			} break;
			default: {
				buffer[bufferIndex++] = s[i];
			}
		}
	}
	copy(s, buffer);
}


/* print the longest input line */
int main() {
	int len = 0; /* current line length */
	char line[MAXLINE]; /* current input line */
	while ((len = getlines(line, MAXLINE)) > 0) {
		escape(line);
		printf("%s\n", line);
	}
	return 0;
}
