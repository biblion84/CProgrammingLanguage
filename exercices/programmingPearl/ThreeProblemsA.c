#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>
#include <string.h>
#define LINES 10100100
#define MAX_LINE 4294967295
#define SHUFFLED_FILE "D:/cbuild/shuffled"
#define SORTED_FILE "D:/cbuild/sorted"
unsigned int seed;

/* The state word must be initialized to non-zero */
unsigned int random()
{
	/* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
	unsigned int x = seed;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return seed = x;
}


void set(unsigned char *bitmap, int n){
	int index = n / 8;
	int rest = n % 8;
	unsigned char bitcompare = (1 << rest);
	bitmap[index] = (bitmap[index] | bitcompare);
}

bool test(unsigned char *bitmap, int n) {
	int index = n / 8;
	int rest = n % 8;
	unsigned char bitcompare = (1 << rest);
	char *s = "test";
	return bitmap[index] & bitcompare;
}

void createFile(){
	srand(42);
	seed = 42;
	FILE *f = fopen(SHUFFLED_FILE, "wb");
	
	int *file = (int*)malloc(LIN                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ES * sizeof(int)); // Can't allocate an array this big on the stack
	for (int k = 0; k < 50; k++) {
		int fileIndex = 0;
		for (int i = 0; i < LINES; i++) {
			if ((random() % 10) > 8){
				file[fileIndex++] = i + (k * LINES);
			}
		}
		printf("Start shuffling\n");
		for (int i = 0; i < (fileIndex / 2); i++) {
			int swapIndex = (random() % (fileIndex / 2)) + fileIndex/2;
			if (swapIndex != i) {
				int temp = file[i];
				file[i] = file[swapIndex];
				file[swapIndex] = temp;
			}
		}
		printf("Start writing\n");
		
		fwrite(file, sizeof(int), fileIndex, f);
		printf("Wrote %d integers\n", LINES);
	}
	free(file);
	/* Column 1 exercice 4
		Generating k integers less than n without duplicates.
		* Step 1 : Generate integer with an incrementing index from 0 to n
		* Step 2 : shuffle
		* Step 3 : ??
		* Step 4 : Profit
		*/
	
	fclose(f);
}


int main(int argc, char *argv[]) {
	//printf("%d\n", (int)sizeof(int));
	createFile();
	printf("Start of reading file\n");
	unsigned char *bitfield = (unsigned char*)malloc((MAX_LINE / 8) * sizeof(unsigned char)); // One bit per value
	{
		FILE *f = fopen(SHUFFLED_FILE, "rb");
		for (int i = 0; i < MAX_LINE / 8; i++) {
			bitfield[i] = 0;
		}
		int x = 0;
		while (fread(&x, sizeof(int), 1, f)) {
			if (x < 0) continue;
			if (test(bitfield, x)) {
				//Question 7 : Handle numbers that appears more than once,
				//They're ignored and the user is notified
				fprintf(stderr, "%d appears more than once !\n", x);
			}
			set(bitfield, x);
		}
		if (ferror(f)) {
			printf("error\n");
		}
	}
	printf("Start of writing file\n");
	
	{
		FILE *output = fopen(SORTED_FILE, "wb");
		for (int i = 0; i < MAX_LINE; ++i) {
			if (test(bitfield, i)) {
				fwrite(&i, sizeof(int), 1, output);
			}
		}
		fclose(output);
	}
#if 0
	
	{
		FILE *reader = fopen(SORTED_FILE, "rb");
		int readInt;
		while (fread(&readInt, sizeof(int), 1, reader) && !feof(reader)) {
			printf("%d\n", readInt);
		}
		fclose(reader);
	}
	
#endif
	printf("Ok\n");
	
}

