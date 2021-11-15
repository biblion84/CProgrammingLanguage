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

// TODO Almost works
void checkSyntax(char s[]) {
	int cBrace = 0;
	int cBracket = 0;
	int cParentheses = 0;
	int cQuote = 0;
	int cBlockComment = 0;
	
	int inString = 0;
	int inDefine = 0;
	
	for (int i = 0; i < MAXLINE && s[i] != '\0'; i++) {
		if ((s[i] == '"' ||s[i] == '\'') && i > 0 && s[i-1] != '\\') {
			if (inString) {
				inString = 0;
			} else {
				inString = 1;
			}
		}
		if (s[i] == '#' && i > 0 && s[i - 1] == '\n') {
			inDefine = 1;
		}
		if (s[i] == '\n' && inDefine) {
			inDefine = 0;
		}
		
		if (!inString && !inDefine) {
			if (s[i] == '{') {
				cBrace++;
			} else if (s[i] == '}') {
				cBrace--;
			} else if (s[i] == '[') {
				cBracket++;
			} else if (s[i] == ']') {
				cBracket--;
			} else if (s[i] == '(') {
				cParentheses++;
			} else if (s[i] == ')') {
				cParentheses--;
			} else if (s[i] == '\'') {
				cQuote++;
			} else if (s[i] == '/' && s[i + 1] == '*') {
				cBlockComment++;
			} else if (s[i] == '*' && s[i + 1] == '/') {
				cBlockComment--;
			}
		}
	}
	int errors = 0;
	if (inString) {
		errors++;
		printf("Quotes unbalanced\n");
	}
	if (cBrace > 0 || cBrace < 0) {
		errors++;
		printf("Braces unbalanced\n");
		printf("%d\n", cBrace);
	}
	if (cBracket > 0 || cBracket < 0) {
		errors++;
		printf("Brackets unbalanced\n");
	}
	if (cParentheses > 0 || cParentheses < 0) {
		errors++;
		printf("Parentheses unbalanced\n");
	}
	if (cBlockComment > 0 || cBlockComment < 0) {
		errors++;
		printf("Block Comments unbalanced\n");
	}
	if ((cQuote % 2) != 0) {
		errors++;
		printf("Quotes unbalanced\n");
	}
	if (errors == 0) {
		printf("All good\n");
	}
}

/* print the longest input line */
int main() {
	int len = 0; /* current line length */
	char line[MAXLINE]; /* current input line */
	while ((len = getlines(line, MAXLINE)) > 0) {
		removeComments(line);
		for (int i = 0; i < 100; i++) {
			putchar('\n');
		}
		checkSyntax(line);
	}
	return 0;
}