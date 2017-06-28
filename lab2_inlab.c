/*
	Name: Nikki Truong
	Student#: 112 314 174
	IPC144 Section H - In_lab 2

  */

#include<stdio.h>

  // This program will take in an input amount from user and print out numbers of loonies, quarters and leftover balance



int main(void)
{
	int loonies, quarters;
	double amount, balance, leftover;

	//prompt user to enter amount
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount); 

	loonies = amount; //chunk off amount to get number of loonies
	balance = amount - loonies; //calculate balance by subtract number of loonies

	//display the number of loonies require based on amount
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, balance);

	quarters = (balance * 100) / 25; //use balance to calculate quarters needed
	leftover = balance - (0.25 * quarters); //subtract to get the final balance owing

	//display the number of quarters require based on leftover balance
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, leftover);

	return 0;

}


