/*
Nikki Truong - 112 314 174
IPC144 - Section H
Milestone Project - part 2
*/


/*As for now, the file contain functions that are being called from 144_ms1_tester file.
Details of what each function does are commented below */

#include <stdio.h>

#define LINEAR 1
#define FORM 0

const TAX = 0.13;

struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};

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
//part 2
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);




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

/*This function will reach in every single chacracter without storing and return control to its caller when
user key in newline character (ENTER)*/

void flushKeyboard(void) {

	while (getchar() != '\n')
		;
}

/*This function will pause the flow of the program and continue the program when user input new line character
It calls flushkeyboard to clear buffer and wait for ENTER from user to continue*/

void pause(void) {

	printf("Press <ENTER> to continue...");
	flushKeyboard();

}

/*Function getInt will scan in two input, an integer and one character, it reads in the integer and won't let user
pass unless the correct data is entered and the one character is a newline*/

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

//This function till check the value return from getInt function is within allowing limits

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

	scanf(" %c", &yesOrNo);

	//This loop will check user input and only stop when y or n was entered

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

/*This function contains the expansions of our program's menu. It calls function menu to obtain a verified option
from user and goes to an option accordingly*/

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

//PART 2

double totalAfterTax(struct Item item) {
	double totalAfterTax;

	if (item.isTaxed == 0) {
		totalAfterTax = (item.price * item.quantity) * TAX;
	}
	else if (item.isTaxed != 0) {
		totalAfterTax = (item.price * item.quantity);

	}
	return totalAfterTax;
}

int isLowQuantity(struct Item item) {

	if (item.quantity < item.minQuantity) {
		return 1;
	}
	else {
		return 0;
	}

}

/*struct Item itemEntry(int sku) {
	int count = 0;

	sku = getIntLimited(0,999);
	printf("Name: ");
	scanf("%20[^\n]", &item.name[21]);
	flushKeyboard();

	price = getdouble();
	item.quantity = getInt();
	item.minQuantity = getInt();
	item.isTaxed = yes();

	count++;

}*/

void displayItem(struct Item item, int linear) {

	double totalPrice;
	int lowQuantity;

	totalPrice = totalAfterTax(item);
	lowQuantity = isLowQuantity(item);
	if (linear == 1) {

		if (lowQuantity == 0) {
			printf(">|%d|%c| %lf| %c| %d| %d| %lf|", item.sku, item.name, item.price, item.isTaxed, item.quantity, item.minQuantity, totalPrice);

		}
		else if (lowQuantity == 1) {
			printf(">|%d|%c| %lf| %c| %d| %d| %lf|***", item.sku, item.name, item.price, item.isTaxed, item.quantity, item.minQuantity, totalPrice);
		}
	}

	else if (linear == 0) {
		if (lowQuantity == 0) {

			printf("SKU: %d\nName: %c\nPrice: %lf\nQuanity: %d", item.sku, item.name, item.price, item.quantity);
			printf("Minimun Qty: %d\nIs Taxed: %d\n", item.minQuantity, item.minQuantity, item.isTaxed, totalPrice);
		}
		else if (lowQuantity == 1) {

			printf("SKU: %d\nName: %c\nPrice: %lf\nQuanity: %d", item.sku, item.name, item.price, item.quantity);
			printf("Minimun Qty: %d\nIs Taxed: %d\n", item.minQuantity, item.minQuantity, item.isTaxed, totalPrice);
			printf("WARNING: QUantity low, please order ASAP!!!\n");

		}
	}
}
void listItems(const struct Item item[], int NoOfItems) {

	int i = 0;
	double grandTotal = 0;


	printTitle();

	for (i = 0; i < NoOfItems; i++) {
		displayItem(item[i], 1);

	}

	printFooter(grandTotal);

}

int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index){
	
	int i = 0;

	for (i = 0; i < NoOfRecs; i++) {

		if (sku == item[i].sku) {

			*index = i;
			return 1;
		}

		else {
			return 0;
		}

	}


}

