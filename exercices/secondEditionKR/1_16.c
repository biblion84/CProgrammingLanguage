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
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}


/* print the longest input line */
int main() {
	int len; /* current line length */
	int max; /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here */
	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
		if (max > 0) { /* there was a line */
			printf("%s\n", longest);
			printf("size : %d", max);
		}
		return 0;
}
