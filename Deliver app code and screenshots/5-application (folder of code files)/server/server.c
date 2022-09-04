#include <stdio.h>
#include <string.h>
#include "std.h"
#include "card.h"
#include "terminal.h"
#include "server.h"

			/*  acountDB[255] = { {account balance, cardPan}, {} ... } */
static ST_accountsDB_t acountDB[255] = { {25000.0, "1234567891234567"}, {2000.0, "9876543219876543"} };
static ST_transaction_t transDataDB[255] = { {{"","",""}, {0.0,0.0,""}, 0, 0} };
// counter used in store data in transData array
// variable used for the transaction sequence number
static uint8_t transactionCounter = 0;


EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	/* check if the account is exist or not */
	if (DECLINED_STOLEN_CARD == isValidAccount(&(transData->cardHolderData)))
	{
		return DECLINED_STOLEN_CARD;
	}
	else
	{
		/* check if the amount is available */
		if (LOW_BALANCE == isAmountAvailable(&(transData->cardHolderData), &(transData->terminalData)))
		{
			return DECLINED_INSUFFECIENT_FUND;
		}
		else
		{
			/* save the transaction */
			if (APPROVED == saveTransaction(&transData))
			{
				/* update the balance */
				for (uint8_t count = 0; count < 255; count++)
				{
					if (strcmp(acountDB[count].primaryAccountNumber, transData->cardHolderData.primaryAccountNumber) == 0)
					{
						acountDB[count].balance -= (transData->terminalData.transAmount);
						return APPROVED;
					}
				}
			}
			return INTERNAL_SERVER_ERROR;
		}
	}
}

EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
	for (int count=0; count < 256; count++)
	{
		if (strcmp(acountDB[count].primaryAccountNumber, cardData->primaryAccountNumber) == 0)
		{
			return OK;
		}
	}
	return DECLINED_STOLEN_CARD;
}

EN_serverError_t isAmountAvailable(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
	for (uint8_t count = 0; count < 255; count++)
	{
		if (strcmp(acountDB[count].primaryAccountNumber, cardData->primaryAccountNumber) == 0)
		{
			if (termData->transAmount <= acountDB[count].balance)
			{
				return OK;
			}
			else
			{
				return LOW_BALANCE;
			}
		}
	}
	return LOW_BALANCE;
}

EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	if (transactionCounter <= 254)
	{
		transData->transactionSequenceNumber = transactionCounter;
		transData->transState = APPROVED;
		transDataDB[transactionCounter] = *transData;

		transactionCounter++;
		return APPROVED;
	}
	else
	{
		return SAVING_FAILED;
	}
}

EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData)
{
	for (int count = 0; count < 255; count++)
	{
		if (transDataDB[count].transactionSequenceNumber == transactionSequenceNumber)
		{
			*transData = transDataDB[count];
			return OK;
		}
	}
	return TRANSACTION_NOT_FOUND;
}