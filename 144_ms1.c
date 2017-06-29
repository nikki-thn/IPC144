#include <stdio.h>


// ---------------------------------------
// place function PROTOTYPES below here...
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
void GroceryInventorySystem (void);
int menu(void);


// ----------------------------------------
// place function DEFINITIONS below here...
// ----------------------------------------
void welcome(void) {

	printf("---=== Grocery Inventory System ===---\n");
}

void printTitle(void) {

	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min | Total      |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

void printFooter(double gTotal) {
	printf("--------------------------------------------------------+----------------\n");
	if (gTotal > 0) {
		printf("                                           Grand Total: | %12.2lf\n", gTotal);
	}
}

void pause(void) {
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}

void flushKeyboard(void) {

	while (getchar() != '\n')
		;
}

int getInt(void) {

	int value;
	int errorCheck;
	char checkNewLine;
	int done = 1;

	while (done == 1) {

		errorCheck = scanf("%d%c", &value, &checkNewLine);

		if (checkNewLine != '\n' || errorCheck == 0) {
			printf("Invalid interger, please try again: ");
			flushKeyboard();
		}
		else {
			done = 0;
		}
	}

	return value;
}

int getIntLimited(int lowerLimit, int upperLimit) {
	
	int limitCheck;
	int done = 1;

	while (done == 1) {

		limitCheck = getInt();

		if (limitCheck > upperLimit || limitCheck < lowerLimit) {
			printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		}
		else {
			done = 0;
		}

	}

	return limitCheck;
}

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

double getDoubleLimited(double lowerLimit, double upperLimit) {

	double limitCheck;
	int done = 1;

	while (done == 1) {

		limitCheck = getDouble();

		if (limitCheck > upperLimit || limitCheck < lowerLimit) {
			printf("Invalid value, %lf < value < %lf: ", lowerLimit, upperLimit);
		}
		else {
			done = 0;
		}

	}

	return limitCheck;
}

// app interface

int yes(void) {
	char yesOrNo;
	int done = 0;

	scanf(" %c", &yesOrNo);
	if (yesOrNo != 'y', 'Y', 'n', 'N') {
		printf("Only (Y)es or (N)o are acceptable: ");
		flushKeyboard();
	}
	else if (yesOrNo == 'y', 'Y') {
		done = 1;
	}
	else if (yesOrNo == 'n', 'N') {
		done = 0;
	}

	return done;
}

int menu(void) {

	printf("1- List all items\n2 - Search by SKU\n3 - Checkout an item\n");
	printf("4 - Stock an item\n5 - Add new item or update item\n");
	printf("6 - Delete item\n7 - Search by name\n0 - Exit program\n\n");

	int choice;
	choice = getIntLimited(0, 7);

	return choice;
	
}

void GroceryInventorySystem (void) {
	int done = 0;
	int option;

	option = menu();

	while (done = 0) {

			switch (option) {

			case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			done = yes();
			break;

			case 1:
				printf("List Items under construction!\n");
				break;

			case 2:
				printf("Search Items under construction!\n");
				break;

			case 3:
				printf("Checkout Items under construction!\n");
				break;

			case 4:
				printf("Stock Items under construction!\n");
				break;

			case 5:
				printf("Add/Update Items under construction!\n");
				break;

			case 6:
				printf("Delete Items under construction!\n");
				break;

			case 7:
				printf("Search by name under construction!\n");
				break;

			}
		}
	}





int main(void) {
	int iVal;
	double dVal;
	welcome();

	// uncommnet each tester as you complete the develpment of that section:

	// testing printTitle() 
	printf("listing header and footer with grand total:\n");
	printTitle();
	//---------------------------------------------------------------


	// Testing printFooter()  

	printFooter(1234.5678);
	printf("listing header and footer without grand total:\n");
	printTitle();
	printFooter(-1);
	//---------------------------------------------------------------

	// Testing Pause() and flushKeyboard() 
	pause();
	//---------------------------------------------------------------


	// Testing getInt() 
	printf("Enter an integer: ");
	iVal = getInt();
	printf("You entered: %d\n", iVal);
	//---------------------------------------------------------------


	// Testing Get Int Limited 
	printf("Enter an integer between 10 and 20: ");
	iVal = getIntLimited(10, 20);
	printf("Your entered %d\n", iVal);
	//---------------------------------------------------------------


	// Testing Get Double 
	printf("Enter a floating point number: ");
	dVal = getDouble();
	printf("You entered: %0.2lf\n", dVal);
	//---------------------------------------------------------------


	// Tesing Get Double Limited 
	printf("Enter a floating point number between 10.00 and 20.00: ");
	dVal = getDoubleLimited(10.0, 20.0);
	printf("You entered: %0.2lf\n", dVal);
	//---------------------------------------------------------------


	// testing the App interface
	GroceryInventorySystem();
	//---------------------------------------------------------------

	printf("End of tester program for milestone one!\n");


	return 0;
}
