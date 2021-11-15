#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int main(int argc, char *argv[]) {
	FILE *f1;
	FILE *f2;
	if (argc >= 3) {
		f1 = fopen(argv[1], "r");
		f2 = fopen(argv[2], "r");
	} else {
		fprintf(stderr, "Need two filename to compare\n");
		return 1;
	}
	
	char l1[MAXLINE];
	char l2[MAXLINE];
	
	char *r1 = fgets(l1, MAXLINE, f1);
	char *r2 = fgets(l2, MAXLINE, f2);
	int line = 0;
	while ((r1 = fgets(l1, MAXLINE, f1)) != 0 &&
		(r2 = fgets(l2, MAXLINE, f2)) != 0){
		line++;
		if (strcmp(r1, r2) != 0) {
			printf("Disrepancy on line %d :\n%s%s", line, r1, r2);
			break;
		}
	}
	fclose(f1);
	fclose(f2);
}
