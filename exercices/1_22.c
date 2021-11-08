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

// TODO(lucas) : debug this
void fold(char s[]) {
	char buffer[MAXLINE];
	int bufferIndex = 0;
	int maxLine = 80;
	int currentLine = 0;
	for (int i = 0; s[i] != '\0' && i < MAXLINE - 1; i++) {
		currentLine++;
		if (currentLine > maxLine) {
			int pWhiteDist;
			for (pWhiteDist = 0; pWhiteDist < i && pWhiteDist < maxLine; pWhiteDist++) {
				int index = i - pWhiteDist;
				if (s[index] == ' ') {
					break;
				}
			}
			if (pWhiteDist < i) {
				buffer[bufferIndex - pWhiteDist] = '\n';
			} else {
				buffer[bufferIndex] = '\n';
				buffer[++bufferIndex] = '\t';
				buffer[++bufferIndex] = s[i];
			}
			currentLine = 0;
		} else {
			buffer[bufferIndex++] = s[i];
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
	while ((len = getline(line, MAXLINE)) > 0) {
		fold(line);
		printf("%s\n", line);
	}
	return 0;
}
