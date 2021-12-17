#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

struct point {
	int x;
	int y;
};

int main() {
	// No input today
	//point targetMin = {};
	//targetMin.x = 20;
	//targetMin.y = -10;
	//point targetMax = {};
	//targetMax.x = 30;
	//targetMax.y = -5;	
	point targetMin = {};
	targetMin.x = 48;
	targetMin.y = -189;
	point targetMax = {};
	targetMax.x = 70;
	targetMax.y = -148;	
	
	int globalMaxY = 0;
	for (int x = 0; x < 1000; x++) {
		for (int y = 0; y < 1000; y++) {
			int maxY = 0;
			point position = {};
			point velocity = {};
			velocity.x = x;
			velocity.y = y;
			for (int step = 0; step < 10000; step++) {
				position.x += velocity.x;
				position.y += velocity.y;
				
				if (position.y > maxY) {
					maxY = position.y;
				}
				
				if (position.x >= targetMin.x && position.x <= targetMax.x &&
					position.y >= targetMin.y && position.y <= targetMax.y) {
					if (maxY > globalMaxY) {
						globalMaxY = maxY;
					}
					break;
				}
				velocity.y--;
				if (velocity.x > 0) {
					velocity.x--;
				} else if (velocity.x < 0) {
					velocity.x++;
				}
			}
		}
	}
	
	printf("%d\n", globalMaxY);
	
	
	
	printf("\nOk\n");
	
}