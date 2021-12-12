#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int CONNECTION_SIZE = 10;


//struct cave {
//	char *id;
//	cave **connections;
//};
//
//cave caves[100] = {};
//int cavesIdx = 0;
//
//cave *newcave(char *id) {
//	cave *n = &caves[cavesIdx++];
//	n->id = id;
//	n->connections = (cave **)malloc(sizeof(cave *) * CONNECTION_SIZE);
//	return n;
//}
//
//cave *find(char *id) {
//	for (int i = 0; i < 100 && caves[i].id != 0; i++) {
//		if (strcmp(caves[i].id, id) == 0) { 
//			return &caves[i];
//		}
//	}
//	return 0;
//}
//
// does not check for duplicates
//void addconnection(cave *from, cave *to) {
//	for (int i = 0; i < CONNECTION_SIZE; i++) {
//		if (from->connections[i] == 0) {
//			from->connections[i] = to;
//		}
//	}
//}


int isSpace(int c) {
	return c == ' ' || c == '\t';
}

int isAlphaNum(int c) 
{
	return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// return the line pointer pointed at the end of the word
char * getWord(char *word, char *line) {
	int c = '\0';
	
	while (isSpace((c = *line++)));
	
	char *wp = word;
	
	do {
		*wp++ = (char)c;
	} while (*line != EOF && *line != '\0' && isAlphaNum((c = *line++)));
	
	*wp = '\0';
	
	return line;
}

struct connection {
	char from[10];
	char to[10];
};
connection connections[100] = {};
int cIdx = 0;

int count(char *from) {
	int result = 0;
	for (int i = 0; i < cIdx; i++) {
		if (strcmp(connections[i].from, from) == 0) {
			result++;
		}
	}
	return result;
}

connection **find(char *from) {
	connection **result = (connection **)malloc(count(from) * sizeof(connection *));
	int rIdx = 0;
	for (int i = 0; i < cIdx; i++) {
		if (strcmp(connections[i].from, from) == 0) {
			result[rIdx++] = &connections[i];
		}
	}
	return result;
}


int main() {
	FILE *f = fopen("input.txt", "r");
	char buf[300];

	
	while (fgets(buf, 300, f)) {
		char *line = buf;
		connection c = connection{};
		line = getWord(c.from, line);
		line = getWord(c.to, line);
		connections[cIdx++] = c;
	}
	
	connection **startConnections = find("start");


	//for (int i = 0; i < cIdx; i++) {
	//	cave *n = find(connections[i].from);
	//	if (n == 0) {
	//		newcave(connections[i].from); // just create an entry with the cave
	//	}
	//}
//
	//for (int i = 0; i < cIdx; i++) {
	//	cave *from = find(connections[i].from);
	//	cave *to = find(connections[i].to);
	//	addconnection(from, to);
	//}
//
	//cave c = caves[0];
	//for (int i = 0; c.connections[i] != 0; i++) {
	//	printf("%s \n", c.connections[i]->id);
	//}

	//printf("from : %s to : %s\n", connections[i].from, connections[i].to); 
	printf("OK\n");
}
