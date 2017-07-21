#include<stdio.h>

#define MAX_TITLE_SIZE 21

struct Book {

	char _title[MAX_TITLE_SIZE];
	int _isbn;
	int _year;
	int _qty;
	double _price;
};

void menu();
int readRecord(FILE *fp, struct Book *b2read);

void displayInventory(const char filename[]);

int readRecord(FILE *fp, struct Book *b2read) {

	struct Book book;

	int rv = 0;

	if (fp != NULL) {

		rv = fscanf(fp, "%d;%lf;%d;%d; %20[^\n]", &book._isbn, &book._price, &book._qty, &book._year, book._title);


		fclose(fp);
	}

	printf("%d", rv);
	return rv;

}

void displayInventory(const char filename[]) {

	struct Book book = { { 0 } };

	int rv = 0;

	FILE *fp = NULL;

	fp = fopen("test.txt", "r");

	rv = readRecord(fp, &book);


	printf("%d", rv);

	rewind(fp);

	if (rv == 5) {
		fp = fopen("test.txt", "r");

		while (fscanf(fp, "%d;%lf;%d;%d; %20[^\n]", &book._isbn, &book._price, &book._qty, &book._year, book._title) != EOF) {
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book._isbn, book._title, book._year, book._price, book._qty);

		}
		fclose(fp);
	}


}

int main() {

	struct Book mybook; //An object of struct Book 
	char filename[] = "144_w9_inventory.txt"; //Name of the file

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

		case 4: //Calculate capital
				//calculateCapital(filename);
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
