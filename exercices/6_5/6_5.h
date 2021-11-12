#if !defined(MAIN_H)
#define MAXLINE 1000 /* maximum input line length */
#include <stdio.h>

// Return 1 if string are the same, 0 otherwise
int strCmp(char *s, char *t) {
	while (*s == *t && *s != '\0' && *t != '\0'){
		*++s;
		*++t;
	}
	return !(*s == *t);
}

void strCpy(char *to, char *from) {
	while ((*to++ = *from++) != '\0');
}

#define MAIN_H
#endif