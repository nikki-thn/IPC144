// Name: Nikki Truong	
// StudentID: 112314174
// Section: H
// Workshop: 4 - Array - At-Home

//This program will ask for number of days from user, low and high temperature values from each day
//and prompt back the temperature values of each day in columns. 
//The second part display highest and lowest temperature and correspondent day
//The third part calculate average temperature using the number of days from user's input

#include<stdio.h>

int main(void) {

	//declare variables, arrays and initialize them
	int numDay = 0;
	int avgDay = 0;
	int i, j;
	int low[10] = { 0 };
	int high[10] = { 0 };
	int dayHigh = 0, dayLow = 0;


	//Prompt greeting message and scan in input from user
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &numDay);
	printf("\n");

	//Check if conditions are met
	while (numDay < 3 || numDay >10) {
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &numDay);
		printf("\n");
	}

	//Using for loop to scan in high and low temperature values for each day
	for (i = 0; i < numDay; i++) {
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);
	}

	//Print output using another for loop
	printf("\n");
	printf("Day  Hi  Low\n");

	for (j = 0; j < numDay; j++) {
		printf("%d    %d    %d\n", j + 1, high[j], low[j]);
	}
	
	printf("\n");
	
	//Initialize the highest and lowest values
	int highest = high[0];
	int lowest = low[0];
	
	//This loop using if statement will compare and assign the highest values of all temperature inputs plus records the day it falls into
	int l = 0;
	for (l = 0; l < numDay; l++){
		if (high[l] >= highest) {
			highest = high[l];
			dayHigh = l + 1;
		}

		if (low[l] <= lowest) {
			lowest = low[l];
			dayLow = l + 1;
		}
	}

	printf("The highest temperature was %d, on day %d\n", highest, dayHigh);
	printf("The lowest temperature was %d, on day %d\n", lowest, dayLow);
	printf("\n");


	//The check variable done will set a loop until the user wants to stop 
	int done = 1;
	while (done == 1) {

		//prompt input number of days from user to calculate average temperature 
		printf("Enter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
		scanf("%d", &avgDay);
		printf("\n");

		//conditions check if the input is in range
		//If conditions are failed, prompt for re-input days
		if (avgDay > 4) {
			printf("Invalid entry, please enter a number between 1 and 4, inclusive: ");
			scanf("%d", &avgDay);
			printf("\n");
		}

		//If conditions are met, then calculate the total
		if (avgDay >= 1 && avgDay <= 4) {
			int k;
			double average = 0;
			int totalHigh = 0, totalLow = 0;
			for (k = 0; k < avgDay; k++) {
				totalHigh += high[k];
				totalLow += low[k];
			}

			//calculate average by add all array values and divide by the number of days entered
			average = ((double)totalHigh + (double)totalLow) / (avgDay * 2);
			printf("The average temperature up to day %d is: %.2lf\n", avgDay, average);
			printf("\n");
		}

		//User enter a negative number to exit
		if (avgDay < 1) {
			done = 0;
		}
	}

	printf("Goodbye!\n");

	return 0;
}