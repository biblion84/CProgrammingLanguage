#if !defined(MAIN_H)
#define MAXLINE 1000 /* maximum input line length */

void copy(char to[], const char from[]) {
	int i;
	for (i = 0; from[i] != '\0'; i++) {
		to[i] = from[i];
	}
	to[i] = '\0';
}

/* getline: read a line into s, return length */
int getlines(char s[],int lim)
{
	int c = 0;
	int currentIndex = 0;
	int trailingBlanks = 0;
	for (int i = 0; (c = getchar()) != EOF; ++i) {
		if (currentIndex < lim-1) {
			s[currentIndex] = (char)c;
			currentIndex++;
			if (c == ' ' || c == '\t') {
				trailingBlanks++;
			} else {
				trailingBlanks = 0;
			}
		}
	}
	
	if (c == '\n') {
		s[currentIndex] = (char)c;
		++currentIndex;
	}
	
	s[currentIndex - trailingBlanks] = '\0';
	
	return currentIndex - trailingBlanks;
}

void reverse(char s[]){
	int i, j;
	int len = 0;
	for (len = 0; s[len] != '\0'; len++);
	
	for (i = 0, j = len - 1; i < len / 2 ; i++,j--) {
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	s[len] = '\n';
}

int power(int a, int exp) {
	int result = 1;
	for (int i = 0; i < exp; i++) {
		result *= a;
	}
	return result;
}

double dpower(double a, int exp) {
	double result = 1;
	for (int i = 0; i < exp; i++) {
		result *= a;
	}
	return result;
}



#define MAIN_H
#endif