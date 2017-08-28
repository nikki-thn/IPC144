// Name: Nikki Truong	
// StudentID: 112314174
// Section: H
// Workshop: 4 - Array - In-lab

//This program will ask for number of days from user, low and high temperature values from each day
//and promt back the temperature values of each day in columns 

#include<stdio.h>

int main(void) {

	//declare variables, arrays and initialize them
	int numDay = 0;
	int i, j;
	int low[10] = { 0 };
	int high[10] = { 0 };

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

	//Print output
	printf("\n");
	printf("Day	Hi	Low\n");

	for (j = 0; j < numDay; j++) {
		printf("%d	%d	%d\n", j + 1, high[j], low[j]);
	}

	return 0;
}
