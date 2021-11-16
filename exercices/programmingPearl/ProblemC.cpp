#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int occurencesInFile[10]; // I don't have lseek on windows. Need to implement it.
	int bitmap;
	int occurence;
	node *next;
};

int getStringBitmap(char *word){ // only works on ASCII encoded word
	int result = 0;
	for (int i = 0; word[i] != '\0' &&  word[i] != '\n'; ++i){
		char shift = word[i] - 'a';
		result = result | (1 << shift);
	}
	//printf("Bitmap for %s : %d\n", word, result);
	return result;
}

#define LINES 400000
#define WORD_MAX 30
int main(int argc, char *argv[]) {
	FILE *f = fopen("words_alpha.txt", "r");
	char word[WORD_MAX];
	char *c = 0;
	int lineNumber = 1;
	printf("Start malloc\n");
	
	printf("Start of string allocation\n");
	char **words = (char **)malloc(sizeof(char*) * LINES);
	for (int i = 0; i < LINES; i++){
		words[i] = (char *)malloc(sizeof(char) * WORD_MAX);
		for(int j = 0; j < WORD_MAX; j++){
			words[i][j] = '\0';
		}
	}
	printf("End of string allocation\n");
	
	node *hashmap[2000];
	
	node *root = (node*) malloc(sizeof(node));
	c = fgets(word, WORD_MAX, f);
	root->occurencesInFile[0] = lineNumber;
	root->bitmap = getStringBitmap(word);
	root->next = 0;
	hashmap[root->bitmap % 2000] = root;
	
	printf("Start reading\n");
	
	for (int i = 0; word[i] != '\0'; i++){
		words[lineNumber-1][i] = word[i];
	}
	
	
	while ( (c = fgets(word, WORD_MAX, f)) != 0)
	{
		lineNumber++;
		for (int i = 0; word[i] != '\0'; i++){
			words[lineNumber-1][i] = word[i];
		}
		int bitmap = getStringBitmap(word);
		node *n = hashmap[bitmap%2000];
		for (int i = 0; i < 2000; i++){
			n = (node*) malloc(sizeof(node));
			
			for (int j = 0; j < 10; j++) n->occurencesInFile[j] = 0;
			
			n->occurence = 0;
			n->bitmap = 0;
			n->next = 0;
			hashmap[i] = n;
		}
		
		while(n != 0){
			if (n->bitmap == bitmap){
				break;
			}
			n = n->next;
		}
		
		if (n == 0){
			n = (node*) malloc(sizeof(node));
			for (int i = 0; i < 10; i++) n->occurencesInFile[i] = 0;
			n->occurencesInFile[0] = lineNumber;
			n->occurence = 1;
			n->bitmap = bitmap;
			n->next = hashmap[bitmap%2000];
			hashmap[bitmap%2000] = n;
		} else {
			n->occurence++;
			for (int i = 0; i < 10; i++) {
				if (n->occurencesInFile[i] == 0){
					n->occurencesInFile[i] = lineNumber;
					break;
				}
			}
		}
	}
	for (int i = 0; i < 2000; ++i) {
		node *n = hashmap[i];
		
		if (!n) continue;
		
		if (n->occurence > 0){
			printf("/////////\n");
			for (int j = 0; j < 10 && n->occurencesInFile[j] != 0; j++){
				printf("%s\n", words[n->occurencesInFile[j] - 1]);
			}
			printf("/////////\n");
		}
	}
	printf("Read ended\n");
}