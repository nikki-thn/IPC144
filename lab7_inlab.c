/*
Name: Nikki Truong
Student number: 112 314 174
IPC 144 - Workshop 7
Section: H
*/

//This program will store user contacts number and exact it into format (area) - prefix - number 

#include <stdio.h>


#define SIZE 3 //Maximum number storage

//Function prototype
void decompose (const long long phoneNum[], int *areaCode, int*prefix, int *lineNum);


//Function declaration
//This funtion will extract user input phone number into area code, prefix and 4 last digit number

void decompose(const long long phoneNum, int *areaCode, int*prefix, int *lineNum) {

	long long temp;

	temp = (phoneNum % 10000000); //This line of code extract last 7 digits
	*lineNum = temp % 10000; //This line gets the last 4 digits
	*prefix = (temp - *lineNum) / 10000; //This codes gets the prefix digits
	*areaCode = (phoneNum - temp) / 10000000; //This exacts the area code

}

/* main program */
int main(void) {

	int option;
	int count = 0;
	long long phoneNum[SIZE] = { 0LL };
	long long areaCode;
	long long prefix;
	long long lineNum;
	int i = 0;

	printf("---=== Phone Numbers ===---\n\n");

	do {
		// Display the Option List
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {

		case 0:	// Exit the program
			printf("Exiting Phone Number App. Good Bye!!!\n\n");
			break;

		case 1: // Display the Phone List

			printf("Phone Numbers\n");
			printf("==============\n\n");
			// Display each number in decomposed form

			for (i = 0; i < count; i++) {

				decompose(phoneNum[i], &areaCode, &prefix, &lineNum);

				printf("(%d)-", areaCode);
				printf("%d-", prefix);
				printf("%d\n", lineNum);

			}

			break;

		case 2:	// Add a Phone Number

			//This will check the counter to make sure there are space in array for input 
			//Everytime user input, increase the counter by one
			if (count < SIZE) {

				printf("Add a Number\n");
				printf("============\n");
				scanf("%lld", &phoneNum[count]);
				printf("\n");
				count++;
			}

			//If array is full, return an error message
			else if (count >= SIZE) {
				printf("ERROR!!! Phone Number List is Full\n\n");
			}

			break;

		default:

			//When user input non of the valid option
			printf("Invalid menu option\n");

			break;

		}

	} while (option != 0);

	return 0;
}
