#include <stdio.h>
#include <limits.h>
#include "main.h"

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
	int c, i;
	c = '\0';
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = (char)c;
	if (c == '\n')
		s[i++] = (char)c;
	s[i] = '\0';
	return i;
}

int rstrindex(char s[], char t[]) {
	int lens = 0;
	int lent = 0;
	
	for (lens = 0; s[lens] != '\0'; lens++); 
	for (lent = 0; t[lent] != '\0'; lent++);
	lens--; // -1 to offset, and thus remove the \n
	lent--;
	
	for (int i = lens; i > 0; i--) {
		printf("%d\n", i);
		int occurences = 0;
		int j, k;
		for (j = lent - 1, k = i; k> 0 && j > 0 && t[j] == s[k]; j--, k--) {
			occurences++;
		}
		if (occurences == (lent - 1)) {
			return k + 1;
		}
	}
	return -1;
}

/* print the longest input line */
int main() {
	char s[MAXLINE];
	char t[MAXLINE];
	getline(s, MAXLINE);
	getline(t, MAXLINE);
	int index = rstrindex(s, t);
	printf("index found : %d", index);
	return 0;
}
