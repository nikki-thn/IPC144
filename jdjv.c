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

int main() {

	struct Book book [MAX_BOOKS] = { {0} };

	int count = 0;

		printf("ISBN: ");
		scanf("%d", &book[0]._isbn);
		printf("Year: ");
		scanf("%d", &book[0]._year);
		
		printf("Price: ");
		scanf("%lf", &book[0]._price);
		printf("Quantity: ");
		scanf("%d", &book[0]._qty);
		printf("Title: ");

		scanf(" %20[^\n]s", &book[0]._title);
		printf("The book is successfully added to the inventory\n");
		count++;
		printf("%d \n", count);
	

	int i = 0;
	for (i < 0; i < count; i++) {
		printf("isbn: %d, title: %s, year: %d , price : %.2lf, qty %d \n", book[i]._isbn, book[i]._title, book[i]._year, book[i]._price, book[i]._qty);
	}

	return 0;
}
