/*
Name: Nikki Truong
Student number: 112 314 174
IPC 144 - Workshop 9 - At home
Section: H
*/

/*This program will open a file, scan in information, display them and calculate the total capital
of the bookstore*/

#include<stdio.h>

#define MAX_TITLE_SIZE 21


struct Book {

	char _title[MAX_TITLE_SIZE];
	int _isbn;
	int _year;
	int _qty;
	double _price;
};

//Functions prototypes go here

void menu();
int readRecord(FILE *fp, struct Book *b2read);
void displayInventory(const char filename[]);
float calculateCapital(const char filename[]);

//int searchInventory(FILE *fp, const int isbn2find);
void addBook(const char filename[], struct Book *b2Add);
//void checkPrice(const char filename[], const int isbn2find);



int searchInventory(FILE *fp, const int isbn2find) {

	struct Book book = { { 0 } };

	int found = -1;

	while (fscanf(fp, "%d;%lf;%d;%d; %20[^\n]", &book._isbn, &book._price, &book._year, &book._qty, book._title) != EOF) {
		if (book._isbn == isbn2find)
		{
			found = 1;
			printf("Book %d costs $%.2f\n\n", isbn2find, book._price);
		}

	}

	fclose(fp);

	//Define an object of struct Book and other necessary variables

	//If the file ponter is not NULL:
	//as long as the record is not found,
	//use the function readRecord to read the recods and look for isbn2find
	return found;
}


void checkPrice(const char filename[], const int isbn2find) {

	int found = 0;

	FILE *fp = NULL;


	fp = fopen(filename, "r");

	found = searchInventory(fp, isbn2find);

	if (found == -1) {

		printf("Book does not exist in inventory\n");
	}


}



void addBook(const char filename[], struct Book *b2Add)
{
	struct Book book = { { 0 } };

	int found = 0;

	int isbn = 0;

	FILE *fp = NULL;

	fp = fopen(filename, "a+");

	printf("ISBN: ");
	scanf("%d", &isbn);


	printf("Title:");
	scanf(" %20[^\n]", book._title);

	printf("Year:");
	scanf("%d", &book._year);

	printf("Price:");
	scanf("%lf", &book._price);

	printf("Quantity:");
	scanf("%d", &book._qty);


	found = searchInventory(fp, isbn);

	rewind(fp);

	printf("found %d", found);
	if (found == -1) {


		fp = fopen(filename, "a+");

		book._isbn = isbn;
		printf("The book is successfully added to the inventory.\n\n");

		fprintf(fp, "%d;%lf;%d;%d; %s\n", book._isbn, book._price, book._year, book._qty, book._title);
		fclose(fp);


	}

	if (found == 1) {

		printf("The book exists in the repository!\n\n");
	}
}
//put bookstore_v2_at_home.c

//Menu function print out the menu
void menu() {

	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Calculate total capital of the store.\n");
	printf("0) Exit.\n\n");

}


/*This function will scan through the files and make sure there are 5 sucessful scan with given format
and pass the number of successful scan to caller*/

int readRecord(FILE *fp, struct Book *b2read) {

	struct Book book;

	int rv = 0;

	//If the file is not empty, scan the data
	if (fp != NULL) {

		rv = fscanf(fp, "%d;%lf;%d;%d; %20[^\n]", &book._isbn, &book._price, &book._year, &book._qty, book._title);

		fclose(fp);
	}

	return rv;

}


//This function will display the inventory when readRecoed function return 5 sucessful scans
void displayInventory(const char filename[]) {

	struct Book book = { { 0 } };

	int rv = 0;

	FILE *fp = NULL;

	fp = fopen(filename, "r");

	rv = readRecord(fp, &book);

	rewind(fp);

	//If condition was met, display entries
	if (rv == 5) {
		fp = fopen(filename, "r");

		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");

		while (fscanf(fp, "%d;%lf;%d;%d; %20[^\n]", &book._isbn, &book._price, &book._year, &book._qty, book._title) != EOF) {
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book._isbn, book._title, book._year, book._price, book._qty);

		}

		printf("===================================================\n\n");

		fclose(fp);
	}


}


//This function will calculate the total capital of current inventory
float calculateCapital(const char filename[]) {

	struct Book book;
	float total_capital = 0;

	int rv = 0;

	FILE *fp = NULL;

	fp = fopen(filename, "r");

	rv = readRecord(fp, &book);

	rewind(fp);

	//Again, when readRecord is good, perform the calculation
	if (rv == 5) {

		fp = fopen(filename, "r");

		while (fscanf(fp, "%d;%lf;%d;%d; %20[^\n]", &book._isbn, &book._price, &book._year, &book._qty, book._title) != EOF) {
			total_capital = total_capital + book._qty * book._price;

		}

		fclose(fp);
	}

	printf("The total capital is: $%.2lf.\n\n", total_capital);

	return total_capital;

}


int main() {

	struct Book mybook; //An object of struct Book 
	char filename[] = "144_w9_inventory.txt"; //Name of the file

	int flag = 0;
	int option;
	int isbn = 0;

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

		case 2: //add new item to inventory
			addBook(filename, &mybook);
			break;

		case 3: //Check price of an item

			printf("Please input the ISBN number of the book:\n\n");
			scanf("%d", &isbn);
			checkPrice(filename, isbn);
			break;

		case 4: //Calculate total capital
			calculateCapital(filename);
			break;

		default: //prompt error message
			printf("Invalid input, try again:\n");
			break;

		}
	}

	return 0;
}
