// Name: Nikki Truong	
// Student Number: 112314174
// Email: ntruong4@myseneca.ca	
// Section: H
// Workshop: 3 - Logics

//This program will take in temperature values from user 3 timmes and calculate the mean

#include<stdio.h>
#define NUMS 3

int main(void) {

	int low;
	int high;
	int totalHigh = 0;
	int totalLow = 0;
	int i;
	double average;

	printf("---=== IPC Temperature Analyzer ===---\n");

	//Use a for loop to promt and read in temperature values for day 1, 2 and 3
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

	} 

	//Average are calculated by taking the total temperature of each day and divided by 6 (2 values for each day)
	average = ((double)totalHigh + (double)totalLow) / 6;
	printf("The average (mean) temperature was: %.2lf\n", average);

	return 0;
}