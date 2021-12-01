#include <stdio.h>
#include <stdlib.h>

int main() {
	
	FILE *f = fopen("input.txt", "r");
	
	char temp[300];
	int depths[2000];
	int depthIndex = 0;
	
	while (fgets(temp, 300, f)) {
		int current = atoi(temp);
		depths[depthIndex++] = current;
	}
	
	int increment = 0;
	for (int i = 0; i + 3 < 2000; i++){
		int current = depths[i] + depths[i + 1] + depths[i + 2];
		int next = depths[i + 1] + depths[i + 2] + depths[i + 3];
		if (next > current) {
			increment++;
		}
	}
	
	printf("%d\n", increment);
}
