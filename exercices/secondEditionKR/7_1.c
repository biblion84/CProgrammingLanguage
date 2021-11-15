#include <stdio.h>
#include <ctype.h>



int main(int argc, char *argv[]) {
	char *ls = argv[0];
	int len = 0;
	// Advance ls to last / position
	for (len = 0; argv[0][len] != '\0'; len++) {
		if (argv[0][len] == '/'){
			ls = argv[0] + len;
		}
	}
	char *pend = argv[0] + len;
	// if a / exist, advance ls by one to skip it
	if (ls < pend && ls != argv[0]) {
		ls++;
	}
	// add a \0 at the next '.' position in order to terminate the string
	for (int i = 0; *(ls + i) != '\0'; i++){
		if (*(ls + i) == '.'){
			*(ls + i) = '\0';
			break;
		}
	}
	// ls now contain the string of the program name
	
	int upper = 0;
	if (strcmp(ls, "upper") == 0) {
		upper = 1;
	}
	
	int c;
	while ((c = getchar()) != EOF) {
		if (upper) {
			putchar(toupper(c));
		} else {
			putchar(tolower(c));
		}
	}
}
