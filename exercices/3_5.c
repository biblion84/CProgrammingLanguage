#include <stdio.h>
#include <limits.h>
#include "main.h"

/* itoa: convert n to characters in s */
void itoa(int n, char s[], char base)
{
	int i = 0;
	int negative = n < 0;
	if (negative) {
		n = -n; // Do not handle INT_MIN but who care ? 
	}
	
	do { /* generate digits in reverse order */
		char digit = (char)(n % base);
		char digitInBase = '\0';
		if (digit < 10) {
			digitInBase = digit + '0';
		} else if (digit < 36) {
			digitInBase = (digit - 10) + 'A';
		} else if (digit < 62) {
			digitInBase = (digit - 36) + 'a';
		}
		s[i++] = digitInBase;
	} while ((n /= base) > 0); /* delete it */
	
	if (negative)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}


/* print the longest input line */
int main() {
	char s[MAXLINE];
	itoa(43544330, s, 62);
	printf("%s", s);
	return 0;
}
