#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isAlphaNum(int c) 
{
	return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isSpace(int c) {
	return c == ' ' || c == '\t';
}

int len(char *s){
	int i;
	for (i = 0; s[i] != '\0'; ++i);
	return i;
}

char * getWord(char *word, char *line) {
	int c = '\0';
	
	while (isSpace((c = *line++)));
	
	char *wp = word;
	
	do {
		*wp++ = (char)c;
	} while (*line != EOF && *line != '\0' && isAlphaNum((c = *line++)));
	
	*wp = '\0';
	
	return line;
}

int main() {
	
	FILE *f = fopen("input.txt", "r");
	char buf[300];
	
	int count = 0;
	
	while (fgets(buf, 300, f)) {
		char *line = buf;
		char w[20];
		bool secondPart = false;
		// left part
		while( isAlphaNum(line[0])) { // till '|'
			line = getWord(w, line);
			//printf("-%s-\n", w);
		}
		line = getWord(w, line); // remove the '|'
		// right part
		while( isAlphaNum(line[0])) {
			line = getWord(w, line);
			if (len(w) == 2 || len(w) == 3 || len(w) == 4 || len(w) == 7) {
				count++;
			}
			printf("-%s-\n", w);
		}
	}
	
	
	
	printf("%d\n", count);
	
	
	
	
}






