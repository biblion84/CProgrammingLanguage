#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// bubble sort (fast enough) average O(n²) but the arrays are always small ( < 10)
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


// Quicksort is pretty bad in this scenario, because the array is already almost sorted
int partition(canonicalString *a, int low, int high){
	canonicalString pivot = a[high];

	int i = low - 1;

	for (int j = low; j <= high; ++j){
		if (strcmp(a[j].canonical, pivot.canonical) <= 0) {
			i++;
			canonicalString temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	return i;
}

void quicksort(canonicalString *a, int low, int high){
	if (low >= 0 && high >= 0 && low < high){
		int p = partition(a, low, high);

		quicksort(a, low, p - 1);
		quicksort(a, p + 1, high);


	}
}


int compare(const void *a, const void *b){
	canonicalString *aa = (canonicalString*)a;
	canonicalString *bb= (canonicalString*)b;
	return strcmp(aa->canonical, bb->canonical);
}

int main(int argc, char *argv[]) {
	printf("%d\n", strcmp("a", "b"));
	
	printf("%d\n", strcmp("acehillnnsttuyy", "deinrssux"));
	FILE *f = fopen("words_alpha.txt", "r");

	printf("Start Allocating\n");
	char *memory = (char *)malloc(10 * MB);
	for (int i = 0; i < 10 * MB; ++i){
		memory[i] = '\0';
	}
	char *memoryIndex = memory;

	canonicalString *words = (canonicalString *)malloc(MAX_WORDS * sizeof(canonicalString));

	int wordIndex = 0;
	printf("End Allocating\n");
	
	printf("Start Loading\n");
	char word[30];
	while (fgets(word, 30, f)) {
		int l = len(word);
		word[l - 1] = '\0'; // remove the last \n
		words[wordIndex].original = memoryIndex;

		for (int i = 0; i < l; i++){ // + 1 to get the last \0 in
			*memoryIndex++ = word[i];
		}
		canonalize(word);
		words[wordIndex++].canonical = memoryIndex;
		for (int i = 0; i < l; i++){ // + 1 to get the last \0 in
			*memoryIndex++ = word[i];
		}
	}
	//for (int i = 00000; i < wordIndex - 1; i++){
	//	printf("original %30s, canonalized %30s \n", words[i].original, words[i].canonical);
	//}
	printf("Start sorting\n");
	quicksort(words, 0, wordIndex - 1);
	printf("End sorting\n");

	FILE *anagrams = fopen("anagrams.txt", "w");
	char printChar[200];
	for (int i = 0 ; i < wordIndex - 1; i++){
		if (strcmp(words[i].canonical, words[i + 1].canonical) == 0) {
			sprintf(printChar,"\n\n%s\n%s", words[i].original, words[i + 1].original);
			fputs(printChar, anagrams);
			
			for (int j = 2; j < 1000 && i + j < wordIndex; j++){
				if (strcmp(words[i].canonical, words[i + j].canonical) == 0) {
					sprintf(printChar,"\n%s", words[i + j].original);
					fputs(printChar, anagrams);
					
				} else {
					i = i + j;
					break;
				}
			}
		}
	}

	FILE *out = fopen("out.txt", "w");
	for (int i = 0 ; i < wordIndex; i++){
		fputs(words[i].canonical, out);
		fputs(",", out);
		fputs(words[i].original, out);
		fputc('\n', out);
	}


	printf("%lld\n", memoryIndex - memory);
	printf("Stop Loading\n");
}