#include <stdio.h>
#include "main.h"

void squeeze(char s[], const char del[]) {
	char buffer[3000];
	int bufferIndex = 0;
	
	for (int i = 0; s[i] != '\0'; i++) {
		int found = 0;
		
		for (int j = 0; del[j] != '\0'; j++) {
			if (s[i] == del[j]) {
				found = 1;
				break;
			}
		}
		
		if (!found) {
			buffer[bufferIndex++] = s[i];
		}
	}
	
	copy(s, buffer);
}


/* print the longest input line */
int main() {
	int len = 0; 
	char source[] = "Hello I'm Lucas";
	char charToDel[] = "l";
	squeeze(source, charToDel);
	printf("%s", source);
	return 0;
}