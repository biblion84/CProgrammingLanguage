#include <stdio.h>
#define ArrayCount(Array) (sizeof(Array) / sizeof((Array)[0]))


inline int ctoi(char s){
	if (s >= '0' && s <= '9'){
		return s - '0';
	}
	return 0;
}

int main(){
	FILE *f = fopen("template.txt", "r");
	char records[][10] = { "Lucas", "Bg", "25" };
	
	char line[200];
	char output[230];
	while (fgets(line, 200, f)){
		char *outputIndex = output;
		for (int i = 0; line[i] != '\0'; i++){
			if (line[i] == '$' && ctoi(line[i+1])){
				char *toAdd = records[ctoi(line[i + 1]) - 1];
				for (int j = 0; toAdd[j] != '\0'; j++){
					*(outputIndex++) = toAdd[j];
				}
				i++;
			} else {
				*(outputIndex++) = line[i];
			}
		}
		*outputIndex = '\0';
		printf("%s\n", output);
	}
	
}