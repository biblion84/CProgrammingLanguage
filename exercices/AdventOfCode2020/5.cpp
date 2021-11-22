#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	FILE *f = fopen("input.txt", "r");
	
	char s[300];
	char seats[1024];
	
	int max = 0;
	
	while (fgets(s, 300, f)) {
		int row = 0;
		for (int i = 0; i < 7; i++) {
			if (s[i] == 'B') {
				row |= (1 << (6 - i));
			}
		}
		
		int column = 0;
		for (int i = 7; i < 10; i++) {
			if (s[i] == 'R') {
				int shift = 9 - i;
				column |= (1 << shift);
			}
		}
		
		int seatId = (row * 8) + column;
		
		if (seatId > max) {
			max = seatId;
		}
		seats[seatId] = 1;
		printf("Row : %d, Column : %d, SeatId : %d\n", row, column, seatId);
		
	}
	
	printf("Max : %d\n", max);
	
	for (int i = 1; i < 867; i++){
		if (seats[i] == 0){
			printf("FOUND %d\n", i);
		}
	}
}
