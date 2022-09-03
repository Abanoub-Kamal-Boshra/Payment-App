#include "std.h"
#include <stdio.h>
#include "card.h"
#include "terminal.h"
#include "server.h"

void testFunc(void)
{
	// TEST getCardHolderName
	//ST_transaction_t transData;
	//EN_cardError_t cardState;
	//do {
	//	cardState = getCardHolderName(&(transData.cardHolderData));
	//	if (cardState == OK)
	//		printf("OK\n");
	//	else
	//		printf("WRONG_NAME\n");
	//} while (cardState == WRONG_NAME);

	//// TEST getCardExpiryDate
	//ST_transaction_t transData;
	//EN_cardError_t cardState;
	//do {
	//	cardState = getCardExpiryDate(&(transData.cardHolderData));
	//	if (cardState == OK)
	//		printf("OK\n");
	//	else
	//		printf("WRONG_EXP_DATE\n");
	//} while (cardState == WRONG_EXP_DATE);

	//// TEST getCardExpiryDate
	//ST_transaction_t transData;
	//EN_cardError_t cardState;
	//do {
	//	cardState = getCardPAN(&(transData.cardHolderData));
	//	if (cardState == OK)
	//		printf("OK\n");
	//	else
	//		printf("WRONG_PAN\n");
	//} while (cardState == WRONG_PAN);

	//// TEST getTransactionDate
	//ST_transaction_t transData;
	//EN_cardError_t terminalState;
	//do { 
	//	terminalState = getTransactionDate(&(transData.terminalData));
	//	if (terminalState == OK)
	//		printf("OK\n");
	//	else
	//		printf("WRONG_DATE\n");
	//} while (terminalState == WRONG_DATE);

	//// TEST isCardExpired        {{0,0, expiry},{0,0, transaction},0,0}; 
	//ST_transaction_t transData = {{"","","11/22"},{0,0,"02/09/2022"},0,0};
	//EN_cardError_t terminalState;
	//
	//terminalState = isCardExpired(transData.cardHolderData, transData.terminalData);
	//if (terminalState == OK)
	//	printf("OK\n");
	//else
	//	printf("EXPIRED_CARD\n");

	//// TEST getTransactionAmount
	//ST_transaction_t transData;
	//EN_cardError_t terminalState;
	//do { 
	//	terminalState = getTransactionAmount(&(transData.terminalData));
	//	if (terminalState == OK)
	//		printf("OK\n");
	//	else
	//		printf("INVALID_AMOUNT\n");
	//} while (terminalState == INVALID_AMOUNT);

	//// TEST isBelowMaxAmount
	//ST_transaction_t transData;
	//EN_cardError_t terminalState;
	//
	//do {
	//	printf("Please enter trnasAmount: ");
	//	scanf_s("%f", &transData.terminalData.transAmount);
	//	printf("Please enter maxXrnasAmount: ");
	//	scanf_s("%f", &transData.terminalData.maxTransAmount);
	//
	//	terminalState = isBelowMaxAmount(&(transData.terminalData));
	//	if (terminalState == OK)
	//		printf("OK\n");
	//	else
	//		printf("EXCEED_MAX_AMOUNT\n");
	//} while (terminalState == EXCEED_MAX_AMOUNT);


	//// TEST setMaxAmount
	//ST_transaction_t transData;
	//EN_cardError_t terminalState;
	//
	//do {
	//	terminalState = setMaxAmount(&(transData.terminalData));
	//	if (terminalState == OK)
	//		printf("OK\n");
	//	else
	//		printf("INVALID_MAX_AMOUNT\n");
	//} while (terminalState == INVALID_MAX_AMOUNT);


	//// TEST isValidAccount
	//ST_transaction_t transData = { {"Abanoub Kamal Boshra","1234567891234567","12/28"}, {0.0,0.0,""}, 0, 0 };
	//EN_serverError_t serverState;
	//
	//serverState = isValidAccount(&(transData.cardHolderData));
	//
	//if (serverState == OK)
	//	printf("OK\n");
	//else 
	//	printf("DECLINED_STOLEN_CARD\n");
		

	//// TEST saveTransaction																{amount,max   ,date}
	//ST_transaction_t transData = { {"Abanoub Kamal Boshra","1234567891234567","12/28"}, {2000.0,5000.0,""}, 0, 0 };
	//EN_serverError_t serverState;
	//
	//for (uint8_t count = 0; count <= 253; count++)
	//{
	//	saveTransaction(&(transData));
	//}
	//
	//serverState = saveTransaction( &(transData) );
	//
	//if (serverState == APPROVED)
	//	printf("APPROVED\n");
	//else
	//	printf("SAVING_FAILED\n");

	
	//// TEST getTransaction																{amount,max ,date}, st,sequance}
	//ST_transaction_t transData = { {"Abanoub Kamal Boshra","1234567891234567","12/28"}, {2000.0,5000.0,""}, 0, 1 };
	//EN_serverError_t serverState;
	//
	//saveTransaction(&(transData)); // sequance = 0
	//saveTransaction(&(transData)); // sequance = 1
	// 
	//serverState = getTransaction(1, &(transData));
	//
	//if (serverState == OK)
	//	printf("OK\n");
	//else
	//	printf("TRANSACTION_NOT_FOUND\n");



	//// TEST recieveTransactionData														{amount,max   ,trans date }, st,sequance}
	//ST_transaction_t transData = { {"Abanoub Kamal Boshra","1234567891234567","12/28"}, {4000.0,5000.0,"12/12/2022"}, 0, 0 };
	//EN_serverError_t serverState;
	//
	//for (uint8_t count = 0; count <= 254; count++)
	//{
	//	saveTransaction(&(transData));
	//}
	//
	//serverState = recieveTransactionData(&(transData));
	//
	//if (serverState == APPROVED)
	//	printf("APPROVED\n");
	//else if(serverState == DECLINED_STOLEN_CARD)
	//	printf("DECLINED_STOLEN_CARD\n");
	//else if (serverState == DECLINED_INSUFFECIENT_FUND)
	//	printf("DECLINED_INSUFFECIENT_FUND\n");
	//else if (serverState == INTERNAL_SERVER_ERROR)
	//	printf("INTERNAL_SERVER_ERROR\n");
		

	
}