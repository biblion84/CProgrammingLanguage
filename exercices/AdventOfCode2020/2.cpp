#include <stdio.h>
#include <stdlib.h>


int main(){
	FILE *f = fopen("input.txt", "r");
	
	int valid = 0;
	int total = 0;
	while (true){
		total++;
		int low, high;
		char c;
		char p[30];
		int result = fscanf(f, "%u-%u %c: %s", &low, &high, &c, p);
		if (result == EOF){
			break;
		}
		int count = 0;
		if (p[low - 1] == c){
			count++;
		}
		if (p[high - 1] == c) {
			count++;
		}
		printf("%u-%u %c: %s\n", low, high, c, p);
		if (count == 1) {
			valid++;
		}
	}
	
	printf("%d %d\n", valid, total);
}