#include <stdio.h>
#include <string.h>
#include "std.h"
#include "card.h"

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	printf("pleaze enter your card name: ");
	_flushall();
	gets(cardData->cardHolderName);

	if (cardData->cardHolderName == NULL || strlen(cardData->cardHolderName) < 20 || strlen(cardData->cardHolderName) > 24)
	{
		return WRONG_NAME;
	}
	else
	{
		return OK;
	}
}


EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	int month = 0;
	int year = 0;
	char forwardSlash;

	printf("pleaze enter your card expiry date: ");
	_flushall();
	gets(cardData->cardExpirationDate);
	
	month = ((cardData->cardExpirationDate[0] - '0') * 10) + (cardData->cardExpirationDate[1] - '0');
	year  = ((cardData->cardExpirationDate[3] - '0') * 10) + (cardData->cardExpirationDate[4] - '0');
	forwardSlash = (char)cardData->cardExpirationDate[2];

	if (cardData->cardExpirationDate == NULL || strlen(cardData->cardExpirationDate) != 5 || month <= 0 || month > 12 || forwardSlash != '/')
	{
		return WRONG_EXP_DATE;
	}
	else
	{
		return OK;
	}
}


EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	printf("pleaze enter your card Pan: ");
	_flushall();
	gets(cardData->primaryAccountNumber);

	if (cardData->primaryAccountNumber == NULL || strlen(cardData->primaryAccountNumber) < 16 || strlen(cardData->primaryAccountNumber) > 19)
	{
		return WRONG_PAN;
	}
	else
	{
		// to check that all the digits are numbers
		for (char i = 0; i < 16; i++)
		{
			if ((cardData->primaryAccountNumber[i]-'0') < 0 || (cardData->primaryAccountNumber[i]-'0') > 9)
			{
				return WRONG_PAN;
			}
		}
	}
	return OK;
}