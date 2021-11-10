#include "main.h"
struct tnode { /* the tree node: */
	char *word; /* points to the text */
	int count; /* number of occurrences */
	struct tnode *left; /* left child */
	struct tnode *right; /* right child */
};

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
/* word frequency count */
int isAlphaNum(int);

int main()
{
	struct tnode *root;
	char word[MAXWORD];
	root = NULL;
	while (getword(word, MAXWORD) != EOF){
		if (isAlphaNum(word[0])) {
			root = addtree(root, word);
		}
	}
		
	treeprint(root);
	return 0;
}

struct tnode *talloc(void);
char *strsave(char *);
/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	if (p == NULL) { /* a new word has arrived */
		p = talloc(); /* make a new node */
		p->word = strsave(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++; /* repeated word */
	else if (cond < 0) /* less than into left subtree */
		p->left = addtree(p->left, w);
	else /* greater than into right subtree */
		p->right = addtree(p->right, w);
	return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
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

int getCh();
void ungetCh(int);

// Get a word from the standard input
// Skip the whitespace and stop at the first blank character
int getword(char *s, int lim) 
{
	int c = '\0';
	int i = 0;

	// skip the whitespace
	while (isSpace(c = getCh()));
	// c must not be a whitespace, we add it back to the stack
	ungetCh(c);

	// we save everything to s as long as c is alpha
	for (i = 0; i < lim && isAlphaNum(c = getCh()); i++) {
		s[i] = (char)c;
	}
	s[i] = '\0';

	return c;
}

#define NO_CHAR -2 // smallest value should be EOF at -1
static int ch = NO_CHAR; 

int getCh() 
{
	int result;
	if (ch != NO_CHAR) { // smallest value should be EOF at -1
		result = ch;
		ch = NO_CHAR;
	} else {
		result = getchar();
	}
	return result;
}

void ungetCh(int c) 
{
	ch = c;
}

int isAlphaNum(int c) 
{
	return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

