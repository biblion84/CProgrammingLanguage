#include <stdio.h>



/* strcpy: copy t to s; pointer version 3 */
void cp(char *s, char *t) {
	while ((*s++ = *t++) != 0)
		;
}

void cat(char *s, char *t) {
	for (; *s != '\0'; s++);
	while ((*s++ = *t++) != 0);
}



int main() {
	char s[] = "Hello Baaaaaa";
	char e[] = "Hola.";
	cat(s, e);
	printf("%s", s);
	char pattern[] = "hello";
}