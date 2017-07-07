/*
Name: Nikki Truong
Student number: 112 314 174
IPC 144 - Workshop 7 - At home
Section: H
*/

//This program will store user contacts number and exact it into format (area) - prefix - number 

#include <stdio.h>


#define SIZE 3 //Maximum number storage

//Function prototype
void decompose(long long phoneNum, int *areaCode, int*prefix, int *lineNum);
int isValid(const long long phoneNum);

//Function declaration
//This funtion will extract user input phone number into area code, prefix and 4 last digit number
void decompose(long long phoneNum, int *areaCode, int*prefix, int *lineNum) {

	int temp;

	temp = (phoneNum % 10000000); //This line of code extract last 7 digits
	*lineNum = temp % 10000; //This line gets the last 4 digits
	*prefix = (temp - *lineNum) / 10000; //This codes gets the prefix digits
	*areaCode = (phoneNum - temp) / 10000000; //This exacts the area code

}

//This function will check each area code and prefix if they are valid
/*Function recieves a phone number from caller, call decompose funtion to break it up and check
the required components*/
int isValid(const long long phoneTemp) {

	int areaCodeCheck;
	int prefixCheck;
	int lineNumCheck;

	decompose(phoneTemp, &areaCodeCheck, &prefixCheck, &lineNumCheck);

	//Check conditions
	if ((areaCodeCheck == 416 || areaCodeCheck == 647 || areaCodeCheck == 905) && (prefixCheck > 100 && prefixCheck < 999)) {
		return 1;
	}

	else {
		//If number is not valid, print error message
		printf("ERROR!!! Phone Number is not Valid\n");
		
		return 0;
	}

}


/* main program */
int main(void) {

	int option;
	int count = 0;
	long long phoneNum[SIZE] = { 0LL };
	long long phoneTemp = { 0LL };
	int areaCode;
	int prefix;
	int lineNum;
	int valid;
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
			printf("==============\n");

			// Display each number in decomposed form
			for (i = 0; i < count; i++) {

				decompose(phoneNum[i], &areaCode, &prefix, &lineNum);

				printf("(%d)-", areaCode);
				printf("%d-", prefix);
				printf("%d\n", lineNum);

			}

			printf("\n");

			break;

		case 2:	// Add a Phone Number

				//This will check the counter to make sure there are space in array for input 
				//Everytime user input, increase the counter by one
			if (count < SIZE) {

				printf("Add a Number\n");
				printf("============\n");
				scanf("%lld", &phoneNum[count]);
				valid = isValid(phoneTemp); //Here function isValid is called to check the entered number

											//When the phone number is valid, store it to the array
				if (valid == 1) {
					phoneNum[count] = phoneTemp;
					count++;
					
				}
				printf("\n");

			}

			//If array is full, return an error message
			else if (count >= SIZE) {
				printf("Add a Number\n");
				printf("============\n");
				printf("ERROR!!! Phone Number List is Full\n");
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
