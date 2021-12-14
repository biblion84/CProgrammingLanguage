#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

struct pair {
	char from[3];
	char to[2];
};

char getPair(pair *pairs, int pairsLen, char a, char b) {
	for (int i = 0; i < pairsLen; i++) {
		if (pairs[i].from[0] == a && pairs[i].from[1] == b) {
			return pairs[i].to[0];
		}
	}
	return '\0';
}

const int LEN = 100;

int main() {
	char *primary = (char *) malloc(10000 * sizeof(char));
	char *secondary = (char *) malloc(10000 * sizeof(char));
	for (int i = 0; i < 10000; i++) {
		primary[i] = '\0';
		secondary[i] = '\0';
	}
	strcpy(primary, "SNPVPFCPPKSBNSPSPSOF");

	FILE *f = fopen("input.txt", "r");
	char buffer[300] = {};

	pair pairs[LEN] = {};
	int pairIdx = 0;

	while (fgets(buffer, 300, f) != 0) {
		char *line = buffer;
		line = getWord(pairs[pairIdx].from, line);
		
		char temp[5];
		line = getWord(temp, line); // remove ->
		
		line = getWord(pairs[pairIdx].to, line);

		pairIdx++;
	}

	for (int step = 0; step < 10; step++) {
		int sIdx = 0;
		int i;
		for (i = 0; primary[i + 1] != '\0'; i++) {
			secondary[sIdx++] = primary[i];
			char c = getPair(pairs, LEN, primary[i], primary[i + 1]);
			if (c != '\0') {
				secondary[sIdx++] = c;
			}
		}
		secondary[sIdx++] = primary[i];
		secondary[sIdx++] = '\0';

		char *temp = primary;
		primary = secondary;
		secondary = temp;
	}
	printf("%s\n", primary);

	int occurences[26] = {};
	for (int i = 0; primary[i] != '\0'; i++) {
		occurences[primary[i] - 'A']++;
	}
	int most = 0;
	int least = 1  << 30;
	for (int i = 0; i < 26; i++) {
		if (occurences[i] == 0) {
			continue;
		}
		if (occurences[i] > most) {
			most = occurences[i];
		}
		if (occurences[i] < least) {
			least = occurences[i];
		}
	}
	printf("%d : %d\n", most, least);
	printf("result :  %d\n", most - least);

	//for (int i = 0; i < pairIdx; i++) {
	//	printf("-%s- -> -%s-\n", pairs[i].from, pairs[i].to);
	//}

	
	printf("\nOK\n");
}
