/*
Name: Nikki Truong
Student number: 112314174
IPC144 - Section H
Workshop 6 - In-lab
*/

#include <stdio.h>

#define distRate1  0.69			// Rate per Kilometer from 0km to 100km (inclusive)
#define distRate2  0.49			// Rate per Kilometer above 100km 

// Structure Declaration for Vehicle Rentals
struct Rental
{
	int id;						// ID of the Rental Vehicle
	double baseDay;				// Daily Base Price 
	double earnings;			// Total earnings from this rental
};

double addPositive(double, double);

// addPositive function will add newAmount to amount when newAmount is positive
double addPositive(double amount, double newAmount) {

	if (newAmount >= 0) {
		amount += newAmount;
	}

	return amount;
}

int main()
{
	const int noVehicles = 2;			// Number of Vehicles
	int option;							// Variable to store the option selected
	int flag;							// Flag to support vehicle ID find
	int tempID;							// To hold user input for vehicle ID
	int i = 0;							// Variable for "for-loop" counters

	// Initialize the struct Vehicle Rental
	struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 } };

	printf("***** Rental Vehicle Management App *****\n\n");

	do
	{
		// Display the option list
		printf("1.) Rental Status\n");
		printf("2.) Apply Charges\n");
		printf("0.) Log out\n\n");
		printf("Please enter an option to continue: ");

		scanf("%d", &option);

		switch (option)
		{

		case 0: // Exit the program
			break;

		case 1: // Rental Vehicle Status

			printf("\n-- Rental Vehicle Status --\n\n");
			printf("ID#      Earnings\n");
			printf("-------- ----------\n");

			// Print vehical status using for loop
			for (i = 0; i < noVehicles; i++) {
				printf("%8d %10.2lf\n", vRent[i].id, vRent[i].earnings);
			}

			printf("\n");

			break;

		case 2: // Calculate Rental Charges

			flag = -1;
			printf("\n-- Rental Charges --\n\n");
			printf("Enter vehicle ID: ");
			scanf("%d", &tempID);

			// Finding the correct vehicle index
			for (i = 0; i < noVehicles && flag == -1; i++) {
				if (tempID == vRent[i].id) {
					flag = i;
				}
			}

			int rentalDays;
			if (flag != -1) {

				printf("Enter Rental Period (in Days): ");
				scanf("%d", &rentalDays);

				// Calculate the base price (baseDay * Days)
				double basePrice;
				basePrice = vRent[flag].baseDay * rentalDays;

				// Calculate cost for Kilometers driven using "distRate1 & 2 above"
				int drivenKm;
				double kmCost;
				printf("Enter kilometers driven: ");
				scanf("%d", &drivenKm); 

				if (drivenKm <= 100 && drivenKm > 0) {
					kmCost = drivenKm *distRate1;
				}
				else if (drivenKm > 100 && drivenKm > 0) {
					kmCost = (distRate1 * 100) + ((drivenKm - 100) *distRate2);
				}

				// Add base Price and cost for kilometer driven in to a new variable "charge"
				double charge;
				charge = basePrice + kmCost;

				/* Call addPositive function with current earnings for the rental and
				charge(calculated above) as arguments and assign the returned
				result back to earnings */
				vRent[flag].earnings = addPositive(vRent[flag].earnings, charge);

				// Display Base Charge, cost for km and the Total 
				printf("\nBase   kmCost Total\n");
				printf("====== ====== ======\n");
				printf("%6.2lf %6.2lf %6.2lf\n\n", basePrice, kmCost, charge);

			}

			else {
				// If user input an invalid vehicle ID, back to case 2
				printf("ERROR: Vehicle ID does not exist.\n\n");
			}

			break;

		default: // Prompt error message and continue the loop

			printf("Error: Please enter a valid option to continue\n\n");

			break;
		}

	} while (option != 0);

	return 0;
}
