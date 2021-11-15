#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>
#include <string.h>
#define LINES 3410000
#define MAX_LINE 10000000

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
	return bitmap[index] & bitcompare;
}

void createFile(){
	srand(42);
	int *file = (int*)malloc(LINES * sizeof(int)); // Can't allocate an array this big on the stack
	int fileIndex = 0;
	for (int i = 0; i < LINES; i++){
		if ((rand() % 10) > 3){
			file[fileIndex++] = i;
		}
	}
	/* Column 1 exercice 4
		Generating k integers less than n without duplicates.
		* Step 1 : Generate integer with an incrementing index from 0 to n
		* Step 2 : shuffle
		* Step 3 : ??
		* Step 4 : Profit
		*/
	seed = 22;
	//shuffle the data around
	for (int i = 0; i < (fileIndex / 2); i++) {
		int swapIndex = (random() % (fileIndex / 2)) + fileIndex/2;
		if (swapIndex != i) {
			int temp = file[i];
			file[i] = file[swapIndex];
			file[swapIndex] = temp;
		}
	}
	file[30] = 42;
	file[3000] = 42;
	file[2500] = -42;
	FILE *f = fopen("C:/cbuild/shuffled", "wb");
	fwrite(file, sizeof(int), fileIndex, f);
	printf("Before\n");
	//
	char *test = "hello";
	fwrite(test, sizeof(char), 4, f);
	printf("Wrote\n");
	fclose(f);
	free(file);
}


int main(int argc, char *argv[]) {
	createFile();
	
	unsigned char *bitfield = (unsigned char*)malloc((MAX_LINE / 8) * sizeof(unsigned char)); // One bit per value
	{
		FILE *f = fopen("C:/cbuild/shuffled", "rb");
		for (int i = 0; i < MAX_LINE / 8; i++) {
			bitfield[i] = 0;
		}
		int x = 0;
		while (fread(&x, sizeof(int), 1, f) && !feof(f)) {
			if (x < 0) continue;
			if (test(bitfield, x)) {
				// Question 7 : Handle numbers that appears more than once,
				// They're ignored and the user is notified
				fprintf(stderr, "%d appears more than once !\n", x);
			}
			set(bitfield, x);
		}
		if (ferror(f)) {
			printf("error\n");
		}
	}
	{
		FILE *output = fopen("C:/cbuild/sorted", "wb");
		for (int i = 0; i < MAX_LINE; ++i) {
			if (test(bitfield, i)) {
				fwrite(&i, sizeof(int), 1, output);
			}
		}
		fclose(output);
	}
	
	//{
	//	FILE *reader = fopen("C:/cbuild/output", "rb");
	//	int readInt;
	//	while (fread(&readInt, sizeof(int), 1, reader) && !feof(reader)) {
	//		printf("%d\n", readInt);
	//	}
	//	fclose(reader);
	//}
	
	printf("Ok\n");
	
}

