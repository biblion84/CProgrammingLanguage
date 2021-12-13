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

int main() {

	printf("%d\n", palindrome("kazyak", 4, 0));

	printf("\nOK\n");
}
