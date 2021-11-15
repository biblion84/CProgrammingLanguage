#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc <= 0) {
		printf("Need at least a filename to read");
		return 1;
	}
	char *filename = argv[1];
	FILE *f = fopen(filename, "rb");
	
	int x;
	for (int i = 0; i < 100; i++){
		fread(&x, sizeof(int), 1, f);
		
		if (feof(f)){
			break;
		}
		
		printf("%d\n", x); 
	}
}