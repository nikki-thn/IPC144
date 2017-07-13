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
struct Rental {
	int id;						// ID of the Rental Vehicle
	double baseDay;				// Daily Base Price 
	double earnings;			// Total earnings from this rental
};

// Declare functions
double addPositive(double, double);
double taxCalc(double, double);
double subtractPositive(double, double);

// addPositive function will add newAmount to amount when newAmount is positive
double addPositive(double amount, double newAmount) {

	if (newAmount >= 0) {
		amount += newAmount;
	}

	return amount;
}

// taxCalc function will calculate the amount of tax
double taxCalc(double price, double rate) {

	double taxes;
	taxes = price * rate;

	return taxes;
}

// subtractPositive will subtract newAmount from amount when newAmount is positive
double subtractPositive(double amount, double newAmount) {

	if (newAmount >= 0) {
		amount -= newAmount;
	}

	return amount;
}

/* Main program */
int main() {

	const int noVehicles = 3;			// Number of Vehicles [ Changed to 3]
	int option;							// Variable to store the option selected
	int flag;							// Flag to support vehicle ID find
	int tempID;							// To hold user input for vehicle ID
	int i = 0;							// Variable for "for-loop" counters

	// Initialize the struct Vehicle Rental [ New addition for 3 Rentals]
	struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 },{ 125, 29.95, 0 } };

	double taxRate = 0.14;				// Tax rate is 14%
	double discount = 5;    			// Discount amount for rentals (in CAD)

	/*Declare Your Variables Here*/

	int rentalDays;
	double basePrice;
	int drivenKm;
	double kmCost;
	double charge;
	char discountAns;
	double taxes;
	double giftCardAmt;

	printf("***** Rental Vehicle Management App *****\n\n");

	do
	{
		// Display the option list
		printf("1.) Rental Status\n");
		printf("2.) Apply Charges\n");
		printf("3.) Apply Taxes to All Rentals\n");
		printf("4.) Apply Gift Card\n");
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

			if (flag != -1) {

				printf("Enter Rental Period (in Days): ");
				scanf("%d", &rentalDays);

				// Calculate the base price (baseDay * Days)
				basePrice = vRent[flag].baseDay * rentalDays;

				// Calculate cost for Kilometers driven using "distRate1 & 2 above"
				printf("Enter kilometers driven: ");
				scanf("%d", &drivenKm);

				if (drivenKm <= 100 && drivenKm > 0)
					kmCost = drivenKm *distRate1;
				else if (drivenKm > 100 && drivenKm > 0) {
					kmCost = (distRate1 * 100) + ((drivenKm - 100) *distRate2);
				}

				// Add base Price and cost for kilometer driven in to a new variable "charge"
				charge = basePrice + kmCost;

				/* Call addPositive function with current earnings for the rental and
				charge(calculated above) as arguments and assign the returned
				result back to earnings */
				printf("Apply Discount: ");
				scanf(" %c", &discountAns);

				if (discountAns == 'n' || discountAns == 'N')
					vRent[flag].earnings = addPositive(vRent[flag].earnings, charge);

				/* If the input is 'Y' or 'y' then call function subtractPositive with current earnings
				for the rental and discount (5 CAD) as arguments and assign the returned
				result back to earnings */

				if (discountAns == 'y' || discountAns == 'Y') {

					vRent[flag].earnings = addPositive(vRent[flag].earnings, charge);
					vRent[flag].earnings = subtractPositive(vRent[flag].earnings, discount);
					charge -= discount;

				}

				// Display Base Charge, cost for km and the Total 
				printf("\nBase   kmCost DiscStatus Total\n");
				printf("====== ====== ========== ======\n");
				printf("%6.2lf %6.2lf %10c %6.2lf\n\n", basePrice, kmCost, discountAns, charge);
			}
			else {
				printf("ERROR: Vehicle ID does not exist.\n\n");
			}

			break;

		case 3: // Apply Taxes to all Earnings

			printf("\n-- Apply Taxes To all Accounts--\n\n");
			printf("ID#      Earnings   Taxes\n");
			printf("-------- ---------- ------\n");

			for (i = 0; i < noVehicles; i++) {
				taxes = taxCalc(vRent[i].earnings, taxRate);
				vRent[i].earnings = addPositive(vRent[i].earnings, taxes);
				printf("%8d %10.2lf %6.2lf\n", vRent[i].id, vRent[i].earnings, taxes);
			}

			// Iterate over all Rentals. For each rental, calculate the taxes by calling taxCalc 
			// by passing current earnings and tax rate
			// Then call addPositive with current earnings and the taxes returned from taxCalc function
			// Then use "%8d %10.2lf %6.2lf" formatting to display ID, Earnings and taxes for each rental


			break;

		case 4: // Apply Gift Card

			flag = -1;
			printf("\n-- Apply Gift Card --\n\n");
			printf("Enter vehicle ID: ");
			scanf("%d", &tempID);


			// Finding the correct vehicle index
			for (i = 0; i < noVehicles && flag == -1; i++) {
				if (tempID == vRent[i].id) {
					flag = i;
				}
			}

			if (flag != -1) {
				// Capture Gift card amount
				printf("Enter Gift Card Amount: ");
				scanf("%lf", &giftCardAmt);

				/* call function subtractPositive with current earnings for the rental and Gift card
				amount as arguments and assign the returned result back to earnings */
				vRent[flag].earnings = subtractPositive(vRent[flag].earnings, giftCardAmt);

				printf("Discount Applied", giftCardAmt, vRent[flag].earnings);

			}
			else {
				printf("ERROR: Vehicle ID does not exist.\n\n");
			}

			printf("\n");
			break;

		default: // Prompt error message and continue the loop
			printf("Error: Please enter a valid option to continue\n\n");
			break;
		}


	} while (option != 0);

	return 0;
}
