#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	node *next;
};


node *append(node *l, node *n) {
	n->next = l;
	return n;
}

void print(node *l) {
	printf("/////////////////////\n");
	while (l != 0) {
		printf("%d\n", l->value);
		l = l->next;
	}
	printf("/////////////////////\n");
}

node *newNode(int value) {
	node *n = (node *)malloc(sizeof(node));
	n->value = value;
	n->next = 0;
	return n;
}

// Does not keep the order
node *copy(node *l) {
	node *newN = newNode(l->value);
	l = l->next;
	while (l != 0) {
		newN = append(newN, newNode(l->value));
		l = l->next;
	}
	return newN;
}

node *merge(node *l, node *ll) {
	node *p = l;
	while (p->next != 0) {
		p = p->next;
	}
	p->next = ll;
	return l;
}

node *split(node *l, int where) {
	int i;
	
	for (i = 0; i < (where - 1) && l != 0; i++){
		l = l->next;
	}
	
	if (i == (where - 1)) {
		node *newN = l->next;
		l->next = 0;
		return newN;
	}
	return 0;
}

void insertAfter(node *l, node *toAdd, int valueAfter) {
	while (l != 0) {
		if (l->value == valueAfter) {
			toAdd->next = l->next;
			l->next = toAdd;
			break;
		}
		l = l->next;
	}
}

void insertBefore(node *l, node *toAdd, int valueBefore) {
	node *previous = l;
	while (l != 0) {
		if (l->value == valueBefore) {
			toAdd->next = previous->next;
			previous->next = toAdd;
			break;
		}
		previous = l;
		l = l->next;
	}
}


int main() {
	node *list = newNode(0);
	
	for (int i = 0; i < 10; i++) {
		node *n = newNode(i);
		list = append(list, n);
	}
	node *ll = copy(list);
	
	list = merge(list, ll);
	//print(list);
	node *s = split(list, 10);
	print(list);
	insertAfter(list, newNode(11), 5);
	print(list);
	insertBefore(list, newNode(22), 11);
	print(list);
}
