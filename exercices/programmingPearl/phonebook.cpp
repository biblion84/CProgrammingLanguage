#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KB 1024

static char *memory;
static char *memoryIndex;
struct nameStruct {
	char *number;
	char *name;
};
int len(char *s){
	int i;
	for (i = 0; s[i] != '\0'; ++i);
	return i;
}

void reverse(char s[]){
	int i, j;
	int l = len(s);
	
	for (i = 0, j = l - 1; i < l / 2 ; i++,j--) {
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


char * getNumber(char *s){ // its overflowing.. And we need string to better compare
	char *result = memoryIndex;
	
	reverse(s);
	
	for (int i = 0; s[i] != '\0'; ++i) {
		char l = s[i];
		int r = 0;
		// Buttons on a phone
		if (l >= 'a' && l <= 'c'){
			r = 2;
		} else if (l >= 'd' && l <= 'f'){
			r = 3;
		} else if (l >= 'g' && l <= 'i'){
			r = 4;
		} else if (l >= 'j' && l <= 'l'){
			r = 5;
		} else if (l >= 'm' && l <= 'o'){
			r = 6;
		} else if (l >= 'p' && l <= 's'){
			r = 7;
		} else if (l >= 't' && l <= 'v'){
			r = 8;
		} else if (l >= 'w' && l <= 'z'){
			r = 9;
		}
		if (r > 0){
			*memoryIndex++ = (char)('0' + r);
		}
	}
	reverse(s);
	
	*memoryIndex++ = '\0';
	reverse(result);
	
	return result;
}


int partition(nameStruct *a, int low, int high){
	nameStruct pivot = a[low];
	
	int i = low - 1;
	
	for (int j = low; j <= high; j++){
		if (strcmp(a[j].number, pivot.number) <= 0){
			i++;
			nameStruct temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	
	return i;
	
}

void quicksort(nameStruct *a, int low, int high){
	if (low >= 0 && high >= 0 && low < high){
		int p = partition(a, low, high);
		
		quicksort(a, low, p - 1);
		quicksort(a, p + 1, high);
	}
}

inline bool isalpha(char c){
	return c >= 'a' && c <= 'z';
}

int compareSubstring(char *a, char *b, int endB){
	char temp = b[endB];
	b[endB] = '\0';
	int result = strcmp(a, b);
	b[endB] = temp;
	return result;
}

// What happen when the number is not found ? 
int buttonToNames(char *input, nameStruct *names, int lenNames, nameStruct **start){
	int startIndex = 0;
	int lenInput = len(input);
	
	for (startIndex = 0; startIndex < lenNames; ++startIndex){
		if (compareSubstring(input, names[startIndex].number, lenInput) == 0){
			break;
		}
	}
	
	int found = 0;
	for (int endIndex = startIndex; endIndex < lenNames; ++endIndex){
		if (compareSubstring(input, names[endIndex].number, lenInput) != 0){
			break;
		}
		found++;
	}
	
	*start = names + startIndex;
	return found;
	
}

int main() {
	
	memory = (char *)malloc(200 * KB);
	memoryIndex = memory;
	nameStruct *names = (nameStruct *)malloc(sizeof(nameStruct) * 2200);
	int namesIndex = 0;
	
	FILE *f = fopen("names.txt", "r");
	char name[100];
	while (fgets(name, 100, f)){
		int l = len(name);
		name[l - 1] = '\0'; // we remove the last \n
		
		bool notAlpha = false;
		for (int i = 0; name[i] != '\0'; ++i) {
			if (!isalpha(name[i])){
				notAlpha = true;
				break;
			}
		}
		if (notAlpha){
			continue;
		}
		
		
		names[namesIndex].number = getNumber(name);
		names[namesIndex++].name = memoryIndex;
		
		for (int i = 0; name[i] != '\0'; ++i){
			*memoryIndex++ = name[i];
		}
		*memoryIndex++ = '\0';
	}
	
	
	printf("Start of sorting\n");
	quicksort(names, 0, namesIndex - 1);
	printf("End of sorting\n");
	//for (int i = 0; i < namesIndex - 1; i++){
	//	if (strcmp(names[i].number, names[i + 1].number) == 0) {
	//		int j;
	//		printf("%s number is the same for :\n", names[i].number);
	//		for (j = 0; strcmp(names[i].number, names[i + j].number) == 0; j++){
	//			printf("\t%s\n", names[i + j].name);
	//		}
	//
	//	}
	//}
	
	nameStruct *start = 0;
	int matches = buttonToNames("5822", names, namesIndex, &start);
	printf("Matches found :\n");
	
	for (int i = 0; i < matches; i++){
		printf("%s (%s)\n", start[i].name, start[i].number);
	}
	
	
}