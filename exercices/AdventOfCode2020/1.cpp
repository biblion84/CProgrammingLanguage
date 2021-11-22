#include <stdio.h>
#include <stdlib.h>


int main(){
	FILE *f = fopen("input.txt", "r");
	int numbers[3000];
	int numberIndex = 0;
	char line[300];
	
	while (fgets(line, 300, f) != 0){
		numbers[numberIndex++] = atoi(line);
	}
	
	for (int i = 0; i < numberIndex; i++){
		for (int j = i + 1; j < numberIndex; j++){
			for (int k = j + 1; k < numberIndex; k++){
				if (numbers[i] + numbers[j] + numbers[k] == 2020){
					printf("%d + %d + %d = 2020 \n %d * %d * %d = %d\n", numbers[i], numbers[j], numbers[k],
						numbers[i], numbers[j],numbers[k], numbers[i] * numbers[j] * numbers[k]);
				}
			}
		}
	}
	printf("OK");
	
	
}