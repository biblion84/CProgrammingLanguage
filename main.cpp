#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	FILE *f = fopen("input.txt", "r");
	
	char *s[3000];
	int sIndex = 0;
	for (int i = 0; i < 3000; i++){
		s[i] = (char *)malloc(300);
	}

	for (int i = 0; i < 3000; i++) {
		for (int j = 0; j < 300; j++) {
			s[i][j] = '\0';
		}
	}

	int ssIndex = 0;
	char temp[300];

	while (fgets(temp, 300, f)) {
		if (temp[0] == '\n'){
			sIndex++;
			ssIndex = 0;
		} else {
			for (int i = 0; temp[i] != '\0' && temp[i] != '\n'; i++){
				s[sIndex][ssIndex++] = temp[i];
			}
		}
	}

	long long total = 0;
	for (int i = 0; i < sIndex + 1; i++){
		int result = 0;
		for(int c = 0; c < 26; c++){
			char ch = (char)('a' + c);
			for (int j = 0; s[i][j] != '\0'; j++){
				if (s[i][j] == ch){
					result++;
					break;
				}
			}
		}
		total += result;
		printf("%s : %d\n", s[i], result);
	}

	printf("TOTAL :%lld\n", total);
		
}
