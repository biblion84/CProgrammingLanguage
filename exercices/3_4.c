#include <stdio.h>
#include <limits.h>
#include "main.h"

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

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
	int i = 0;
	int negative = n < 0;
	
	do { /* generate digits in reverse order */
		if (negative) {
			s[i++] = -(n % 10) + '0'; /* get next digit */
		} else {
			s[i++] = n % 10 + '0'; /* get next digit */
		}
	} while (negative ? (n /= 10) < 0 : (n /= 10) > 0); /* delete it */
	if (negative)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}


/* print the longest input line */
int main() {
	char s[MAXLINE];
	itoa(INT_MIN, s);
	printf("%s", s);
	return 0;
}
