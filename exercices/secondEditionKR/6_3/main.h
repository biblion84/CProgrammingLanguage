#if !defined(MAIN_H)
#define MAXLINE 1000 /* maximum input line length */
#include <stdio.h>

void copy(char to[], const char from[]) {
	int i;
	for (i = 0; from[i] != '\0'; i++) {
		to[i] = from[i];
	}
	to[i] = '\0';
}

/* getline: read everything into s, return length */
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

int isSpace(int c) {
	return c == ' ' || c == '\t';
}

int isDigit(int c) {
	return c >= '0' && c <= '9';
}

#define NO_CHAR -2 // smallest value should be EOF at -1
static int ch = NO_CHAR; 
int getCh() 
{
	int result;
	if (ch != NO_CHAR) { // smallest value should be EOF at -1
		result = ch;
		ch = NO_CHAR;
	} else {
		result = getchar();
	}
	return result;
}

void ungetCh(int c) 
{
	ch = c;
}

int isAlphaNum(int c) 
{
	return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}


/* getline: read a line into s, return EOF if found */
int getline(char *s,int lim)
{
	int c = '\0';
	while (isSpace(c = getCh()));
	ungetCh(c);
	int i;
	for (i = 0; i < lim && (c = getCh()) != EOF && c != '\n'; i++) {
		s[i] = (char)c;
	}
	s[i] = '\0';
	
	return c;
}

// populate word with the word found, Does NOT advance line because its
// a copy .. Duh;
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

int len(char *s){
	int i;
	for (i = 0; s[i] != '\0'; ++i);
	return i;
}

void reverse(char s[]){
	int i, j;
	int len = 0;
	for (len = 0; s[len] != '\0'; len++);
	
	for (i = 0, j = len - 1; i < len / 2 ; i++,j--) {
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	s[len] = '\n';
}

int power(int a, int exp) {
	int result = 1;
	for (int i = 0; i < exp; i++) {
		result *= a;
	}
	return result;
}

double dpower(double a, int exp) {
	double result = 1;
	for (int i = 0; i < exp; i++) {
		result *= a;
	}
	return result;
}



/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int i, sign;
	for (i = 0; isSpace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isDigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isDigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	
	double exponent = 1;
	
	if (s[i] == 'e') {
		i++;
		int negative = s[i] == '-';
		if (s[i] == '+' || s[i] == '-')
			i++;
		
		int exponentValue = 0;
		for (int e = 0; isDigit(s[i]); i++,e++) {
			exponentValue = 10 * e + (s[i] - '0');
		}
		printf("%d exponent value \n", exponentValue);
		exponent = dpower(10, exponentValue);
		if (negative) {
			exponent = 1 / exponent;
		}
	}
	val = sign * val / power;
	val = val * exponent;
	
	
	return val;
}

int atoI(char s[]) {
	return (int)atof(s);
}




#define MAIN_H
#endif