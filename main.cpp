#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>
#include <string.h>
#define LINES 3410000
#define MAX_LINE 10000000



void createFile(){
	srand(42);
	int *file = (int*)malloc(LINES * sizeof(int)); // Can't allocate an array this big on the stack
	int fileIndex = 0;
	for (int i = 0; i < LINES; i++){
		if ((rand() % 10) > 3){
			file[fileIndex++] = i;
		}
	}
	FILE *f = fopen("C:/cbuild/1", "wb");
	fwrite(file, sizeof(int), LINES, f);
	fclose(f);
}


int main(int argc, char *argv[]) {
	printf("%d\n", RAND_MAX);
	createFile();
	printf("File written\n");
	
	unsigned char *bitfield = (unsigned char*)malloc((MAX_LINE / 8) * sizeof(unsigned char)); // One bit per value
	{
		FILE *f = fopen("C:/cbuild/1", "rb");
		for (int i = 0; i < MAX_LINE / 8; i++) {
			bitfield[i] = 0;
		}
		int x = 0;
		int read = 0;
		int maxIndex = 0;
		int maxX = 0;
		while (fread(&x, sizeof(int), 1, f) && !feof(f)) {
			if (x < 0){
				break;
			}
			int index = x / 8;
			if (index > maxIndex) maxIndex = index;
			if (x > maxX) maxX = x;
			int rest = x % 8;
			++read;
			unsigned char bitcompare = (1 << rest);
			
			bitfield[index] = (bitfield[index] | bitcompare);
		}
		printf("Max index: %d\n", maxIndex);
		printf("Max number: %d\n", maxX);
		
		printf("Read: %d\n", read);
		if (ferror(f)) {
			printf("error\n");
		}
	}
	{
		FILE *output = fopen("C:/cbuild/output", "wb");
		int c = 0;
		for (int i = 0; i < MAX_LINE; ++i) {
			int index = i / 8;
			int rest = i % 8;
			unsigned char bitcompare = (1 << rest);
			//printf("index : %3d, rest : %3d, bitcompare : %3d, bitfield : %3d\n", index, rest, bitcompare, bitfield[index]);
			int toWrite = i;
			if (bitfield[index] & bitcompare) {
				printf("%d\n", i);
				fwrite(&toWrite, sizeof(int), 1, output);
				++c;
			}
		}
		fclose(output);
		printf("%d\n", c);
	}
	{
		FILE *readOutput = fopen("C:/cbuild/output", "rb");
		int y = 0;
		while (fread(&y, sizeof(int), 1, readOutput) && !feof(readOutput)) {
			//printf("%d\n", y);
			++y;
		}
		printf("Number written : %d\n", y);
	}

	printf("Ok\n");

}

