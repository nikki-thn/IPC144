/*
Name: Nikki Truong
Student number: 112 314 174
IPC 144 - Workshop 8 - At home
Section: H
*/

/*This program will perform a book inventory, in which it let user add data, display inventory, search for an item
and price check and search the item by isbn (at-home) */

#include<stdio.h>

#define MAX_TITLE_SIZE 21

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
void displayInventory(const char filename[]);
void addBook(struct Book *book, int *size);
int searchInventory(const struct Book book[], const int isbn, const int size);
void checkPrice(const struct Book book[], const int size);
int searchInventory(const struct Book book[], const int isbn, const int size);
int readRecord(FILE *fp, struct Book *b2read);

int readRecord(FILE *fp, struct Book *b2read){
	//FILE *b2read = NULL;
	//int rv = 0;

	//rv = scanf(fp, b2read);
	//return rv;
}

int main() {

	struct Book mybook; //An object of struct Book 
	char filename[] = "144_w9_inventory.txt"; //Name of the file
//	FILE *b2read = NULL;
//	int rv = 0;

//	rv = scanf(&b2read, &mybook);

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
			displayInventory(filename);
			break;

		case 2: //add data started from the first element of struct array
			addBook(filename, &size);
			break;

		case 3: //find book's price by using isbn number to search
			checkPrice(&mybook, size);
			break;

		case 4: //Calculate capital
			calculateCapital(filename);
			break;

		default: //prompt error message
			printf("Invalid input, try again:\n");
			break;
		}
	}

	return 0;
}


//Menu function print out the menu
void menu() {

	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Calculate total capital of the store.\n");
	printf("0) Exit.\n\n");

}



/*This fuction will bring out the book inventory by taking in the struct and the current size
of number of elements in the struct */

void displayInventory(const char filename[])
{
	struct Book book;
	FILE *fp = NULL;

	printf("\n\nInventory\n");
	printf("===================================================\n");
	printf("ISBN      Title               Year Price  Quantity\n");
	printf("---------+-------------------+----+-------+--------\n");

	fp = fopen(filename, "r");
	if (fp != NULL){
		while (fscanf(fp, "%d;%.2lf;%d;%d;%20s", &book._isbn, &book._price, &book._qty, &book._year, &book._title) != EOF){
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book._isbn, book._title, book._year, book._price, book._qty);
		}
		fclose(fp);
		printf("===================================================\n\n");
	}

	//search function will look through struct book._isbn array and search for a match
	//When match is found, return the index value of the variable

	/*	int searchInventory(const struct Book book[], const int isbn, const int size) {

			int i = 0;
			int found = -1;

			for (i = 0; i < size; i++) {

			//When match is found, record index and pass to caller
			if (book[i]._isbn == isbn) {

			found = i;
			}

			}

			return found;

			//Define an object of struct Book


			//Open the file, and check for null pointer


			//If the file is properly opened, display headers, similar to workshop 8



			//Use a while loop to call readRecord and display the records.
			//while (/*call readRecord and check its return value
			//display the record



			//Display the footer

			//Close the file

			}





			void addBook(const char filename[], struct Book *b2Add)
			{

			int count = *size;
			int isFound = 0;
			int isbn = 0;

			printf("ISBN:");
			scanf("%d", &isbn);

			isFound = searchInventory(book, isbn, MAX_BOOKS);

			if (isFound >= 0) {

			int newQty = 0;

			printf("Quantity:");
			scanf("%d", &newQty);
			book[isFound]._qty += newQty;
			printf("The book exists in the repository, quantity is updated.\n\n");

			}

			else if (isFound < 0) {


			//printf("isbn %d, _isbn %d", isbn, book[count]._isbn);

			if (*size == MAX_BOOKS) {

			printf("The inventory is full.\n");

			}

			else if (*size < MAX_BOOKS) {

			book[count]._isbn = isbn;

			printf("Quantity:");
			scanf("%d", &book[count]._qty);

			printf("Title:");
			scanf(" %20[^\n]", book[count]._title);

			printf("Year:");
			scanf("%d", &book[count]._year);

			printf("Price:");
			scanf("%lf", &book[count]._price);

			printf("The book is successfully added to the inventory.\n\n");

			count++;
			*size = count;

			}
			}
			}

			void checkPrice(const char filename[], const int isbn2find)
			{


			int isbn = 0;
			int isFound = -1;

			printf("Please input the ISBN number of the book:\n\n");
			scanf("%d", &isbn);

			//call searchInventory function to get index if item is found
			isFound = searchInventory(book, isbn, MAX_BOOKS);

			if (isFound >= 0) {

			printf("Book %d costs $%.2lf\n\n", isbn, book[isFound]._price);
			}

			//if item is not found, prompt error message
			else if (isFound < 0) {

			printf("Book does not exist in the bookstore! Please try again.\n\n");

			}


			}

			int searchInventory(FILE *fp, const int isbn2find)
			{
			//Not implemented!
			}
			*/

	float calculateCapital(const char filename[])
	{
	
	struct Book book;

	float total_capital = 0;

	total_capital = total_capital + book._price* book._qty;
}
	//Define and initialize total_capital


	//Open the file, and check for null pointer


	//If the file is properly opened, use a while loop to call readRecord
	//while (/*call readRecord and check its return value*/)
		//Accumulate the multiplication of the price of each item to its quantity



		//Display the footer

		//Close the file

		//return the total_capital


int readRecord(FILE *fp, struct Book *b2read)
{
	//Define a variable int rv = 0

	rv = fscanf(/*Type your code here*/);

	//return rv;

}
