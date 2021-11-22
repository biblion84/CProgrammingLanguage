#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len(char *s) {
	int i;
	for (i = 0; s[i] != '\0'; ++i);
	return i;
}

struct keyValue {
	char k[20];
	char v[20];
};

char *getKeyValue(char *s, keyValue *kv) {
	int i = 0;
	for (i = 0; s[i] != ':' && s[i] != '\0'; i++) {
		kv->k[i] = s[i];
	}
	kv->k[i] = '\0';
	
	i++;
	
	int j = 0;
	for (j = 0; s[i + j] != ' ' && s[i + j] != '\0'; j++) {
		kv->v[j] = s[i + j];
	}
	kv->v[j] = '\0';
	
	return s + i + j + 1; // skip next space too
}

int main() {
	FILE *f = fopen("input.txt", "r");
	
	char *s[300];
	int sIndex = 0;
	for (int i = 0; i < 300; i++) {
		s[i] = (char *)malloc(300);
	}
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			s[i][j] = '\0';
		}
	}
	
	char temp[300];
	int ssIndex = 0;
	while (fgets(temp, 300, f)) {
		if (temp[0] == '\n') {
			//printf("0\n");
			sIndex++;
			ssIndex = 0;
		} else {
			//printf("%d\n", sIndex);
			for (int i = 0; temp[i] != '\0' && temp[i] != '\n'; i++) {
				s[sIndex][ssIndex++] = temp[i];
			}
			s[sIndex][ssIndex++] = ' '; // let it breathe, add spaces
		}
	}
	sIndex++;
	
	int valid = 0;
	
	char *tofind[] = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid" };
	//int targetBitmap = 0;
	//for (int j = 0; j < 7; j++){
	//	targetBitmap |= (1 << j);
	//}
	
	char *eyeColor[] = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };
	
	for (int index = 0; index < sIndex; index++) {
		char *ss = s[index];
		int correct = 0;
		while (true) {
			keyValue kv = {};
			ss = getKeyValue(ss, &kv);
			//printf("%s %s\n", kv.k, kv.v);
			
			if (kv.k[0] == '\0') {
				break;
			}
			
			if (strcmp(kv.k, "byr") == 0) {
				int year = atoi(kv.v);
				if (year >= 1920 && year <= 2002) {
					correct++;
				}
			} else if (strcmp(kv.k, "iyr") == 0) {
				int year = atoi(kv.v);
				if (year >= 2010 && year <= 2020) {
					correct++;
				}
			} else if (strcmp(kv.k, "eyr") == 0) {
				int year = atoi(kv.v);
				if (year >= 2020 && year <= 2030) {
					correct++;
				}
			} else if (strcmp(kv.k, "hgt") == 0) {
				int l = len(kv.v);
				if (kv.v[l - 2] == 'c' && kv.v[l - 1] == 'm') {
					kv.v[l-2] = '\0';
					int height = atoi(kv.v);
					if (height >= 150 && height <= 193) {
						correct++;
					}
				} else if (kv.v[l - 2] == 'i' && kv.v[l - 1] == 'n') {
					kv.v[l-2] = '\0';
					int height = atoi(kv.v);
					if (height >= 59 && height <= 76) {
						correct++;
					}
				}
			} else if (strcmp(kv.k, "hcl") == 0) {
				if (kv.v[0] == '#') {
					int hexaCount = 0;
					int i;
					for (i = 1; kv.v[i] != '\0'; i++) {
						if ((kv.v[i] >= '0' && kv.v[i] <= '9') || (kv.v[i] >= 'a' && kv.v[i] <= 'z')) {
							hexaCount++;
						}
					}
					if (hexaCount == 6 && i == 7) { // i == 7 because we get the # 
						correct++;
					}
				}
			} else if (strcmp(kv.k, "ecl") == 0) {
				for (int i = 0; i < 7; i++) {
					if (strcmp(kv.v, eyeColor[i]) == 0) {
						correct++;
					}
				}
			} else if (strcmp(kv.k, "pid") == 0) {
				int numbers = 0;
				for (int i = 0; kv.v[i] != '\0'; i++) {
					if (kv.v[i] >= '0' && kv.v[i] <= '9') {
						numbers++;
					}
				}
				if (numbers == 9) {
					correct++;
				}
			}
		}
		if (correct == 7) {
			valid++;
		}
	}
	
	printf("Ok : %d\n", valid);
}