int main() {
	struct Item I[21] = {
		{ 4.4,275,0,10,2,"Royal Apples" },
		{ 5.99,386,0,20,4,"Watermelon" },
		{ 3.99,240,0,30,5,"Blueberries" },
		{ 10.56,916,0,20,3,"Seedless Grapes" },
		{ 2.5,385,0,5,2,"Pomegranate" },
		{ 0.44,495,0,100,30,"Banana" },
		{ 0.5,316,0,123,10,"Kiwifruit" },
		{ 4.49,355,1,20,5,"Chicken Alfredo" },
		{ 5.49,846,1,3,5,"Veal Parmigiana" },
		{ 5.29,359,1,40,5,"Beffsteak Pie" },
		{ 4.79,127,1,30,3,"Curry Checken" },
		{ 16.99,238,1,10,2,"Tide Detergent" },
		{ 10.49,324,1,40,5,"Tide Liq. Pods" },
		{ 10.99,491,1,50,5,"Tide Powder Det." },
		{ 3.69,538,1,1,5,"Lays Chips S&V" },
		{ 3.29,649,1,15,5,"Joe Org Chips" },
		{ 1.79,731,1,100,10,"Allen's Apple Juice" },
		{ 6.69,984,1,30,3,"Coke 24 Pack" },
		{ 7.29,350,1,50,5,"Nestea 24 Pack" },
		{ 6.49,835,1,20,2,"7up 24 pack" }
	};

	double val;
	int ival;
	int searchIndex;
	val = totalAfterTax(I[0]);
	printf("totalAfterTax:\n"
		"    yours=%lf\n"
		"program's=44.000000\n", val);
	val = totalAfterTax(I[7]);
	printf("totalAfterTax:\n"
		"    yours=%lf\n"
		"program's=101.474000\n", val);
	ival = isLowQuantity(I[0]);
	printf("isLowQuantity:\n"
		"    yours=%d\n"
		"program's=0\n", ival);
	ival = isLowQuantity(I[14]);
	printf("isLowQuantity:\n"
		"    yours=%d\n"
		"program's=1\n", ival);
	pause();

	printf("itemEntry, enter the following values:\n");
	printf("        SKU: 999\n"
		"       Name: Red Apples\n"
		"      Price: 4.54\n"
		"   Quantity: 50\n"
		"Minimum Qty: 5\n"
		"   Is Taxed: n\n");
	printf("Enter the values:\n");
	I[20] = itemEntry(999);
	printf("displayItem, Linear:\nYours: ");
	displayItem(I[20], LINEAR);
	printf(" Prog: |999|Red Apples          |    4.54|   No|  50 |   5 |      227.00|\n");
	printf("displayItem, Form:\nYours:\n");
	displayItem(I[20], FORM);
	printf("Programs: \n");
	printf("        SKU: 999\n"
		"       Name: Red Apples\n"
		"      Price: 4.54\n"
		"   Quantity: 50\n"
		"Minimum Qty: 5\n"
		"   Is Taxed: No\n");
	I[20].quantity = 2;
	I[20].isTaxed = 1;
	pause();

	printf("displayItem, Linear with low value and taxed:\nYours: ");
	displayItem(I[20], LINEAR);
	printf(" Prog: |999|Red Apples          |    4.54|  Yes|   2 |   5 |       10.26|***\n");
	printf("displayItem, Form with low value:\nYours:\n");
	displayItem(I[20], FORM);
	printf("Programs: \n");
	printf("        SKU: 999\n"
		"       Name: Red Apples\n"
		"      Price: 4.54\n"
		"   Quantity: 2\n"
		"Minimum Qty: 5\n"
		"   Is Taxed: Yes\n"
		"WARNING: Quantity low, please order ASAP!!!\n");
	pause();

	printf("Listing Items: \n");
	listItems(I, 21);
	pause();
	printf("Locate Item, successful search:\n");
	printf("program: Found the item 999 at index: 20\n");
	printf("  Yours: ");
	if (locateItem(I, 21, 999, &searchIndex)) {
		printf("Found the item 999 at index: %d\n", searchIndex);
	}
	else {
		printf("No item with the sku 999 is in the array!\n");
	}

	printf("Locate Item, unsuccessful search:\n");
	printf("Progam: No item with the sku 732 is in the array!\n");
	printf(" Yours: ");
	if (locateItem(I, 21, 732, &searchIndex)) {
		printf("Found the item at index: %d\n", searchIndex);
	}
	else {
		printf("No item with the sku 732 is in the array!\n");
	}
	return 0;
}
