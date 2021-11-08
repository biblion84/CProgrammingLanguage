#include <stdio.h>
#define MAXLINE 3000 /* maximum input line length */

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

int power(int a, int exp) {
	int result = 1;
	for (int i = 0; i < exp; i++) {
		result *= a;
	}
	return result;
}

int htoi(const char s[]) {
	if (!(s[0] == '0' && s[1] == 'x' || s[1] == 'X')) {
		return -1;
	}
	int len = 0;
	for ( len = 0; len < MAXLINE - 1 && s[len] != '\0'; len++);
	len-= 2; // Remove the \n and the \0
	
	int result = 0;
	for (int i = 0; len - i > 1; i++) {
		int index = len - i;
		int multiple = power(16, i);
		printf("XX %c\n", s[index]);
		if (s[index] >= '0' && s[index] <= '9') {
			result += multiple * (s[index] - '0');
		} else if (s[index] >= 'a' && s[index] <= 'f') {
			result += multiple * ((s[index] - 'a') + 10);
		} else if (s[index] >= 'A' && s[index] <= 'F') {
			result += multiple * ((s[index] - 'A') + 10);
		} else {
			return -1;
		}
	}
	return result;
	
}



/* print the longest input line */
int main() {
	int len = 0; 
	char line[MAXLINE];
	while ((len = getline(line, MAXLINE)) > 0) {
		int n = htoi(line);
		printf("%s = %3d\n", line, n);
	}
	return 0;
}