#include "main.h"
#define MAXWORD 100

struct tnode { /* the tree node: */
	char *word; /* points to the text */
	int line[MAXWORD]; /* lines of occurence */
	struct tnode *left; /* left child */
	struct tnode *right; /* right child */
};

#include <stdio.h>
#include <ctype.h>
#include <string.h>


struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
/* word frequency count */
int isAlphaNum(int);

int startWithMultiple(char *s, char c, int multiple) {
	for (int i = 0; i < multiple && s[i] != '\0'; i++) {
		if (s[i] != c) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
	char lineStorage[MAXLINE];
	root = NULL;
	int nline = 0;
	// Get one line from command line
	while (getline(lineStorage, MAXLINE) != EOF){
		++nline;
		char *pline = lineStorage;
		// Find the next word at each iteration
		while (*(pline = getWord(word, pline)) != '\0') { // we skip the last word, but oh well..
			if (isAlphaNum(word[0])) {
				root = addtree(root, word, nline);
			}
		}
	}
	
	treeprint(root);
	return 0;
}

void addIfNotFound(int *line, int nline) {
	int found = 0;
	for (int i = 0; i < MAXWORD; i++) {
		if (line[i] == nline) {
			printf("Found at index %d\n", i);
			found = 1;
			break;
		}
	}
	if (!found) {
		for (int i = 0; i < MAXWORD; i++) {
			if (line[i] == 0) { // Uninitialised
				printf("Not found, adding to index %d\n", i);
				line[i] = nline;
				break;
			}
		}
	}
}

struct tnode *talloc(void);
char *strsave(char *);
/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int nline)
{
	int cond;
	if (p == NULL) { /* a new word has arrived */
		p = talloc(); /* make a new node */
		for (int i = 0; i < MAXWORD; i++) { // Need initialisation to avoid garbage values
			p->line[i] = 0;
		}
		p->word = strsave(w);
		p->left = p->right = NULL;
		printf("Adding for : %s \t", w);
		addIfNotFound(p->line, nline);
	} else if ((cond = strcmp(w, p->word)) == 0){
		printf("Adding for : %s \t", w);
		addIfNotFound(p->line, nline);
	}
	else if (cond < 0) /* less than into left subtree */
		p->left = addtree(p->left, w, nline);
	else /* greater than into right subtree */
		p->right = addtree(p->right, w, nline);
	return p;
}

/* treeprint: in-order print of tree p */
// In orded means asc sorted
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%s \t lines:\n\t\t", p->word);
		for (int i = 0; p->line[i] != 0 && i < MAXLINE; i++) {
			printf("%3d ", p->line[i]);
		}
		putchar('\n');
		treeprint(p->right);
	}
}

#include <stdlib.h>
//talloc: make a tnode 
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strsave(char *s) /* make a duplicate of s */
{
	char *p;
	p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
	if (p != NULL)
		copy(p, s);
	return p;
}


