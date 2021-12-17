#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

char tobit(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 10 + (c - 'A');
}

void printbit(char c, int bitsToPrint) {
	for (int i = 0; i < bitsToPrint; i++) { // Print the last bitsToPrint bits
		if ((c & (1 << (3 - i)))) {
			printf("1");
		} else {
			printf("0");
		}
	}
}

struct bits {
	int bitIdx;
	char *memory;
};

struct lit {
	char version;
	char type;
	long long value;
};

// Return a char with quantity of bit set
long long read(bits *b, int quantity) {
	long long result = 0;
	for (int q = quantity - 1; q >= 0; q--){
		char bit = b->memory[b->bitIdx / 4] & (1 << (3 -(b->bitIdx % 4))); // 3- because we read inversed
		if (bit) {
			result += 1;
		}
		result = result << 1;
		b->bitIdx++;
	}
	result = result >> 1; // We always do 1 shift in excess
	return result;
}

struct readLitteralR {
	long long value;
	int bitRead;
};

readLitteralR readLitteral(bits *b) {
	readLitteralR result = {}; 
	bool cont = true;
	while (cont) {
		char value = (char)read(b, 5);
		result.bitRead += 5;
		cont = value & 0b10000; // is the continue bit set
		value = value & 0b01111; // remove the continue bit
		result.value += value;
		result.value <<= 4;
	}
	result.value >>= 4;
	return result;
}

struct packet {
	long long value;
	int bitRead;
};

int versions = 0;



// recursive read operator
// when do we stop ? version = 0 ??
packet readPacket(bits *b) {
	packet p = {};
	
	char version = (char)read(b, 3);
	char type = (char)read(b, 3);
	p.bitRead += 6;
	versions += version;
	
	if (type == 4) { // litteral
		readLitteralR litteral = readLitteral(b);
		p.bitRead += litteral.bitRead;
		p.value = litteral.value;
		//printf("%lld\n", litteral.value);
	} else { // operator
		char i = (char)read(b, 1);
		p.bitRead += 1;
		long long length = 0;
		if (i) {
			length = read(b, 11);
			p.bitRead += 11;
			int sub = 0;
			long long value = -1;
			while(sub < length) {
				packet r = readPacket(b);
				p.bitRead += r.bitRead;
				sub++;
				switch (type) {
					case 0 : { // sum
						if (value == -1) value = 0;
						value += r.value;
					} break;
					case 1 : { // product
						if (value == -1) value = 1;
						value *= r.value;
					} break;
					case 2 : { // minimum
						if (value == -1) value = r.value;
						value = value < r.value ? value : r.value;
					} break;
					case 3 : { // maximum
						if (value == -1) value = r.value;
						value = value > r.value ? value : r.value;
					} break;
					case 5 : { // gt
						if (value == -1) {
							value = r.value;
						} else {
							value = value > r.value;
						}
					} break;
					case 6 : { // lt
						if (value == -1) {
							value = r.value;
						} else {
							value = value < r.value;
						}
					} break;
					case 7 : { // eq
						if (value == -1) {
							value = r.value;
						} else {
							value = value == r.value;
						}
					} break;
				}
			}
			p.value = value;
			//printf("%lld\n", length);
		} else {
			length = read(b, 15);
			p.bitRead += 15;
			int bRead = 0;
			long long value = -1;
			while(bRead < length) {
				packet r = readPacket(b);
				bRead += r.bitRead;
				switch (type) {
					case 0 : { // sum
						if (value == -1) value = 0;
						value += r.value;
					} break;
					case 1 : { // product
						if (value == -1) value = 1;
						value *= r.value;
					} break;
					case 2 : { // minimum
						if (value == -1) value = r.value;
						value = value < r.value ? value : r.value;
					} break;
					case 3 : { // maximum
						if (value == -1) value = r.value;
						value = value > r.value ? value : r.value;
					} break;
					case 5 : { // gt
						if (value == -1) {
							value = r.value;
						} else {
							value = value > r.value;
						}
					} break;
					case 6 : { // lt
						if (value == -1) {
							value = r.value;
						} else {
							value = value < r.value;
						}
					} break;
					case 7 : { // eq
						if (value == -1) {
							value = r.value;
						} else {
							value = value == r.value;
						}
					} break;
				}
			}
			p.value = value;
			p.bitRead += bRead;
			//printf("%lld\n", length);
		}
		
	}
	return p;
	
}

int main() {
	FILE *f = fopen("input.txt", "r");
	char buffer[300] = {};
	
	char *memory = (char *)malloc(10000 * sizeof(char));
	for (int i = 0; i < 10000; i++) memory[i] = '\0';
	
	bits b = {};
	b.memory = memory;
	int mIdx = 0;
	
	while (fgets(buffer, 300, f) != 0) {
		for (int i = 0; buffer[i] != '\0'; i++) {
			b.memory[mIdx++] = tobit(buffer[i]);
		}
	}
	
	packet read = readPacket(&b);
	printf("%lld\n", read.value);
	
	
	
	printf("\nOk\n");
	
}