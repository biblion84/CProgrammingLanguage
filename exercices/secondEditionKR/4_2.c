#include <stdio.h>
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

int isspace(int c) {
	return c == ' ' || c == '\t';
}

int isdigit(int c) {
	return c >= '0' && c <= '9';
}

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int i, sign;
	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
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
		for (int e = 0; isdigit(s[i]); i++,e++) {
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

/* print the longest input line */
int main() {
	char s[MAXLINE];
	getline(s, MAXLINE);
	double value = atof(s);
	printf("%s\t:\t%f", s, value);
	return 0;
}
