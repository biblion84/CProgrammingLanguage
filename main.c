#include "main.h"

struct nlist { /* table entry: */
	struct nlist *next; /* next entry in chain */
	char *name; /* defined name */
	char *defn; /* replacement text */
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s)
{
	return 4;
#if 0
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
		return hashval % HASHSIZE;
#endif
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
	{
		if (strCmp(s, np->name) == 0) {
			return np; /* found */
		}
	}

	return NULL; /* not found */
}

#include <stdlib.h>

char *strdup(char *s) /* make a duplicate of s */
{
	char *p;
	p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
	if (p != NULL)
		strCpy(p, s);
	return p;
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) { /* not found */
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval]; // Either null or the previous one
		hashtab[hashval] = np; // We put np at the top of the linked list
	} else /* already there */
		free((void *) np->defn); // We free it because we re malloc it just after
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}



int main(){
	install("ATA", "OTO");
	install("ITI", "UTU");
	struct nlist *p = lookup("ATA");
	printf("%s\n", p->defn);
	
	p = lookup("ITI");
	printf("%s\n", p->defn);
	printf("Ok\n");
	return 0;
}