#include <stdio.h>

int isAlpha(int c) {
	return !(c == ' ' || c == '\t' || c == ' ' || c == '\n');
}

#define MAX_LENGTH 26

int main() {
	int characters[MAX_LENGTH];
	for (int i = 0; i < MAX_LENGTH; i++) {
		characters[i] = 0;
	}
	
	
	int c;
	int total = 0;
	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z') {
			characters[c - 'a']++;
			total++;
		}
	}
	for (int i = 0; i < MAX_LENGTH; i++) {
		putchar(i + 'a');
		putchar(':');
		putchar('\t');
		float frequency = ((float)characters[i] / (float)total) * 100.0f;
		for (int wl = 0; wl < frequency; wl++) {
			putchar('|');
		}
		for (int j = 20 - (int)frequency; j >= 0; j--) {
			putchar(' ');
		}
		printf("%3.2f%%", frequency);
		putchar('\n');
	}
}