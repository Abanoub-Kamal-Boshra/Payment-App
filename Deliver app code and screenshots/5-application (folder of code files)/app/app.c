#include "std.h"
#include <stdio.h>
#include "card.h"
#include "terminal.h"
#include "server.h"
#include "app.h"

void appStart(void)
{
	ST_transaction_t transData;
	char choice = 0;
	EN_cardError_t cardState;
	EN_terminalError_t terminalState;
	
	do
	{
		/* 1- get the card data */

		// get the card holder name
		do {
			cardState = getCardHolderName(&(transData.cardHolderData));
		} while (cardState == WRONG_NAME);
		// get the card holder card expirty date
		do {
			cardState = getCardExpiryDate(&(transData.cardHolderData));
		} while (cardState == WRONG_EXP_DATE);
		// get the card holder card pan
		do {
			cardState = getCardPAN(&(transData.cardHolderData));
		} while (cardState == WRONG_PAN);

		/* 2- get the Terminal data */

		// get the transaction date
		do {
			terminalState = getTransactionDate(&(transData.terminalData));
		} while (terminalState == WRONG_DATE);
	
		if (EXPIRED_CARD == isCardExpired(transData.cardHolderData, transData.terminalData))
		{
			printf("Declined Expired Card!\n\n");
		}
		else
		{
			// set the max amount
			setMaxAmount(&(transData.terminalData));

			do {
				terminalState = getTransactionAmount(&(transData.terminalData));
			} while (terminalState != OK);

			if (EXCEED_MAX_AMOUNT == isBelowMaxAmount(&(transData.terminalData)) )
			{
				printf("Declined Account Exceeding Limit!\n\n");
			}
			else
			{
				/* 3- start the code of the server */
				if (DECLINED_STOLEN_CARD == isValidAccount( &(transData.cardHolderData) ) )
				{
					printf("Declined Invalid Account!\n\n");
				}
				else
				{
					if (DECLINED_STOLEN_CARD == isAmountAvailable(&(transData.cardHolderData), &(transData.terminalData)))
					{
						printf("Declined Insuffecient Funds!\n\n");
					}
					else
					{
						// update the balance and save the transaction data
						EN_serverError_t serverState = recieveTransactionData(&transData);
						if (APPROVED == serverState)
						{
							// show message to the user
							printf("\n*****************************************************\n"
								"********** Thank You So Mach For Your Time **********\n"
								"*****************************************************\n"
								"\t\tYour Transaction is\n\n");

							printf("\tTransaction Date  : %s \n", transData.terminalData.transactionDate);
							printf("\tTransaction Amount: %.2f Bounds\n", transData.terminalData.transAmount);
							printf("\tTransaction State : APPROVED.\n");
							printf("*****************************************************\n");
						}
						else
						{
							if (serverState == DECLINED_STOLEN_CARD)
								printf("DECLINED_STOLEN_CARD\n");
							else if (serverState == DECLINED_INSUFFECIENT_FUND)
								printf("DECLINED_INSUFFECIENT_FUND\n");
							else if (serverState == INTERNAL_SERVER_ERROR)
								printf("INTERNAL_SERVER_ERROR\n");
						}
					}
				}
			}
		}
	
		/* 4- finish the operantion */
		printf("If you want to exit press ESC, \nfor continue press another button");
		choice = getch();
		printf("\n\n");
	
	} while (choice != ESC);
}
