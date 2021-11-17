#include <stdio.h>
#define ArrayCount(Array) (sizeof(Array) / sizeof((Array)[0]))

int len(char *s){
	int i;
	for (i = 0; s[i] != '\0'; ++i);
	return i;
}

int lenWithoutHyphen(char *s){
	int result = 0;
	for (int i = 0; s[i] != '\0'; ++i){
		if (s[i] != '-') {
			++result;
		}
	}
	return result;
}

int main(){
	
	char hyphens[][10] = {
		"et-ic", "al-is-tic", "s-tic", "p-tic", "-lyt-ic",
		"ot-ic", "an-tic", "n-tic", "c-tic", "at-ic", "h-nic",
		"n-ic", "m-ic", "l-lic", "b-lic", "-clic", "l-ic",
		"h-ic", "f-ic", "d-ic", "-bic", "a-ic", "-mac", "i-ac"
	};
	for (int i = 0; i < ArrayCount(hyphens); i++){
		printf("%s\n", hyphens[i]);
	}
	
	char word[] = "ethnic";
	int l = len(word);
	
	char* h = 0;
	char *match = 0;
	for (int i = 0; i < ArrayCount(hyphens) && match == 0; i++){
		int lhyphen = lenWithoutHyphen(hyphens[i]);
		int startingIndex = l - lhyphen;
		
		if (startingIndex < 0) continue;
		
		bool found = true;
		
		for(int j = 0; hyphens[i][j] != '\0' && match == 0; j++){
			if (hyphens[i][j] != '-' && word[startingIndex++] != hyphens[i][j]){
				found = false;
				break;
			}
		}
		if (found) {
			match = hyphens[i];
		}
	}
	
	if (match) {
		printf("match found : %s\n", match);
	} else {
		printf("match not found\n");
	}
	
	return 0;
}