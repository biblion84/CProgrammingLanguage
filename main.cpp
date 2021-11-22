#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MB (1024*1024)

static char *memory;
static char *memoryIndex;

struct bag {
	char *color;
	
	char **bags;
};

char *getWords(char *s, char **result, int n) {

	*result = memoryIndex;

	for (int i = 0; i < n; i++){
		while (*s == ' ') s++;
		if (i != 0) *memoryIndex++ = ' ';
		for (; *s != '\0' && *s != ' '; s++){
			*memoryIndex++ = *s;
		}
	}
	*memoryIndex++ = '\0';
	return s;
}


char *getInt(char *s, int *result) {
	while (*s == ' ') s++;

	*result = *s - '0';
	s++;

	return s;
}

static char *stack[200];
static char **sp = stack;

void push(char *n) {
	*sp++ = n;
}

char* pop() {
	if (sp != stack) {
		return *--sp;
	} else {
		return 0;
	}
}
#define NUM_COLOR 1000

int main() {
	for (int i = 0; i < 200; i++){
		stack[i] = 0;
	}
	memory = (char *)malloc(1 * MB);
	memoryIndex = memory;
	FILE *f = fopen("input.txt", "r");
	char *temp;
	temp = (char *)malloc(300 * sizeof(char));

	bag bags[3000];
	for (int i = 0; i < 3000; i++) {
		bags[i] = {};
	}
	int bagIndex = 0;

	while (fgets(temp, 300, f)) {
		char *buf = 0;

		char *t = temp;
		bag p = {};
		p.bags = (char **)malloc(sizeof(char**)* NUM_COLOR);
		for (int i = 0; i < NUM_COLOR; i++){
			p.bags[i] = 0;
		}
		t = getWords(t, &p.color, 2);

		t = getWords(t, &buf, 2);
		while (true){
			int quantity;
			char *bagColor;
			t = getInt(t, &quantity);
			if (quantity > 9 || quantity < 0) {
				printf("BREAAK\n");
				
				break;
			}
			t = getWords(t, &bagColor, 2);
			printf("Adding %s\n", bagColor);
			for (int i = 0; i < NUM_COLOR; i++){
				if (p.bags[i] == 0){
					p.bags[i] = bagColor;
					break;
				}
			}
			t = getWords(t, &buf, 1);
		}

		bags[bagIndex++] = p;

		//if (p.lquantity && p.rquantity){
		//	printf("%s contains |%d| %s and |%d| %s\n", p.color, p.lquantity, p.lbag, p.rquantity, p.rbag);
		//} else if (p.lquantity) {
		//	printf("%s contains |%d| %s\n", p.color, p.lquantity, p.lbag);
		//} else if (p.rquantity) {
		//	printf("%s contains |%d| %s", p.color, p.rquantity, p.rbag);
		//}
	}
	//printf("%s\n", bags[bagIndex].color);
	//for (int i = 0; i < 30; i++){
	//	printf("%s\n", bags[i].color);
	//}
	char *colors[NUM_COLOR];
	for (int i = 0; i < NUM_COLOR; i++){
		colors[i] = (char *)malloc(100);
		for (int j = 0; j < 100; j++) {
			colors[i][j] = '\0';
		}
	}

	push("shiny gold");
	while (true) {
		char *toFind = pop();
		if (toFind == 0){
			break;
		}
		for (int i = 0; i < bagIndex; i++) {
			for (int b = 0; bags[i].bags[b] != 0; b++) {
				if (strcmp(bags[i].bags[b], toFind) == 0) {
					push(bags[i].color);

					bool found = false;
					for (int j = 0; j < NUM_COLOR; j++) {
						if (strcmp(colors[j], bags[i].color) == 0) {
							found = true;
						}
					}
					if (!found) {
						for (int j = 0; j < NUM_COLOR; j++) {
							if (colors[j][0] == '\0') {
								strcpy(colors[j], bags[i].color);
								break;
							}
						}
					}
					//printf("%s\n", bags[i].color);
				}
			}
		}
	}
	int j;
	for (j = 0; j < NUM_COLOR; j++){
		if (colors[j][0] == '\0'){
			break;
		}
		printf("%s\n", colors[j]);
	}
	printf("Total : %d", j);
}


#if 0

light red bags contain 1 bright white bag, 2 muted yellow bags.
dark orange bags contain 3 bright white bags, 4 muted yellow bags.
bright white bags contain 1 shiny gold bag.
muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.
shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.
dark olive bags contain 3 faded blue bags, 4 dotted black bags.
vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.
faded blue bags contain no other bags.
dotted black bags contain no other bags.


#endif