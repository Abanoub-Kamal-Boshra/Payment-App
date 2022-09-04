/************************************************************************************/
/*	Author		:	Abanoub Kamal                                       			*/
/* 	Version		:	V01																*/
/*	Date		: 	23 August 2022													*/
/* 	Notes		:																	*/				
/************************************************************************************/
#ifndef CARD_H
#define CARD_H

/***********************************************************************
                             Typedefs
 **********************************************************************/
typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef enum EN_cardError_t
{
    OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;
/***********************************************************************
                             Functions
 **********************************************************************/

/***********************************************************************
 * Description: function to take card holder name from the user 
                and store it in the card data passed by address
 * Inputs     :	ST_cardData_t* cardData --> (address of cardData)
 * return     :	EN_cardError_t          --> (WRONG_NAME / OK) 
 * scope      :	public
 **********************************************************************/
EN_cardError_t getCardHolderName(ST_cardData_t* cardData);

/***********************************************************************
 * Description: function to take card expiry date in format (Month/Year -> 08/25)
 * Inputs     :	ST_cardData_t* cardData --> (address of cardData)
 * return     :	EN_cardError_t          --> (WRONG_EXP_DATE / OK)
 * scope      :	public
 **********************************************************************/
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);

/***********************************************************************
 * Description: function to get the card pan and store it in variable passed by address
 * Inputs     :	ST_cardData_t* cardData --> (address of cardData)
 * return     : EN_cardError_t          --> (WRONG_PAN / OK)
 * scope      :	public
 **********************************************************************/
EN_cardError_t getCardPAN(ST_cardData_t* cardData);


#endif