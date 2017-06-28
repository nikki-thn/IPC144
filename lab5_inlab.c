/*
Name: Nikki Truong
Student number: 112314174
Workshop 5 - Section H
*/

#include <stdio.h>

// Define Number of Employees "SIZE" to be 2
#define SIZE 2

// Declare Struct Employee 
struct emp {
	int id;
	int age;
	double salary;
};

int main(void) {

	int option = 0;
	int num = 0;

	printf("---=== EMPLOYEE DATA ===---\n\n");

	// Declare a struct Employee array "emp" with SIZE elements and initialize all elements to zero
	struct emp company[SIZE] = { 0 };


	do {

		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");

		// Capture input to option variable
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {

		case 0:	// Exit the program
			break;

		case 1: // Display Employee Data
			// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			// display employee id, age and salary using a loop construct 
			// The loop construct will be SIZE times and will only display employee data 
			// where the EmployeeID is > 0

			for (m = 0; m < num; m++) {
				printf("%6d%9d%11.2lf\n", company[m].id, company[m].age, company[m].salary);
			}
			printf("\n");


			break;

		case 2:	// Adding Employee
			// @IN-LAB

			printf("Adding Employee\n");
			printf("===============\n");

			// Check for limits on the array and add employee data accordingly

			if (num < SIZE) {
				printf("Enter Empployee ID: ");
				scanf("%d", &company[num].id);
				printf("Enter Employee Age: ");
				scanf("%d", &company[num].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &company[num].salary);
				printf("\n");
				num++;
			}

			else if (num >= SIZE) {
				printf("ERROR!!! Maximum Number of Employees reached\n\n");
			}

			break;


		default:
			//if user put none of the option, display error message
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}


	} while (option != 0);


	//Exit message
	printf("Existing Employee Data Program. Good Bye!!!\n");



	return 0;
}
