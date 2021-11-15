#include <stdio.h>

static int daytabSize = 13;
static char **daytab;
/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	if (month > 12 || day > 31) {
		return -1;
	}
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += *(*(daytab + leap) + i);
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	if (yearday < 0) {
		*pmonth = -1;
		*pday = -1;
	}
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= *(*(daytab + leap) + i);
	*pmonth = i;
	*pday = yearday;
}

int main ()
{
	char *pointerStore[2];
	daytab = pointerStore;
	char notLeap[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char leap[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	*daytab = notLeap;
	*(daytab + 1) = notLeap;
	int month, day;
	
	month_day(1914, 123, &month, &day);
	printf("Month\t: %2d\nDay\t\t: %2d", month, day);
	putchar('\n');
	
}