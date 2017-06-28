/*
Name: Nikki Truong
Student#: 112 314 174
IPC144 Section H - At-home 2
*/

#include<stdio.h>

// This program will take in an input amount from user and print out numbers of loonies, quarters, dimes, nickels, pennies and subsequential leftover balance

int main(void)
{
	//declare variables
	double amount, GST, total, owing;
	int loonies, quarters, whole, balance, dimes, nickels, pennies; 

	//prompt to ask for input from user
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);

	//calculate the GST as per instruction
	GST = amount * 0.13 + 0.005;
	total = amount + GST;
	whole = total * 100;

	//display GST and total balance owe after tax
	printf("GST: %.2lf\nBalance owing: $%.2lf\n", GST, total);

	//use division to calculate numbers of loonies and modulus to get remaining balance
	loonies = whole / 100;
	balance = whole % 100;
	owing = (double)balance / 100; //casting balance as double type
	
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, owing);

	quarters = balance / 25;
	balance = balance % 25;
	owing = (double)balance / 100;

	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, owing);

	dimes = balance / 10;
	balance = balance % 10;
	owing = (double)balance / 100;

	printf("Dimes required: %d, balance owing $%.2lf\n", dimes, owing);

	nickels = balance / 5;
	balance = balance % 5;
	owing = (double)balance / 100;

	printf("Nickels required: %d, balance owing $%.2lf\n", nickels, owing);

	pennies = balance / 1;
	balance = balance % 1;
	owing = (double)balance / 100;

	printf("Pennies required: %d, balance owing $%.2lf\n", pennies, owing);

	
	return 0;
}