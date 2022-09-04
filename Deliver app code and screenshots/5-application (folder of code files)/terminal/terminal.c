#include <stdio.h>
#include <string.h>
#include <time.h>
#include "std.h"
#include "card.h"
#include "terminal.h"


EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	char date[11] = { '3','0','/','0','8','/','2','0','2','2','\0'};
	char day = 0, month = 0;
	int year = 0;
	char forwardSlash1;
	char forwardSlash2;

	printf("pleaze enter the transaction date: ");
	gets(date);
	day   = ((date[0] - '0') * 10) + (date[1] - '0');
	month = ((date[3] - '0') * 10) + (date[4] - '0');
	year  = ((date[6] - '0') * 1000) + ((date[7] - '0') * 100) + ((date[8] - '0') * 10) + ((date[9] - '0'));
	forwardSlash1 = (char)date[2];
	forwardSlash2 = (char)date[5];

	if(date==NULL || strlen(date)!=10 || day<=0 || day>31 || month<=0 || month>12 || year<2022 || forwardSlash1!='/' || forwardSlash2!='/')
	{
		return WRONG_DATE;
	}
	else
	{
		strcpy_s(termData->transactionDate, sizeof(termData->transactionDate), date);
		return OK;
	}
}

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	uint32_t transMonth = ((termData.transactionDate[3] - '0') * 10) + (termData.transactionDate[4] - '0');
	uint32_t transYear = ((termData.transactionDate[6] - '0') * 1000) + ((termData.transactionDate[7] - '0') * 100) + ((termData.transactionDate[8] - '0') * 10) + ((termData.transactionDate[9] - '0'));
	uint32_t expiryMonth = ((cardData.cardExpirationDate[0] - '0') * 10) + (cardData.cardExpirationDate[1] - '0');
	uint32_t expiryYear = ((cardData.cardExpirationDate[3] - '0') * 10) + (cardData.cardExpirationDate[4] - '0') + 2000;

	if (transYear < expiryYear)
	{
		return OK;
	}
	else if (transYear == expiryYear)
	{
		if (transMonth <= expiryMonth)
		{
			return OK;
		}
	}
	return EXPIRED_CARD;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	printf("pleaze enter the transaction amount: ");
	scanf_s("%f", &termData->transAmount);
	if (termData->transAmount <= 0)
	{
		return INVALID_AMOUNT;
	}
	else
	{
		return OK;
	}
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount <= termData->maxTransAmount)
	{
		return OK;
	}
	else
	{
		return EXCEED_MAX_AMOUNT;
	}
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	float transamount;
	printf("pleaze enter the maxAmount amount: ");
	scanf_s("%f", &transamount);
	if (transamount <= 0)
	{
		return INVALID_MAX_AMOUNT;
	}
	else
	{
		termData->maxTransAmount = transamount;
		return OK;
	}
}