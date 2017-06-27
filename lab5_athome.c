/*
Name: Nikki Truong
Student number: 112314174
Workshop 5 - Section H
*/

#include <stdio.h>

// Define Number of Employees "SIZE" to be 4 for at_home
#define SIZE 4

// Declare Struct Employee 
struct emp {
	int id;
	int age;
	double salary;
};

int main(void) {

	int option = 0;
	int num = 0;
	int empId = 0;
	int m = 0;
	int l = 0;
	int j = 0;

	printf("---=== EMPLOYEE DATA ===---\n\n");

	// Declare a struct Employee array "emp" with SIZE elements and initialize all elements to zero

	struct emp company[SIZE] = { { 0 } };


	do {

		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
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
				printf("Enter Employee ID: ");
				scanf("%d", &company[num].id);
				printf("Enter Employee Age: ");
				scanf("%d", &company[num].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &company[num].salary);
				printf("\n");
				num++;
			}

			// If limits are met, display error message
			else if (num >= SIZE) {
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}

			break;


		case 3: //Update employee Salary

				//Ask user to input employee ID
			printf("Update Employee Information\n");
			printf("===========================\n");
			printf("Enter Employee ID: ");
			scanf("%d", &empId);

			//Use a loop to go through the array, find the employee we want to replace and update salary
			for (l = 0; l < SIZE; l++) {

				if (company[l].id == empId) {
					printf("The current salary is %.2lf\n", company[l].salary);
					printf("Enter Employee New Salary: ");
					scanf("%lf", &company[l].salary);
					printf("\n");
				}

			}

			break;


		case 4: //Remove employee

				//Prompt from user to input the employee ID
			printf("Remove Employee\n");
			printf("===============\n");
			printf("Enter Employee ID: ");
			scanf("%d", &empId);

			//This for loop will go through the array and search for employee that match user input
			int index;
			for (l = 0; l < num; l++) {

				//when match is found, display a message, store position of the removed element, subtract display element to one
				if (company[l].id == empId) {
					printf("Employee %d will be removed\n\n", empId);
					index = l;
					num--;
				}
			}

			//this loop promote all elements starting at the position of removed element and add one index higher
			//technically this is a reallocation by moving an element higher to replace the deleted one
			for (j = index; j < num; j++) {
				company[j] = company[j + 1];
			}

			break;

		default:
			//if user put none of the option, display error message
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}


	} while (option != 0);


	//Exit message
	printf("Exiting Employee Data Program. Good Bye!!!\n\n");

	return 0;
}
