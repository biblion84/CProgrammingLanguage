#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

struct pair {
	char from[3];
	char to[2];
	long long count;
};

char getPair(pair *pairs, int pairsLen, char a, char b) {
	for (int i = 0; i < pairsLen; i++) {
		if (pairs[i].from[0] == a && pairs[i].from[1] == b) {
			return pairs[i].to[0];
		}
	}
	return '\0';
}

int index(pair *pairs, int pairsLen, char a, char b) {
	for (int i = 0; i < pairsLen; i++) {
		if (pairs[i].from[0] == a && pairs[i].from[1] == b) {
			return i;
		}
	}
	return -1;
}


const int LEN = 100;

int main() {
	
	char *primary = "SNPVPFCPPKSBNSPSPSOF";
	
	FILE *f = fopen("input.txt", "r");
	char buffer[300] = {};
	
	pair pairsPrimary[LEN] = {};
	long long pairsSecondary[LEN] = {};
	int pairIdx = 0;
	
	while (fgets(buffer, 300, f) != 0) {
		char *line = buffer;
		line = getWord(pairsPrimary[pairIdx].from, line);
		
		char temp[5];
		line = getWord(temp, line); // remove ->
		
		line = getWord(pairsPrimary[pairIdx].to, line);
		
		pairIdx++;
	}
	
	// 'A' to 'Z'
	int leftovers[26] = {};
	
	for (int i = 0; primary[i + 1] != '\0'; i++) {
		int idx = index(pairsPrimary, LEN, primary[i], primary[i + 1]);
		if (idx != -1) {
			pairsPrimary[idx].count++;
		}
	}
	
	
	for (int step = 0; step < 40; step++) {
		for (int i = 0; i < LEN; i++) {
			pairsSecondary[i] = 0; // reset
		}
		
		for (int i = 0; i < LEN; i++) {
			pair p = pairsPrimary[i];
			if (p.count > 0) {
				char addin = p.to[0];
				// example CH -> B
				
				// test for CB
				int idx = index(pairsPrimary, LEN, p.from[0], addin);
				if (idx != -1) {
					pairsSecondary[idx]+= p.count;
				} else {
					// leftover ? 
					printf("LEFTOVER\n");
				}
				
				// test for BH
				idx = index(pairsPrimary, LEN, addin, p.from[1]);
				if (idx != -1) {
					pairsSecondary[idx]+= p.count;
				} else {
					printf("LEFTOVER\n");
					// leftover ? 
				}
			}
		}
		for (int i = 0; i < LEN; i++) {
			pairsPrimary[i].count = pairsSecondary[i]; // reset
		}
	}
	
	long long count[26] = {};
	for (int i = 0; i < LEN; i++) {
		count[pairsPrimary[i].from[0] - 'A'] += pairsPrimary[i].count;
		count[pairsPrimary[i].from[1] - 'A'] += pairsPrimary[i].count;
		//count[pairsPrimary[i].to[0] - 'A'] += pairsPrimary[i].count;
		//printf("%s : %d\n", pairsPrimary[i].to, pairsPrimary[i].count);
	}
	for (int i = 0; i < 26; i++) {
		count[i] = count[i] / 2;
		//printf("%s : %d\n", pairsPrimary[i].to, pairsPrimary[i].count);
	}
	count[primary[0] - 'A']++; // add to first and last as they're not counted twice.
	count[primary[len(primary) - 1] - 'A']++; // add to first and last as they're not counted twice.
	
	for (int i = 0; i < 26; i++) {
		printf("%c : %lld\n", 'A' + i, count[i]);
	}
	
	long long most = 0;
	long long least = 0xFFFFFFFFFFFFFF;
	for (int i = 0; i < 26; i++) {
		if (count[i] == 0) {
			continue;
		}
		if (count[i] > most) {
			most = count[i];
		}
		if (count[i] < least) {
			least = count[i];
		}
	}
	printf("most : %lld, least : %lld\n", most, least);
	printf("result %lld\n", most- least);
	
	
	printf("\nOK\n");
}
