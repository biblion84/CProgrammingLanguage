#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

struct node {
	int value;
	int pathValue;
	node **children; // down and right are the only child node
};

struct fifoElem {
	fifoElem *next;
	int x;
	int y;
};

struct fifo {
	fifoElem *head;
	fifoElem *tail;
};

bool in(fifo *list, int x, int y) {
	fifoElem *p = list->head;
	while(p != 0){
		if (p->x == x && p->y == y) {
			return true;
		}
		p = p->next;
	}
	return false;
}

void add(fifo *list, int x, int y) {
	if (in(list, x,y)){ // do not add the same node
		return;
	}
	fifoElem *e = (fifoElem *)malloc(sizeof(fifoElem));
	e->x = x;
	e->y = y;
	e->next = 0;
	if (list->head == 0) {
		list->head = e;
		list->tail = e;
	} else {
		list->tail->next = e;
		list->tail = e;
	}
}

fifoElem *pop(fifo *list) {
	if (list->head == 0) {
		return 0;
	}
	fifoElem *e = list->head;
	list->head = e->next;
	return e;
}


#define LEN 100

int main() {
	FILE *f = fopen("input.txt", "r");
	char buffer[300] = {};

	int table[LEN][LEN] = {};
	{
		int y = 0;
		while (fgets(buffer, 300, f) != 0) {
			for (int x = 0; buffer[x] != '\0'; x++) {
				table[y][x] = buffer[x] - '0';
			}
			++y;
		}
	}

	for (int y = 0; y < LEN; y++) {
		for (int x = 0; x < LEN; x++) {
			printf("%d", table[y][x]);
		}
		printf("\n");
	}

	node *nodes = (node *)malloc(LEN * LEN * sizeof(node));
	for (int y = 0; y < LEN; y++) {
		for (int x = 0; x < LEN; x++) {
			nodes[y * LEN + x].children = (node **)malloc(2 * sizeof(node *));  // down and right are the only child node
		} 
	}
	
	// Populate every node
	for (int y = 0; y < LEN; y++) {
		for (int x = 0; x < LEN; x++) {
			nodes[y * LEN + x].value = table[y][x];
			nodes[y * LEN + x].pathValue = 0;
		}
	}
//
	//for (int y = 0; y < LEN; y++) {
	//	for (int x = 0; x < LEN; x++) {
	//		printf("%d", nodes[y * LEN + x].value);
	//	}
	//	printf("\n");
	//}
	// I could also not iterate multiple times to set values
	// But I wont

	// Set childrens
	for (int y = 0; y < LEN; y++) {
		for (int x = 0; x < LEN; x++) {
			int newX = x + 1;
			int newY = y + 1;
			if (newX < LEN) {
				nodes[y * LEN + x].children[0] = &nodes[y * LEN + newX];
			} else {
				nodes[y * LEN + x].children[0] = 0;
			}
			if (newY < LEN) {
				nodes[y * LEN + x].children[1] = &nodes[newY * LEN + x];
			} else {
				nodes[y * LEN + x].children[1] = 0;
			}
		}
	}

	fifo list;
	fifoElem first = {};
	first.x = LEN - 1;
	first.y = LEN - 1;
	list.head = &first;
	list.tail = &first;
	fifoElem *e;
	while ((e = pop(&list)) != 0 && !(e->x == 0 && e->y == 0)) {
		node *n = &nodes[e->y * LEN + e->x];

		int minPathValue = 1 << 30;
		if (n->children[0]) {
			minPathValue = n->children[0]->pathValue;
		}
		if (n->children[1]) {
			if (n->children[1]->pathValue < minPathValue) {
				minPathValue = n->children[1]->pathValue;
			}
		}
		if (minPathValue == (1 << 30)) {
			minPathValue = 0;
		}

		n->pathValue = minPathValue + n->value;
		int newX = e->x - 1;
		if (newX >= 0) {
			add(&list, newX, e->y);
		}
		int newY = e->y - 1;
		if (newY >= 0) {
			add(&list, e->x, newY);
		}
	}
	printf("min right = %d\n", nodes[0 * LEN + 1].pathValue);
	printf("min below = %d\n", nodes[1 * LEN + 0].pathValue);
	for (int y = 0; y < LEN; y++) {
		for (int x = 0; x < LEN; x++) {

			printf("%3d, ", nodes[y * LEN + x].pathValue);
		} 
		printf("\n");
	}
	printf("Ok\n");

}
