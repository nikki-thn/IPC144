/*
Name: Nikki Truong
Student number: 112 314 174
IPC 144 - Workshop 8 - In lab
Section: H
*/

//This program will 

#include<stdio.h>

#define MAX_BOOKS 2
#define MAX_TITLE_SIZE 21

struct Book {

	char _title[MAX_TITLE_SIZE];
	int _isbn;
	int _year;
	int _qty;
	double _price;
};

void menu();
void displayInventory(struct Book book[], int size);
void searchInventory(const struct Book book[], const int size);
void addBook(struct Book *book, int *size);
void checkPrice(const struct Book book[], const int size);

void menu() {

	printf("Please select from the following option: \n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("0) Exit.\n\n");

}

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

//void searchInventory(const struct Book book[], const int size) {


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

//void checkPrice(const struct Book book[], const int size) { }




int main() {

	struct Book book [MAX_BOOKS] = { { 0 } };
	//{234567, 23.99, 2010, "Harry Potter", 3}
	// An array of Book representing the inventory

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

		case 0:
			printf("Goodbye!\n");
			flag = 1;
			break;

		case 1:

			displayInventory(book, size);

			break;

		case 2:
			addBook(&book, &size);


			break;

		case 3:

			break;

		default:
			printf("Invalid input, try again:\n");
			break;
		}
	}




	return 0;
}
