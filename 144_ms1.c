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
void GroceryInventorySystem(void);
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

	scanf(" %c", &yesOrNo);

	while (yesOrNo != 'y' && yesOrNo != 'Y' && yesOrNo != 'n' && yesOrNo != 'N') {
		printf("Only (Y)es or (N)o are acceptable: ");
		scanf(" %c", &yesOrNo);
	}

	if (yesOrNo == 'y' || yesOrNo == 'Y') {
		return 1;
	}
	else if (yesOrNo == 'n' || yesOrNo == 'N') {
		return 0;
	}

}
int menu(void) {

	printf("1- List all items\n2 - Search by SKU\n3 - Checkout an item\n");
	printf("4 - Stock an item\n5 - Add new item or update item\n");
	printf("6 - Delete item\n7 - Search by name\n0 - Exit program\n> ");

	int choice;
	choice = getIntLimited(0, 7);

	return choice;

}

void GroceryInventorySystem(void) {
	int flag = 0;
	int option;


	while (flag == 0) {
		option = menu();

		switch (option) {

		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			flag = yes();
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

		pause();
	}
}



int main(void) {
	int iVal;
	double dVal;
	welcome();

	printf("listing header and footer with grand total:\n");
	printTitle();
	
	printFooter(1234.5678);
	printf("listing header and footer without grand total:\n");
	printTitle();
	printFooter(-1);

	pause();

	printf("Enter an integer: ");
	iVal = getInt();
	printf("You entered: %d\n", iVal);

	printf("Enter an integer between 10 and 20: ");
	iVal = getIntLimited(10, 20);
	printf("Your entered %d\n", iVal);

	printf("Enter a floating point number: ");
	dVal = getDouble();
	printf("You entered: %0.2lf\n", dVal);

	printf("Enter a floating point number between 10.00 and 20.00: ");
	dVal = getDoubleLimited(10.0, 20.0);
	printf("You entered: %0.2lf\n", dVal);
	printf("End of tester program for IO tools!\n");

	welcome();

	GroceryInventorySystem();

	printf("End of tester program for milestone one!\n");

	return 0;
}
