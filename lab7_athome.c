/*
Name:
Student number:
Workshop:
Section:
*/

#include <stdio.h>

#define SIZE 3

//Function Prototypes go here

void decompose (const long long phoneNum[], int *areaCode, int*prefix, int *lineNum);
int isValid(const long long phoneNum);

//Function Definitions go here
void decompose (const long long phoneNum, int *areaCode, int*prefix, int *lineNum) {

	long long temp;

		temp = (phoneNum % 10000000); // Exact the 
		*lineNum = temp % 10000; //9951
		*prefix = (temp - *lineNum) / 10000; // 501
		*areaCode = (phoneNum - temp) / 10000000; //306

}

int isValid(const long long phoneTemp) {


	int validCheck;
	int areaCodeCheck;
	int prefixCheck;
	int lineNumCheck;
	int done = 1;

	decompose(phoneTemp, &areaCodeCheck, &prefixCheck, &lineNumCheck);

   
	while (done = 1) {


	}

	if ((areaCodeCheck != 416 || areaCodeCheck != 647 || areaCodeCheck != 905) && (prefixCheck > 100 && prefixCheck < 999)) {
		done = 0;
		return 1;
	}

	else {

		printf("ERROR!!! Phone Number is not Valid");

		return 0;
	}

}



/* main program */
int main(void) {

	int option;
	int count = 0;
	long long phoneTemp;
	long long phoneNum[SIZE] = { 0LL };
	long long areaCode;
	long long prefix;
	long long lineNum;
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

			if (count < SIZE) {

				printf("Add a Number\n");
				printf("============\n");
				scanf("%lld", &phoneTemp);
				valid = isValid(phoneTemp);
				if (valid == 1) {
					phoneTemp = phoneNum[count];
					count++;
					printf("\n");
				}
			}
			else if (count >= SIZE) {
				printf("ERROR!!! Phone Number List is Full\n\n");
			}

			break;

		default:
			printf("Invalid menu option\n");
			break;

		}

	} while (option != 0);

	return 0;
}
