/*
Name: Nikki Truong
Student number: 112 314 174
IPC 144 - Workshop 8 - In lab
Section: H
*/

/*This program will perform a book inventory, in which it let user add data, display inventory, search for an item 
and price check (at-home) */

#include<stdio.h>

#define MAX_BOOKS 2
#define MAX_TITLE_SIZE 20

//declare struct Book type which hold books information
struct Book {

	char _title[MAX_TITLE_SIZE];
	int _isbn;
	int _year;
	int _qty;
	double _price;
};

//Function prototypes go here
void menu();
void displayInventory(struct Book book[], int size);
void addBook(struct Book *book, int *size);
int searchInventory(const struct Book book[], const int isbn, const int size);
void checkPrice(const struct Book book[], const int size);

//Menu function print out the menu
void menu() {

	printf("Please select from the following option: \n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("0) Exit.\n\n");

}

/*This fuction will bring out the book inventory by taking in the struct and the current size
of number of elements in the struct */ 
void displayInventory(struct Book book[], int size) {

	int i = 0;
	if (size == 0) {
		printf("The inventory is empty!\n");

	}

	else if (size > 0) {
		printf("===================================================\n");
		printf("ISBN      Title               Year Price   Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");
		for (i = 0; i < size; i++) {
			printf("%-10.0d%-20s%-5d\$%-8.2f%-8d\n", book[i]._isbn, book[i]._title, book[i]._year, book[i]._price, book[i]._qty);
		}
	}
	printf("===================================================\n\n");
}

/*addBook function will allow user to input data of the struct by pass-by-address, it 
makes sure current size is less or equal than Maximum space available, then
after successfully scanned in inputs, it will increase the size accordingly*/

void addBook(struct Book *book, int *size) {

	int count = *size;

	if (*size == MAX_BOOKS) {
		printf("The inventory is full.\n");
	}

	if (*size < MAX_BOOKS) {

		printf("ISBN: ");
		scanf("%d", &book[count]._isbn);

		printf("Title: ");
		scanf(" %20[^\n]s", &book[count]._title);

		printf("Year: ");
		scanf("%d", &book[count]._year);

		printf("Price: ");
		scanf("%lf", &book[count]._price);

		printf("Quantity: ");
		scanf("%d", &book[count]._qty);

		printf("The book is successfully added to the inventory\n");

		count++;
		*size = count;

		printf("%d \n", count);
	}

}

int searchInventory(const struct Book book[], const int isbn, const int size){
	int value = 0;


	return value;
}



int main() {

	// An array of Book representing the inventory
	struct Book book [MAX_BOOKS] = { { 0 } };

	int size = 0; //Number of books in the inventory
	int flag = 0;
	int option;

	printf("Welcome to the Book Store\n");
	printf("=========================\n");

	while (flag == 0) {

		menu();
		printf("Select: ");
		scanf("%d", &option);

		switch (option) {

		case 0: //exit program
			printf("Goodbye!\n");
			flag = 1;
			break;

		case 1: //display inventory up to size
			displayInventory(book, size);
			break;

		case 2: //add data started from the first element of struct array
			addBook(&book, &size);
			break;

		default: //prompt error message
			printf("Invalid input, try again:\n");
			break;
		}
	}

	return 0;
}
