#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

/* getline: read a line into s, return length */
int getline(char s[],int lim)
{
	int c = 0;
	int i;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim-1) {
			s[i] = (char)c;
		}
	}
	if (c == '\n') {
		s[i] = (char)c;
		++i;
	}
	if (i < lim - 1) {
		s[i] = '\0';
	} else {
		s[lim - 1] = '\0';
	}
	return i;
}

/* print the longest input line */
int main() {
	int len = 0; /* current line length */
	char line[MAXLINE]; /* current input line */
	while ((len = getline(line, MAXLINE)) > 0) {
		if (len > 80) {
			printf("%s\n", line);
		}
	}
	return 0;
}
