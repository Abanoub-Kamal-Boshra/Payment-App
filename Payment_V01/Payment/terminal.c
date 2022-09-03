#include "std.h"
#include <string.h>
#include <stdio.h>
#include <string.h>
#include "card.h"
#include "server.h"
#include "terminal.h"

static int MaxAmount = 5000;
cardData_t* cardData;
terminalData_t terminalData;
//char cardPan[50];

cardData_t* terminalGetAllCardData(void)
{
	//char (*str1)[50] = getCardHolderName();
	//expiryDate_t expiredate = getCardExpiryDate();
	//char (*str2)[50] = getCardPAN();
	//cardData_t cardData = { *str1, *str2,  expiredate.month, expiredate.year };
	
	//strcpy_s(cardData->cardHolderName, sizeof(cardData->cardHolderName), str);
	//strcpy_s(cardData->cardPan, sizeof(cardData->cardPan), getCardPAN());
	
	cardData = getAllCardData();
	terminalData.cardData = *(cardData);
	//strcpy_s(terminalData.cardData.cardPan, sizeof(terminalData.cardData.cardPan), cardData->cardPan);
	//printf("%s\n", cardData->cardHolderName);
	//printf("%d/%d\n", cardData->expireDate.month, cardData->expireDate.year);
	//printf("%s\n", cardPan);

	return cardData;
}

terminalData_t terminalGetAllTerminalData(void)
{
	return terminalData;
}

transactionDate_t getTransactionDate(void)
{
	char date[6] = { '1','2','/','2','5','\0' };
	int month = 0, year = 0;
	char forwardSlash;
	transactionDate_t transactionDate;

	printf("pleaze enter the transaction date: ");
	gets(date);
	month = ((date[0] - '0') * 10) + (date[1] - '0');
	year = ((date[3] - '0') * 10) + (int)(date[4] - '0');
	forwardSlash = (char)date[2];

	while (True)
	{
		if (strlen(date) != 5 || month <= 0 || month > 12 || forwardSlash != '/')
		{
			printf("pleaze enter a valid transaction date: ");
			gets(date);
			month = ((date[0] - '0') * 10) + (date[1] - '0');
			year = ((date[3] - '0') * 10) + (int)(date[4] - '0');
			forwardSlash = (char)date[2];
		}
		else
		{
			break;
		}
	}

	transactionDate.month = month;
	transactionDate.year = year;

	terminalData.transDate.month = month;
	terminalData.transDate.year = year;

	return transactionDate;
}

state_t isCardExpried(expiryDate_t copyExpireDate, transactionDate_t copyTransactionDate)
{
	if (copyTransactionDate.year <= copyExpireDate.year)
	{
		if (copyTransactionDate.month <= copyExpireDate.month)
		{
			return NotOk;
		}
		else
		{
			return Ok;
		}
	}
	else
	{
		return NotOk;
	}
}


int gatTransactionAmount(void)
{
	int amount;
	printf("pleaze enter the transaction amount: ");
	scanf_s("%d", &amount);

	terminalData.transAmount = amount;

	return amount;
}

state_t isBelowMaxAmount(int copy_amount)
{
	if (copy_amount <= MaxAmount)
	{
		return True;
	}
	else
	{
		return False;
	}
}

void setMaxAmount(int copy_maxAmount)
{
	MaxAmount = copy_maxAmount;
}