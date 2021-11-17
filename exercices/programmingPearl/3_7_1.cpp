#include <stdio.h>

int main(){
	
	int baseIncome = 300200;
	int income = baseIncome;
	float taxDue = 0;
	
	int brackets[6] = { 2200, 2700, 3200, 3700, 4200, 102200 };
	float taxRate[6] = { 0, .14f, .15f, .16f, .17f, .7f };
	
	for (int i = 5; i > 0; i--){
		if (income >= brackets[i]){
			taxDue += taxRate[i] * (income - brackets[i-1]);
			income = brackets[i-1];
		}
	}
	
	printf("you need to pay $%.2f on your income of $%d\n", taxDue, baseIncome);
	return 0;
}