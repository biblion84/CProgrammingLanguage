#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

const int SIZE = 2000;

struct Grid {
	int sizeX;
	int sizeY;
	bool **cell;
};

void foldY(Grid *grid, int foldY) {
	for (int y = foldY + 1; y < grid->sizeY; y++) {
		for (int x = 0; x < grid->sizeX; x++) {
			if (grid->cell[y][x]) {
				int newY = foldY - (y - foldY);
				if (newY >= 0) {
					grid->cell[newY][x] = 1;
				}
			}
		}
	}
	grid->sizeY = foldY;
}


void foldX(Grid *grid, int foldX) {
	for (int y = 0; y < grid->sizeY; y++) {
		for (int x = foldX + 1; x < grid->sizeX; x++) {
			if (grid->cell[y][x]) {
				int newX = foldX - (x - foldX);
				if (newX >= 0) {
					grid->cell[y][newX] = 1;
				}
			}
		}
	}
	grid->sizeX = foldX;
}

int count(Grid *grid) {
	int result = 0;
	for (int y = 0; y < grid->sizeY; y++) {
		for (int x = 0; x < grid->sizeX; x++) {
			if (grid->cell[y][x]) {
				result++;
			}
		}
	}
	return result;
}

int main() {
	Grid grid;
	grid.sizeX = SIZE;
	grid.sizeY = SIZE;
	grid.cell = (bool **)malloc(SIZE * sizeof(bool *));
	for (int y = 0; y < SIZE; y++) {
		grid.cell[y] = (bool *)malloc(SIZE * sizeof(bool *));
	}
	
	for (int y = 0; y < grid.sizeY; y++) {
		for (int x = 0; x < grid.sizeX; x++) {
			grid.cell[y][x] = 0;
		}
	}
	
	
	FILE *f = fopen("input.txt", "r");
	char buf[300];
	
	while (fgets(buf, 300, f)) {
		char *line = buf;
		int x, y;
		char n[10];
		line = getWord(n, line);
		x = atoi(n);
		line = getWord(n, line);
		y = atoi(n);
		
		grid.cell[y][x] = 1;
	}
	
	// No time to parse gotta go fast
	foldX(&grid, 655);
	foldY(&grid, 447);
	foldX(&grid, 327);
	foldY(&grid, 223);
	foldX(&grid, 163);
	foldY(&grid, 111);
	foldX(&grid, 81);
	foldY(&grid, 55);
	foldX(&grid, 40);
	foldY(&grid, 27);
	foldY(&grid, 13);
	foldY(&grid, 6);
	
	for (int y = 0; y < grid.sizeY; y++) {
		for (int x = 0; x < grid.sizeX; x++) {
			if (grid.cell[y][x]) {
				printf("#");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("%d \n", count(&grid));
}
