#include "std.h"
#include <stdio.h>
#include <string.h>
#include "card.h"

static cardData_t cardData;

char* getCardHolderName(void)
{
	printf("pleaze enter your card name: ");
	_flushall();
	gets(cardData.cardHolderName);
	//scanf_s("%[^\n]%*c", cardData.cardHolderName, 0);

	while (True)
	{
		if (strlen(cardData.cardHolderName) < 1 && strlen(cardData.cardHolderName) >= 50)
		{
			printf("pleaze enter a valid card name: ");
			_flushall();
			gets(cardData.cardHolderName);
		}
		else
		{
			break;
		}
	}
	return cardData.cardHolderName;
}


expiryDate_t getCardExpiryDate(void)
{
	char date[6] = {'1','2','/','2','5','\0'};
	int month = 0;
	int year = 0;
	char forwardSlash;

	printf("pleaze enter your card expiry date: ");
	_flushall();
	gets(date);
	//scanf_s("%[^\n]%*c", date,0);
	//scanf_s("%5s", date, (unsigned)_countof(date));

	month = ((date[0] - '0') * 10) + (date[1] - '0');
	year = ((date[3] - '0') * 10) + (int)(date[4] - '0');
	forwardSlash = (char)date[2];

	while (True)
	{
		if (strlen(date) != 5 || month <= 0 || month > 12 || forwardSlash != '/')
		{
			printf("pleaze enter a valid expiry date: ");
			_flushall();
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

	cardData.expireDate.month = month;
	cardData.expireDate.year = year;

	return cardData.expireDate;
}


char* getCardPAN(void)
{
	state_t isAllNumFlag = True;
	printf("pleaze enter your card Pan: ");
	_flushall();
	gets(cardData.cardPan);
	//scanf_s("%[^\n]%*c", cardData.cardPan,0);
	//scanf_s("%5s", cardData.cardPan, (unsigned)_countof(cardData.cardPan));


	while (True)
	{
		if (strlen(cardData.cardPan) != 16)
		{
			printf("pleaze enter a 16 digit card Pan: ");
			_flushall();
			gets(cardData.cardPan);
		}
		else
		{
			for (char i = 0; i < 16; i++)
			{
				if ((cardData.cardPan[i]-'0') < 0 || (cardData.cardPan[i]-'0') > 9)
				{
					isAllNumFlag = False;
				}
			}

			if (isAllNumFlag == True)
			{
				break;
			}
		}
	}
	return cardData.cardPan;
}


cardData_t* getAllCardData(void)
{
	getCardHolderName();
	getCardExpiryDate();
	getCardPAN();

	return &cardData;
}
