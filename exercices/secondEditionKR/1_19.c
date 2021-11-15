#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

/* getline: read a line into s, return length */
int getline(char s[],int lim)
{
	int c = 0;
	int currentIndex = 0;
	int trailingBlanks = 0;
	for (int i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (currentIndex < lim-1) {
			s[currentIndex] = (char)c;
			currentIndex++;
			if (c == ' ' || c == '\t') {
				trailingBlanks++;
			} else {
				trailingBlanks = 0;
			}
		}
	}
	
	if (c == '\n') {
		s[currentIndex] = (char)c;
		++currentIndex;
	}
	
	s[currentIndex - trailingBlanks] = '\0';
	
	return currentIndex - trailingBlanks;
}

void reverse(char s[], int lim) {
	int end = 0;
	char buffer[MAXLINE];
	for (end = 0; end < lim && s[end] != '\0'; end++);
	
	if (end > 0) { // Remove the '\0'
		end--;
	}
	
	for (int i = 0; end-i >= 0; i++) {
		buffer[i] = s[end-i];
	}
	
	for (int i = 0; i <= end; i++) {
		s[i] = buffer[i];
	}
	s[end + 1] = '\0';
}

/* print the longest input line */
int main() {
	int len = 0; /* current line length */
	char line[MAXLINE]; /* current input line */
	while ((len = getline(line, MAXLINE)) > 0) {
		reverse(line, MAXLINE);
		printf("%s\n", line);
	}
	return 0;
}
