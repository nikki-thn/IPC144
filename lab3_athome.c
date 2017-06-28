// Name: Nikki Truong	
// Student Number: 112314174
// Email: ntruong4@myseneca.ca	
// Section: H
// Workshop: 3 - Logics - At-home

//This program will take in temperature values from user 3 timmes and calculate the mean,
//It also prompt back the highest, lowest temperature and the day the values belong to

#include<stdio.h>
#define NUMS 4

int main(void) {

	int low;
	int high;
	int highest = 0;
	int lowest = 0;
	int totalHigh = 0;
	int totalLow = 0;
	int i;
	int iHigh = 0;
	int iLow = 0;
	double average;

	printf("---=== IPC Temperature Analyzer ===---\n");

	//Use a for loop to promt and read in temperature values for day 1, 2, 3 and 4
	for (i = 0; i < NUMS; i++) {

		printf("Enter the high value for day %d: ", i + 1);
		scanf("%d", &high);
		printf("\n");
		printf("Enter the low value for day %d: ", i + 1);
		scanf("%d", &low);
		printf("\n");


		//Check if the data are bad, if one of them is bad, the loop will prompt error message and reread values
		while (high >= 41 || low <= -41 || high <= low) {
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\n");
			printf("Enter the high value for day %d: ", i + 1);
			scanf("%d", &high);
			printf("\n");
			printf("Enter the low value for day %d: ", i + 1);
			scanf("%d", &low);
			printf("\n");

		}

		//this add value of each day, add and store in a total variables
		totalHigh += high;
		totalLow += low;

		//this if statement will compare, assign the highest values of all temperature inputs and records the day it falls into
		if (high >= highest) {
			highest = high;
			iHigh = i + 1;
		}

		if (low <= lowest) {
			lowest = low;
			iLow = i + 1;
		}

	}

	//Average are calculated by taking the total temperature of each day and divided by 6 (2 values for each day)
	average = ((double)totalHigh + (double)totalLow) / 8;
	printf("The average (mean) temperature was: %.2lf\n", average);
	printf("The highest temperature was %d, on day %d\n", highest, iHigh);
	printf("The lowest temperature was %d, on day %d\n", lowest, iLow);

	return 0;
}