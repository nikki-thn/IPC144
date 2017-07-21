#include<stdio.h>

#define MAX_TITLE_SIZE 21

struct Book {

	char _title[MAX_TITLE_SIZE];
	int _isbn;
	int _year;
	int _qty;
	double _price;
};

//int readRecord(FILE *fp, struct Book *b2read);


int readRecord(FILE *fp, struct Book *b2read) {

	struct Book book;

	int rv = 0;
	


	if (fp != NULL) {

		rv = fscanf(fp, "%d;%lf;%d;%d; %20[^\n]", &book._isbn, &book._price, &book._qty, &book._year, book._title);
		rewind(fp);

		while (fscanf(fp, "%d;%lf;%d;%d; %20[^\n]", &book._isbn, &book._price, &book._qty, &book._year, book._title) != EOF) {
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book._isbn, book._title, book._year, book._price, book._qty);
	
		}

		fclose(fp);
	}
	
		printf("%d", rv);
		return rv;

	}

int main() {

	struct Book book = { { 0 } };

	FILE *fp = NULL;

	fp = fopen("test.txt", "r");

	readRecord(fp, &book);

	return 0;
}
