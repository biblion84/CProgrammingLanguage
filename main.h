#if !defined(MAIN_H)

void copy(char to[], const char from[]) {
	int i;
	for (i = 0; from[i] != '\0'; i++) {
		to[i] = from[i];
	}
	to[i] = '\0';
}



#define MAIN_H
#endif