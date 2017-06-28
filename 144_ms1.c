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
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---");
}

void printFooter(double gTotal) {
	printf("--------------------------------------------------------+----------------\n");
	printf("                                           Grand Total: | %12.2lf", gTotal);
}

void flushKeyboard(void) {

	while (getchar() != '\n') 
		;
}

void pause(void) {
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}

int getInt(void) {
	int value;
	char newLine = 'x';

		printf("Enter an integer: ");
		scanf("%d%c", &value, &newLine);

		while (newLine != '\n'){
			printf("Invalid interger, please try again: ");
			scanf("%d%c", &value, &newLine);
	}
	printf("%d\n", value);
}

int main() {

	getInt();



	return 0;
}
