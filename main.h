#if !defined(MAIN_H)

#define MAIN_H

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
#endif