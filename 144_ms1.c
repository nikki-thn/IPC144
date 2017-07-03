/*
Name: Nikki Truong
ID: 112 314 174
IPC144 - Section H
Milestone Project - Part 1
*/


#include <stdio.h>

// ---------------------------------------
// Function PROTOTYPES goes here...
// ---------------------------------------


// user interface tools function PROTOTYPES:
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);


// application user interface function PROTOTYPES:
int yes(void);
void GroceryInventorySystem(void);
int menu(void);


// ----------------------------------------
//Function DEFINITIONS goes here...
// ----------------------------------------


//Function prints welcome message

void welcome(void) {

	printf("---=== Grocery Inventory System ===---\n\n");

}

//Function prints header

void printTitle(void) {

	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");

}

//The function prints footer and only show Grand Total when it is a positive number

void printFooter(double gTotal) {

	printf("--------------------------------------------------------+----------------\n");

	if (gTotal > 0) {

		printf("                                           Grand Total: |%12.2lf\n", gTotal);

	}

}

/*
This function will read in every single chacracter without storing and return control to its caller when
user key in newline \n character 
*/

void flushKeyboard(void) {

	while (getchar() != '\n')
		;
}

/*
This function will pause the flow of the program and continue the program when user input new line character
It calls flushkeyboard to clear buffer and wait for ENTER from user to continue
*/

void pause(void) {

	printf("Press <ENTER> to continue...");
	flushKeyboard();

}

/*
Function getInt will scan in two input, an integer and one character, it reads in the integer and won't let user
pass unless the correct data is entered and the one character is a newline
*/

int getInt(void) {

	int value;
	int errorCheck;
	char checkNewLine;
	int done = 1;

	while (done == 1) {

		errorCheck = scanf("%d%c", &value, &checkNewLine);

		//Here the if-statement will check and enforce user to enter an valid input and end the input with ENTER
		//errorCheck == 0 to make sure user input will be number and not an empty value

		if (checkNewLine != '\n' || errorCheck == 0) {
			printf("Invalid integer, please try again: ");
			flushKeyboard();
		}

		//when conditions are met, exit loop

		else {
			done = 0;
		}
	}

	//function returns the valid integer to caller

	return value;
}

//This function will check the value that was returned from getInt function is within allowing limits

int getIntLimited(int lowerLimit, int upperLimit) {

	int limitCheck;
	int done = 1;

	while (done == 1) {

		limitCheck = getInt();

		//limits check for valid input

		if (limitCheck > upperLimit || limitCheck < lowerLimit) {
			printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		}

		//If input is within limits, exit loop

		else {
			done = 0;
		}

	}

	//return value after limits check to caller

	return limitCheck;
}

//Same as getInt but with double

double getDouble(void) {

	double value;
	double errorCheck;
	char checkNewLine;
	int done = 1;

	while (done == 1) {

		errorCheck = scanf("%lf%c", &value, &checkNewLine);

		if (checkNewLine != '\n' || errorCheck == 0) {

			printf("Invalid number, please try again: ");
			flushKeyboard();

		}

		else {

			done = 0;

		}

	}

	return value;
}

//Same as getIntLimited but with double

double getDoubleLimited(double lowerLimit, double upperLimit) {

	double limitCheck;
	int done = 1;

	while (done == 1) {

		limitCheck = getDouble();

		if (limitCheck > upperLimit || limitCheck < lowerLimit) {

			printf("Invalid value, %lf< value < %lf: ", lowerLimit, upperLimit);

		}

		else {
			done = 0;

		}

	}

	return limitCheck;
}


// app interface


//This function will fool-proof user's character input and it will return one value (0 or 1) to its caller

int yes(void) {

	char yesOrNo;
	int value = 0;

	scanf(" %c", &yesOrNo);

	//This loop will check user input and only stop when y or n was entered

	while (yesOrNo != 'y' && yesOrNo != 'Y' && yesOrNo != 'n' && yesOrNo != 'N') {

		printf("Only (Y)es or (N)o are acceptable: ");
		scanf(" %c", &yesOrNo);

	}

	if (yesOrNo == 'y' || yesOrNo == 'Y') {

		value = 1;
	}

	else if (yesOrNo == 'n' || yesOrNo == 'N') {

		value = 0;
	}

	return value;
}

/*The menu function will print out available options, call function getIntLimited to take in a valid option
and return user's choices to its caller*/

int menu(void) {

	printf("1- List all items\n2- Search by SKU\n3- Checkout an item\n");
	printf("4- Stock an item\n5- Add new item or update item\n");
	printf("6- Delete item\n7- Search by name\n0- Exit program\n> ");

	int choice;
	choice = getIntLimited(0, 7);

	return choice;

}

/*
This function contains the expansions of our program's menu. It calls function menu to obtain a verified option
from user and goes to an option accordingly
*/

void GroceryInventorySystem(void) {
	int flag = 0;
	int option;

	welcome();

	while (flag == 0) {
		option = menu();

		switch (option) {

		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			flag = yes();
			break;

		case 1:
			printf("List Items under construction!\n");
			pause();
			break;

		case 2:
			printf("Search Items under construction!\n");
			pause();
			break;

		case 3:
			printf("Checkout Item under construction!\n");
			pause();
			break;

		case 4:
			printf("Stock Item under construction!\n");
			pause();
			break;

		case 5:
			printf("Add/Update Item under construction!\n");
			pause();
			break;

		case 6:
			printf("Delete Item under construction!\n");
			pause();
			break;

		case 7:
			printf("Search by name under construction!\n");
			pause();
			break;

		}
	}
}

