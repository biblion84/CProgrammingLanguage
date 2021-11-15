#include <stdio.h>
#define MAXLINE 3000 /* maximum input line length */

/* getline: read a line into s, return length */
int getlines(char s[],int lim)
{
	int c = 0;
	int currentIndex = 0;
	int trailingBlanks = 0;
	for (int i = 0; (c = getchar()) != EOF; ++i) {
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

void removeComments(char s[]) {
	char buffer[MAXLINE];
	int bufferIndex = 0;
	int inBlockComment = 0;
	int inLineComment = 0;
	int inString = 0;
	int inDefine = 0;
	printf("Test String Commentaire // Test test test");
	
	for (int i = 0; i < MAXLINE - 2 && s[i] != '\0'; i++) {
		if (inLineComment) {
			if (s[i] == '\n') {
				inLineComment = 0;
			}
		} else if (inBlockComment) {
			if (s[i] == '*' && s[i + 1] == '/') {
				i++;
				inBlockComment = 0;
			}
		} else {
			if (inString || inDefine) {
				if (s[i] == '"') {
					inString = 0;
				}
				if (s[i] == '\n') {
					inString = 0;
					inDefine = 0;
				}
			}
			if (s[i] == '/' && s[i + 1] == '/' && !inString && !inDefine) {
				i++;
				inLineComment = 1;
			} else if (s[i] == '/' && s[i + 1] == '*') {
				i++;
				inBlockComment = 1;
			} else {
				if (s[i] == '#' && i > 0 && s[i-1] == '\n') {
					inDefine = 1;
				} else if (s[i] == '"') {
					inString = 1;
				}	
				buffer[bufferIndex++] = s[i];
			}
		}
	}
	
	int i;
	for (i = 0; buffer[i] != '\0' && i < MAXLINE; i++) {
		s[i] = buffer[i];
	}
	s[i] = '\0';
}

/* print the longest input line */
int main() {
	int len = 0; /* current line length */
	char line[MAXLINE]; /* current input line */
	while ((len = getlines(line, MAXLINE)) > 0) {
		removeComments(line);
		printf("%s\n", line);
	}
	return 0;
}
