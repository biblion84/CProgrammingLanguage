#include <stdio.h>
#include "main.h"

int any(char s[], const char del[]) {
	for (int i = 0; s[i] != '\0'; i++) {
		for (int j = 0; del[j] != '\0'; j++) {
			if (s[i] == del[j]) {
				return i;
			}
		}
	}
	return -1;
}


/* print the longest input line */
int main() {
	char source[] = "Hello I'm Lucas";
	char charToDel[] = "zrol";
	int index = any(source, charToDel);
	printf("%d", index);
	return 0;
}