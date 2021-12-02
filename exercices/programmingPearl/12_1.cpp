#include <stdio.h>
#include <stdlib.h>

int bigrand() {
	return rand() << 16 | rand();
}

int randint(int l, int u) {
	return l + (bigrand() % (u - l));
}

int main(){
	srand(42);
	for (int i = 0; i < 100; i++) {
		printf("%d\n", randint(0,100));
	}
}