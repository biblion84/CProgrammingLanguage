#include <stdio.h>
#include <stdlib.h>

int len(char *s){
	int i;
	for (i = 0; s[i] != '\0'; ++i);
	return i;
}


int descend(char **slope, int slopeLen, int xStep, int yStep){
	int tree = 0;
	
	int x = 0;
	int l = len(slope[0]) - 1; // remove the \n
	for (int y = yStep; y < slopeLen; y += yStep) {
		x += xStep;
		x %= l;
		if (slope[y][x] == '#'){
			tree++;
		}
	}
	
	return tree;
}


int main(){
	FILE *f = fopen("input.txt", "r");
	
	char *s[1000];
	int sIndex = 0;
	
	for (int i = 0; i < 1000; i++){
		s[i] = (char *) malloc(300);
	}
	
	char buffer[300];
	while (fgets(buffer, 300, f)) {
		for (int i = 0; i < 300; i++){
			s[sIndex][i] = buffer[i];
		}
		sIndex++;
	}
	
	int x[] = { 1, 3, 5, 7, 1 };
	int y[] = { 1, 1, 1, 1, 2 };
	int total = 1;
	for (int i = 0; i < 5; i++){
		int tree = descend(s, sIndex, x[i], y[i]);
		total *= tree;
		printf("%d, x:%d, y;%d\n", tree, x[i], y[i]);
	}
	
	printf("Total : %d\n", total);
	
}