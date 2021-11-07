// NOTE : Maybe not working, need testing.
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

void entab(char s[]) {
	int tabSize = 4;
	char buffer[MAXLINE];
	int bufferIndex = 0;
	for (int i = 0; s[i] != '\0' && bufferIndex < MAXLINE - 1; i++) {
		if (s[i] == ' ') {
			int nextWordIndex;

			for (nextWordIndex = i;
					s[nextWordIndex] != '\0' && nextWordIndex < MAXLINE - 1;
					nextWordIndex++) 
			{
				if (s[nextWordIndex] != ' ') {
					break;
				}
			}

			int distance = nextWordIndex - i;

			for (int tab = 0; tab < (distance / 4) && bufferIndex < MAXLINE - 1; tab++) {
				buffer[bufferIndex++] = '\t';
			}
			for (int tab = 0; tab < (distance % 4) && bufferIndex < MAXLINE - 1; tab++) {
				buffer[bufferIndex++] = ' ';
			}
			i = nextWordIndex - 1;
		} else {
			buffer[bufferIndex++] = s[i];
		}
	}
	buffer[bufferIndex] = '\0';
	int i;
	for (i = 0; buffer[i] != '\0'; i++) {
		s[i] = buffer[i];
	}
	s[i] = '\0';
}

/* print the longest input line */
int main() {
	int len = 0; /* current line length */
	char line[MAXLINE]; /* current input line */
	while ((len = getline(line, MAXLINE)) > 0) {
		entab(line);
		printf("%s\n", line);
	}
	return 0;
}
