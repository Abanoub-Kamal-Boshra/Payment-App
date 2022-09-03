#include "std.h"
#include <string.h>
#include "card.h"
#include "terminal.h"
#include "server.h"

/*  acountDB[100] = { {cardPan, account amount}, {} ... } */
acountData_t acountDB[100] = { {"1234567891234567", 25000}, {"9876543219876543", 2000} };
transactionData_t transData[100];
// counter used in store data in transData array
int transactionCounter = 0;
// temp variable
transactionData_t transDataVar = { "", 0,0, 0 };

transactionData_t recieveTransactionData(void)
{
	//strcpy_s(transData.pan, sizeof(transData.pan), cardPan);
	//transData.amount = gatTransactionAmount();

	terminalData_t terminalData = terminalGetAllTerminalData();
	strcpy_s(transDataVar.pan, sizeof(transDataVar.pan), terminalData.cardData.cardPan);
	transDataVar.tDate.month = terminalData.transDate.month;
	transDataVar.tDate.year = terminalData.transDate.year;
	transDataVar.amount = terminalData.transAmount;

	return transDataVar;
}

state_t isValidAccount(char* copy_pan)
{
	char existFlag = False;
	for (int count=0; count < strlen(acountDB); count++)
	{
		if (strcmp(acountDB[count].pan, copy_pan) == 0)
		{
			existFlag = True;
		}
	}
	return existFlag;
}

state_t isAmountAvailable(char* copy_pan, int copy_amount)
{
	char isAvailableFlag = False;
	for (int count=0; count < strlen(acountDB); count++)
	{
		if (strcmp(acountDB[count].pan, copy_pan) == 0)
		{
			if (copy_amount <= acountDB[count].balance)
			{
				isAvailableFlag = True;
			}
		}
	}
	return isAvailableFlag;
}

void saveTransaction(char* copy_pan, int copy_amount)
{
	for (int count=0; count < strlen(acountDB); count++)
	{
		if (strcmp(acountDB[count].pan, copy_pan) == 0)
		{
			acountDB[count].balance -= copy_amount;
			transData[transactionCounter] = transDataVar;
			transactionCounter++;
		}
	}
}