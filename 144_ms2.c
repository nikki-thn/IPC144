/*
Name: Nikki Truong
ID: 112 314 174
IPC144 - Section H
Milestone Project - Part 2
*/


#include <stdio.h>

#define LINEAR 1
#define FORM 0

const TAX = 0.13;
const SIZE = 20;

struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};

double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

void flushKeyboard(void) {

	while (getchar() != '\n')
		;
}

double totalAfterTax(struct Item item) {
	double totalAfterTax = 0;

	if (item.isTaxed == 1) {
		//printf("Quanity: %d, Price: %.2lf", item.price, item.quantity);
		totalAfterTax = (item.price * item.quantity) * (1 + TAX);
	}
	else if (item.isTaxed == 0) {
		totalAfterTax = (item.price * item.quantity);

	}

	return totalAfterTax;
}



int isLowQuantity(struct Item item) {

	if (item.quantity < item.minQuantity) {
		return 1;
	}
	else if (item.quantity >= item.minQuantity) {
		return 0;
	}

}

struct Item itemEntry(int sku) {

	struct Item item;

	int i = 0;

	for (i = 0; i < 1; i++) {


		printf("        SKU: %d\n", sku);

		item.sku = sku;

		printf("       Name: ");
		scanf("%20s", &item.name);
		flushKeyboard();

		printf("      Price: ");
		scanf(" %lf", &item.price);

		printf("   Quantity: ");
		scanf(" %d", &item.quantity);

		printf("Minimun Qty: ");
		scanf(" %d", &item.minQuantity);

		printf("   Is taxed: ");
		scanf(" %d", &item.isTaxed);
	}

	return item;
}

void displayItem(struct Item item, int linear) {

	double totalPrice;
	int lowQuantity;

	totalPrice = totalAfterTax(item);
	lowQuantity = isLowQuantity(item);

	if (linear == 1) {

		if (lowQuantity == 0) {
			printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
			printf("|%3d|%3d|%20s|%8.2lf|  %3d| %3d |%3d  |%12.2lf|\n", 1, item.sku, item.name, item.price, item.isTaxed, item.quantity, item.minQuantity, totalPrice);
		}
		else if (lowQuantity == 1) {
			printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
			printf("|%3d|%3d|%20s|%8.2lf|  %3d| %3d |%3d  |%12.2lf|***\n", 1, item.sku, item.name, item.price, item.isTaxed, item.quantity, item.minQuantity, totalPrice);
		}
	}

	else if (linear == 0) {
		if (lowQuantity == 0) {

			printf("        SKU: %d\n       Name: %s\n      Price: %.2lf\n    Quanity: %d\n", item.sku, item.name, item.price, item.quantity);
			printf("Minimun Qty: %d\n   Is Taxed: %d\n\n", item.minQuantity, item.isTaxed);
		}
		else if (lowQuantity == 1) {

			printf("        SKU: %d\n       Name: %s\n      Price: %.2lf\n    Quanity: %d\n", item.sku, item.name, item.price, item.quantity);
			printf("Minimun Qty: %d\n   Is Taxed: %d\n\n", item.minQuantity, item.isTaxed);
			printf("WARNING: QUantity low, please order ASAP!!!\n\n");

		}
	}
}


void listItems(const struct Item item[], int noOfItems) {

	double grandTotal = 0;

	int n = 0;
	for (n = 0; n < noOfItems; n++) {
		printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
		printf("|%3d|%3d|%20s|%8.2lf|  %3d| %3d |%3d  |%12.2lf|\n", 1, item[n].sku, item[n].name, item[n].price, item[n].isTaxed, item[n].quantity, item[n].minQuantity);

	}

}

int locateItem(const struct Item item[], int NoOfRecs, int sku, int*index) {

	int i = 0;
	for (i = 0; i < NoOfRecs; i++) {

		//printf("item %d has sku: %d\n", i, item[i].sku);

		if (item[i].sku == sku) {
			index = &item;
			printf("%x", index);
			printf("Item found\n");
			return 1;
		}
	}

			return 0;
	}


int main() {

	int sku = 0;
	struct Item item[SIZE] = {
		//price, SKU, isTaxed, Qty, minQty, name;
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


	
		printf("Enter SKU: ");
	
		scanf("%d", &sku);
		int *index = NULL;
		int found;

		//found = locateItem(item, 20, sku, NULL);
		
		/*int i = 0;
		for (i = 0; i < 1; i++) {

			printf("Enter SKU: ");

			scanf("%d", &sku);

			item[i] = itemEntry(sku);

		}
		*/

		//listItems(item, 10);

		//printf("Value return: %d\n", found);

	

	return 0;
}
