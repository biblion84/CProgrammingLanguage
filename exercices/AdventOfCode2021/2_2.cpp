#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isSpace(int c) {
	return c == ' ' || c == '\t';
}

int isAlphaNum(int c) 
{
	return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// return the line pointer pointed at the end of the word
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

	char direction[30];
	char value[30];
	int intValue;
	char line[300];

	int hor = 0;
	int ver = 0;
	int aim = 0;
	while (fgets(line, 300, f)) {
		char *nextWord = getWord(direction, line);
		getWord(value, nextWord);
		intValue = atoi(value);

		if (strcmp(direction, "forward") == 0) {
			hor += intValue;
			ver += intValue * aim;
		} else if (strcmp(direction, "up") == 0) {
			aim -= intValue;
			
		} else if (strcmp(direction, "down") == 0) {
			aim += intValue;
		}
	}

	printf("hor %d, ver %d, result %d\n", hor, ver, ver * hor);
}
