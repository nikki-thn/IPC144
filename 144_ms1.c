#include <stdio.h>


// ---------------------------------------
// place function PROTOTYPES below here...
// ---------------------------------------
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);


// user interface tools function PROTOTYPES:



// application user interface function PROTOTYPES:





// ----------------------------------------
// place function DEFINITIONS below here...
// --------------------------------
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

int getInt (void) {

	int value;
	int errorCheck;
	char checkNewLine;
	int done = 1;


	while (done == 1) {

	errorCheck = scanf("%d%c", &value, &checkNewLine);

		if (checkNewLine != '\n' || errorCheck == 0) {
			printf("Invalid interger, please try again: ");
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

		scanf("%d", &limitCheck);

		if (limitCheck > upperLimit || limitCheck < lowerLimit) {
			printf("Invalid value, %d < value < %d", lowerLimit, upperLimit);
		}
		else {
			done = 0;
		}

	}

	return limitCheck;
}

double getDouble (void) {

	double value;
	double errorCheck;
	char checkNewLine;
	int done = 1;


	while (done == 1) {

		errorCheck = scanf("%lf%c", &value, &checkNewLine);

		if (checkNewLine != '\n' || value == 0) {
			printf("Invalid interger, please try again: ");
		}
		else {
			done = 0;
		}
	}

	return value;
}

double getDoubleLimited (double lowerLimit, double upperLimit) {

	double limitCheck;
	int done = 1;

	while (done == 1) {

		scanf("%lf", &limitCheck);

		if (limitCheck > upperLimit || limitCheck < lowerLimit) {
			printf("Invalid value, %d < value < %d", lowerLimit, upperLimit);
		}
		else {
			done = 0;
		}

	}

	return limitCheck;
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


	return 0;
}
