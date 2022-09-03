#include "std.h"
#include <stdio.h>
#include "card.h"
#include "terminal.h"
#include "server.h"
#include "application.h"

extern int transactionCounter;
extern transactionData_t transData[100];

void appStart(void)
{
	int transAmount;
	cardData_t* cardData;
	transactionDate_t transDate;
	char choice = 0;

	do
	{
		/* 1- get the card data when you in a terminal */

		// get the card holder name, card pan, and expirty date
		cardData = terminalGetAllCardData();
		// get the transaction date
		transDate = getTransactionDate();

		if (True == isCardExpried(cardData->expireDate, transDate))
		{
			printf("Declined Expired Card!\n\n");
			//break;
		}
		else
		{
			transAmount = gatTransactionAmount();
			if (False == isBelowMaxAmount(transAmount))
			{
				printf("Declined Account Exceeding Limit!\n\n");
				//break;
			}
			else
			{
				/* 2- start the code of the server */
				if (False == isValidAccount(cardData->cardPan))
				{
					printf("Declined Invalid Account!\n\n");
					//break;
				}
				else
				{
					if (False == isAmountAvailable(cardData->cardPan, transAmount))
					{
						printf("Declined Insuffecient Funds!\n\n");
						//break;
					}
					else
					{
						recieveTransactionData();
						saveTransaction(cardData->cardPan, transAmount);

						printf("\n*****************************************************\n"
							"********** Thank You So Mach For Your Time **********\n"
							"*****************************************************\n"
							"\t\tYour Transactions is\n\n");
						for (int count = 0; count < transactionCounter; count++)
						{
							printf("\tTransaction Date  : %d Month\n\t\t\t    20%d Year\n", transData[count].tDate.month, transData[count].tDate.year);
							printf("\tTransaction Amount: %d Bounds\n", transData[count].amount);
							printf("*****************************************************\n");
						}
					}
				}
			}
		}

		/* 3- finish the operantion */
		printf("If you want to exit press ESC, \nfor continue press another button");
		choice = getch();
		printf("\n\n");

	} while (choice != ESC);
}
