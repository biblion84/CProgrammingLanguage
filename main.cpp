#include <stdio.h>
#include <stdlib.h>

#define MB (1024 * 1024)
#define MAX_WORDS 400000

int len(char *s){
	int i;
	for (i = 0; s[i] != '\0'; ++i);
	return i;
}


struct canonicalString {
	char *original;
	char *canonical;
};

// bubble sort (fast enough)
void canonalize(char *s){
	bool cont = true;
	while(cont) {
		cont = false;
		for (int i = 0; s[i + 1] != '\0'; ++i){
			if (s[i] > s[i + 1]) {
				char temp = s[i];
				s[i] = s[i + 1];
				s[i + 1] = temp;
				cont = true;
			}
		}
	}
}
	

int main(int argc, char *argv[]) {
	FILE *f = fopen("words_alpha.txt", "r");

	printf("Start Allocating\n");
	char *memory = (char *)malloc(10 * MB);
	char *memoryIndex = memory;

	canonicalString *words = (canonicalString *)malloc(MAX_WORDS * sizeof(canonicalString));

	int wordIndex = 0;
	printf("End Allocating\n");
	
	printf("Start Loading\n");
	char word[30];
	while (fgets(word, 30, f)) {
		int l = len(word);
		words[wordIndex].original = memoryIndex;
		for (int i = 0; i < l + 1; i++){ // + 1 to get the last \0 in
			*memoryIndex++ = word[i];
		}
		canonalize(word);
		words[wordIndex++].canonical = memoryIndex;
		for (int i = 0; i < l + 1; i++){ // + 1 to get the last \0 in
			*memoryIndex++ = word[i];
		}
	}
	printf("%lld\n", memoryIndex - memory);
	printf("Stop Loading\n");
}