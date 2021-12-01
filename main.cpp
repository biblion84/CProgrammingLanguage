#include <stdio.h>
#include <stdlib.h>

int main() {
	
	FILE *f = fopen("input.txt", "r");

	int previous = -1;
	char temp[300];
	int increment = 0;
	while (fgets(temp, 300, f)) {
		int current = atoi(temp);
		if (previous != -1 && current > previous) {
			increment++;
		}
		previous = current;
		
	}

	printf("%d\n", increment);

}
