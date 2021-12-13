#include <stdio.h>

// recursive exercises from https://www.w3resource.com/c-programming-exercises/recursion/index.php

void count(int i) {
	if (i == 0) {
		return;
	}
	count(i - 1);
	printf("%d, ", i);
}

int add(int i) {
	if (i == 1) {
		return 1;
	}
	return i + add(i - 1);
}

int fibonnaci(int i) {
	if (i <= 1) {
		return 1;
	}
	return fibonnaci(i - 1) + fibonnaci(i - 2);
}

void arrayPrint(int *a, int i) {
	if (i == 1) {
		printf("%d", a[i]);
		return;
	}
	arrayPrint(a, i - 1);
	printf("%d", a[i]);
}

void countDigits(int n, int count) {
	if ((n / 10) > 0) {
		countDigits(n / 10, count + 1);
	} else {
		printf("%d digits\n", count);
	}
}

int sumDigits(int n) {
	if (n == 0) {
		return 0;
	}
	int digit = n % 10;
	return digit + sumDigits(n / 10);
}

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	a = a % b;
	return gcd(b, a);
}

int maxArray(int *arr, int max, int depth) {
	if (depth < 0) {
		return max;
	}
	int newMax = max;
	if (arr[depth] > newMax) {
		newMax = arr[depth];
	}
	return maxArray(arr, newMax, depth - 1);
}

void reverse(char *s, int index) {
	if (s[index] == '\0') {
		return;
	}
	reverse(s, index + 1);
	printf("%c", s[index]);
}

int factorial(int n) {
	if (n == 1) {
		return 1;
	}
	return n * factorial(n - 1);
}

int binary(int n, int power, int bin) {
	if (n == 0) {
		return bin;
	}
	int rest = n % 2;
	bin = bin + (rest * power);
	power *= 10;
	return binary(n / 2, power, bin);
}

bool prime(int n, int divisor) {
	if (divisor >= n) {
		return true;
	}
	if (n % divisor == 0) {
		return false;
	}
	
	return prime(n, divisor + 1);
}

int lcm(int a, int b, int amul, int bmul) {
	if ((a * amul) == (b * bmul)) {
		return a * amul;
	} else if ((a * amul) > (b * bmul)) {
		return lcm(a, b, amul, bmul + 1);
	} else {
		return lcm(a, b, amul + 1, bmul);
	}
}

void odd(int n) {
	if (n == 1) {
		return;
	}
	odd(n - 1);
	if (n % 2 == 0) {
		printf("%d, ", n);
	}
}

bool palindrome(char *s, int len, int current) {
	int lastIndex = len - current;
	if (current >= lastIndex) {
		return true;
	}
	if (s[current] != s[lastIndex]) {
		return false;
	}
	return palindrome(s, len, current + 1);
}


int power(int n, int pow) {
	if (pow <= 0) {
		return 1;
	}
	if (pow == 1) {
		return n;
	}
	return n * power(n, pow - 1);
}

void hailstone(int n) {
	printf("%d, ", n);
	if (n == 1) {
		return;
	}
	if (n % 2 == 0) {
		hailstone(n / 2);
	} else {
		hailstone((n * 3) + 1);
	}
}

void copy(char *in, char *out) {
	if (*in == '\0') {
		*out = '\0';
		return;
	}
	*out = *in;
	copy(in + 1, out + 1);
}

void firstCapital(char *s) {
	if (*s == '\0') {
		printf("No capital\n");
		return;
	}
	if (*s >= 'A' && *s <= 'Z') {
		printf("First capital : %c\n", *s);
		return;
	}
	firstCapital(s + 1);
}

int binSearch(int *a, int search, int low, int high) {
	if (low > high) {
		return -1;
	}
	int middle = (low + high) / 2;
	if (a[middle] == search) {
		return middle;
	} else if (a[middle] > search) {
		return binSearch(a, search, low, middle - 1);
	} else {
		return binSearch(a, search, middle + 1, high);
	}
}

int main() {
	
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = i * 3;
		//printf("%d\n", a[i]);
	}
	
	int idx = binSearch(a, 9, 0, 9);
	printf("index : %d, %d", idx, a[idx]);
	
	
	
	printf("\nOK\n");
}
