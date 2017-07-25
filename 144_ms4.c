/*
Name: Nikki Truong
ID: 112 314 174
IPC144 - Section H
Milestone Project - Part 3
*/

/* Part 4 */

#include<stdio.h>

#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100
#define MAX_ITEM_NO 500
#define DATAFILE "144_fp_items.txt"


//declare constants
const double TAX = 0.13;
const int SIZE = 20;

//declare struct Item type 
struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};


// tester prototypes
void searchTest();
void updateTest();
void addTest();
void addOrUpdateTest();
void adjustQtyTest();


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

double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);

void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(const struct Item item[], char fileName[], int NoOfRecs);
int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr);


// application user interface function PROTOTYPES:
int yes(void);
void GroceryInventorySystem(void);
int menu(void);

// PART 1

// Print welcome message
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
	flushKeyboard();

	//This loop will check user input and only stop when y or n was entered
	while (yesOrNo != 'y' && yesOrNo != 'Y' && yesOrNo != 'n' && yesOrNo != 'N') {

		printf("Only (Y)es or (N)o are acceptable: ");
		scanf(" %c", &yesOrNo);
		flushKeyboard();

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


//PART 2 started

//This function calculate the total of each item with or without tax and return the total
double totalAfterTax(struct Item item) {

	double totalAfterTax = 0;

	if (item.isTaxed == 1) {

		totalAfterTax = (item.price * item.quantity) * (1 + TAX);
	}

	else if (item.isTaxed == 0) {

		totalAfterTax = (item.price * item.quantity);

	}

	return totalAfterTax;
}


//This function check if item quantity is lower than minimum requirement and return 1 or 0
int isLowQuantity(struct Item item) {

	int isLow = 0;

	if (item.quantity <= item.minQuantity) {

		isLow = 1;

	}

	else if (item.quantity > item.minQuantity) {

		isLow = 0;

	}

	return isLow;
}


//Function itemEntry will scan in data for struct item by utilize previous function
struct Item itemEntry(int sku) {

	struct Item item;

	printf("        SKU: %d\n", sku);

	item.sku = sku;

	printf("       Name: ");
	scanf("%20[^\n]", item.name);
	flushKeyboard();

	printf("      Price: ");
	item.price = getDouble();

	printf("   Quantity: ");
	item.quantity = getInt();

	printf("Minimum Qty: ");
	item.minQuantity = getDouble();

	printf("   Is Taxed: ");
	item.isTaxed = yes();

	return item;

}


//Function displays items in two forms: linear and non-linear
void displayItem(struct Item item, int linear) {

	double totalPrice = 0;
	int lowQuantity = 0;
	int taxDisplay = 0;

	totalPrice = totalAfterTax(item);
	lowQuantity = isLowQuantity(item);

	//This is the linear form, we divide further into two cases: low quantity and normal quantity
	if (linear == 1) {

		printf("|%3d|%-20s|%8.2lf|", item.sku, item.name, item.price);

		taxDisplay = item.isTaxed;

		if (taxDisplay == 1) {
			printf("  Yes|");
		}
		else if (taxDisplay == 0) {
			printf("   No|");
		}

		printf(" %3d | %3d |%12.2lf|", item.quantity, item.minQuantity, totalPrice);


		//when quantity is low, print *** in attn colum to alert user
		if (lowQuantity == 1) {

			printf("***\n");
		}

		else if (lowQuantity == 0) {
			printf("\n");
		}

	}
	//Display item in non-linear form, again we divide it in two cases
	if (linear == 0) {

		printf("        SKU: %d\n       Name: %s\n      Price: %.2lf\n   Quantity: %d\n", item.sku, item.name, item.price, item.quantity);
		printf("Minimum Qty: %d\n", item.minQuantity);

		taxDisplay = item.isTaxed;

		if (taxDisplay == 1) {

			printf("   Is Taxed: Yes\n");

		}

		else if (taxDisplay == 0) {

			printf("   Is Taxed: No\n");

		}

		//when quantity is low, show alert message
		if (lowQuantity == 1) {

			printf("WARNING: Quantity low, please order ASAP!!!\n");

		}
	}
}

//listItems utilize displayItem function to show entries up to number noOfItems as specified by user
void listItems(const struct Item item[], int noOfItems) {

	double grandTotal = 0;
	int n = 0;

	printTitle();

	for (n = 0; n < noOfItems; n++) {

		printf("%-3d ", n + 1);
		displayItem(item[n], 1);
	}

	printFooter(grandTotal);
}

/* locateItem function will take parameters from caller, look for item's sku that is matched and store its index
and return 1 or 0 to indicate the success of the search */
int locateItem(const struct Item item[], int NoOfRecs, int sku, int*index) {

	int i = 0;
	int value = 0;

	for (i = 0; i < NoOfRecs; i++) {

		if (item[i].sku == sku) {

			*index = i;
			value = 1;

		}

		else if (item[i].sku != sku) {

			value = 0;
		}

	}

	return value;
}



// PART 3 STARTED

// This function will look for item's sku from user input and displaay match or error message
void search(const struct Item item[], int NoOfRecs) {

	int i = 0;
	int found = -1;
	int sku = 0;

	printf("Please enter the SKU: ");
	sku = getInt();

	for (i = 0; i < NoOfRecs; i++) {

		//When match is found, record index and pass to caller
		if (item[i].sku == sku) {

			found = i;
		}

	}

	if (found >= 0) {

		displayItem(item[found], 0);

	}

	else if (found < 0) {

		printf("Item not found!\n");
	}

}


//This function is to update data by overwrite existing data
void updateItem(struct Item* itemptr) {

	struct Item temp;
	int ans = 0;

	printf("Enter new data:\n");

	temp = itemEntry(itemptr->sku);

	//ask user to confirm overwrite
	printf("Overwrite old data? (Y)es/(N)o: ");

	ans = yes();

	if (ans == 1) {

		*itemptr = temp;

		printf("--== Updated! ==--\n");
	}

	else if (ans == 0) {

		printf("--== Aborted! ==--\n");

	}

}

//addItem will check if storage is full before adding new data to the struct Item
void addItem(struct Item item[], int *NoOfRecs, int sku) {

	struct Item temp;
	int ans = 0;
	int count = *NoOfRecs;

	//When storage is full, display message
	if (count == MAX_ITEM_NO) {

		printf("Can not add new item; Storage Full!\n");

	}

	//when storage is not full, proceed to get new data
	else if (count < MAX_ITEM_NO) {

		temp = itemEntry(sku);

		printf("Add Item? (Y)es/(N)o: ");
		ans = yes();

		if (ans == 1) {

			item[count] = temp;

			printf("--== Added! ==--\n");

			count++;

			*NoOfRecs = count;
		}

		else if (ans == 0) {

			printf("--== Aborted! ==--\n");

		}

	}
}

/* This function is used to add new data (when sku is not already in struct
or update existing data if sku is already found in struct */
void addOrUpdateItem(struct Item item[], int* NoOfRecs) {

	int sku = 0;
	int ans = 0;
	int found = -1;


	int i = 0;

	printf("Please enter the SKU: ");

	sku = getIntLimited(SKU_MIN, SKU_MAX);

	for (i = 0; i < *NoOfRecs; i++) {

		//When match is found, record index and pass to caller
		if (item[i].sku == sku) {

			found = i;
		}

	}

	//If item is found, update item
	if (found >= 0) {

		displayItem(item[found], 0);

		printf("Item already exists, Update? (Y)es/(N)o: ");
		ans = yes();


		if (ans == 1) {
			updateItem(&item[found]);
		}

		if (ans == 0) {

			printf("--== Aborted! ==--\n");
		}

	}

	//If item is not found, create a new one by calling addItem

	else if (found == -1) {

		addItem(item, NoOfRecs, sku);
	}

}


/* This function will adjust quantity of item by subtract quantity if checkout or f
by adding to quantity if stock */
void adjustQuantity(struct Item item[], int NoOfRecs, int stock) {

	int sku = 0;
	int checkedOut = 0;
	int found = -1;
	int stocked = 0;
	int isLow = 0;

	int i = 0;

	printf("Please enter the SKU: ");

	sku = getIntLimited(SKU_MIN, SKU_MAX);

	for (i = 0; i < NoOfRecs; i++) {

		//When match is found, record index and pass to caller
		if (item[i].sku == sku) {

			found = i;
		}

	}

	//Proceed when sku is valid / already existed in the struct
	if (found >= 0) {

		displayItem(item[found], 0);

		//Checkout by subtract from existing quantity
		if (stock == 0) {

			printf("Please enter the quantity to checkout; Maximum of %d or 0 to abort: ", item[found].quantity);
			checkedOut = getIntLimited(0, item[found].quantity);

			if (checkedOut == 0) {

				printf("--== Aborted! ==--\n");

			}

			else if (checkedOut > 0) {

				printf("--== Checked out! ==--\n");

				item[found].quantity -= checkedOut;

				isLow = isLowQuantity(item[found]);

				if (isLow == 1) {

					printf("Quantity is low, please reorder ASAP!!!\n");
				}


			}

		}

		//Stock by adding to existing quantity
		else if (stock == 1) {

			printf("Please enter the quantity to stock; Maximum of %d or 0 to abort: ", MAX_QTY - item[found].quantity);
			stocked = getIntLimited(0, MAX_QTY - item[found].quantity);

			if (stocked == 0) {

				printf("--== Aborted! ==--\n");

			}

			else if (stocked > 0) {

				printf("--== Stocked! ==--\n");

				item[found].quantity += stocked;

			}

		}

	}

	//If item not found, display error message
	else if (found == -1) {

		printf("SKU not found in storage!\n");

	}

}


/* PART 4 */

void saveItem(struct Item item, FILE* dataFile) {

	//printf("Elements are followed %d,%d,%d,%.2lf,%c,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);

	fprintf(dataFile, "%d,%d,%d,%.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);
}



int loadItem(struct Item* temp, FILE* dataFile) {

	int isTrue = 0;

	int rv = 0;

	struct Item item = { 0 };

	rv = fscanf(dataFile, "%d,%d,%d,%lf,%d, %20[^\n]", &item.sku, &item.quantity, &item.minQuantity, &item.price, &item.isTaxed, item.name);
	
	if (rv == 6) {

		isTrue = 1;
	}

	*temp = item;

	return isTrue;


}



int saveItems(const struct Item item[], char fileName[], int NoOfRecs) {

	int isTrue = 1;
	int i = 0;

	int rv = 1;

	FILE *fp = fopen(fileName, "w+");

	if (fp != NULL) {

		for (i = 0; i < NoOfRecs; i++) {

			saveItem(item[i], fp);

		}
	}

	else if (fp == NULL) {

		rv = 0;
	}

	fclose(fp);

	return rv;

}



int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr) {

	int count = *NoOfRecsPtr;

	//printf("count %d\n", count);

//	printf("noRecs %d\n", *NoOfRecsPtr);

	FILE *fp = fopen(fileName, "r");

	//printf("%d,%d,%d,%.2lf,%c,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);

	//printf("is true %d\n", isTrue);

	if (fp != NULL) {

		int i = 0;

		for (i = 0; i < *NoOfRecsPtr + 1; i++) {
			loadItem(&item[i], fp);
		//	printf("%d,%d,%d,%lf,%d, %s\n", item[count].sku, item[count].quantity, item[count].minQuantity, item[count].price, item[count].isTaxed, item[count].name);
			count++;
			printf("count %d\n", count);



		}

		*NoOfRecsPtr = count;

	}

	fclose(fp);

//	printf("%d,%d,%d,%lf,%d, %20[\n]\n", item[count].sku, item[count].quantity, item[count].minQuantity, item[count].price, item[count].isTaxed, item[count].name);


	//printf("count %d\n", count);

	printf("noRecs %d\n", *NoOfRecsPtr);

	return 1;

}



void prnFile() {
	FILE* tp = fopen("test.txt", "r");
	char ch;
	if (tp) {
		for (; fscanf(tp, "%c", &ch) == 1; putchar(ch));
		fclose(tp);
	}
	else {
		printf("test.txt not found\n");
	}
}


int main(void) {

	int i, n = 0;

	struct Item GI[3] = {
		{ 4.4,275,0,10,2,"Royal Gala Apples" },
		{ 5.99,386,0,20,4,"Honeydew Melon" },
		{ 3.99,240,0,30,5,"Blueberries" },
	};

	struct Item I;
	struct Item IN[3];

	printf("***********Testing saveItem:\n");
	printf("Your saveItem saved the following in test.txt: \n");

	FILE* tp = fopen("test.txt", "w");

	if (tp) {

		for (i = 0; i < 3; i++) saveItem(GI[i], tp);
		fclose(tp);
		prnFile();
	}

	printf("*******************************\nThey have to match the following:\n");
	printf("275,10,2,4.40,0,Royal Gala Apples\n");
	printf("386,20,4,5.99,0,Honeydew Melon\n");
	printf("240,30,5,3.99,0,Blueberries\n");
	printf("***********END Testing saveItem!\n\n\n");

	pause();


//==================GOOD

	printf("***********Testing loadItem:\n");
	printf("Your loadItem loaded the following from test.txt: \n");
	tp = fopen("test.txt", "r");

	if (tp) {
		for (i = 0; i < 3; i++) {
			loadItem(&I, tp);
			displayItem(I, LINEAR);
		}

		fclose(tp);
		tp = fopen("test.txt", "w");
		fclose(tp);
	}

	printf("*******************************\nThey have to match the following:\n");
	printf("|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|\n");
	printf("|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|\n");
	printf("|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|\n");
	printf("***********END Testing loadItem!\n\n\n");

	pause();

	//==================GOOD

	printf("***********Testing saveItems:\n");
	printf("Your saveItems saved the following in test.txt: \n");
	saveItems(GI, "test.txt", 3);
	prnFile();

	printf("*******************************\nThey have to match the following:\n");
	printf("275,10,2,4.40,0,Royal Gala Apples\n");
	printf("386,20,4,5.99,0,Honeydew Melon\n");
	printf("240,30,5,3.99,0,Blueberries\n");
	printf("***********END Testing saveItems!\n\n\n");
	pause();


	//================++GOOD

	printf("***********Testing loadItems:\n");
	printf("Your loadItems loaded the following from test.txt: \n");
	loadItems(IN, "test.txt", &n);

	for (i = 0; i < n; i++) {
		displayItem(IN[i], LINEAR);
	}

	printf("*******************************\nThey have to match the following:\n");
	printf("|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|\n");
	printf("|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|\n");
	printf("|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|\n");
	printf("***********END Testing loadItems!\n\n\n");
	pause();

	printf("Done!\n");

	return 0;
}
