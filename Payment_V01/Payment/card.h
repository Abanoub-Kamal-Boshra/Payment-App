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
typedef struct {
    int month;
    int year;
}expiryDate_t;

typedef struct {
    char cardHolderName[50];
    char cardPan[50];
    expiryDate_t expireDate;
}cardData_t;

/***********************************************************************
                             Functions
 **********************************************************************/

/***********************************************************************
 * Description: function to return card holder name in array of chars
 * Inputs     :	void
 * return     :	array of chars (pointer to char -> 
                                as the name of char is address to first element)
 * scope      :	public
 **********************************************************************/
char* getCardHolderName(void);


/***********************************************************************
 * Description: function to return card expiry date in format (Month/Year -> 08/25)
 * Inputs     :	void
 * return     :	state (True or False)
 * scope      :	public
 **********************************************************************/
expiryDate_t getCardExpiryDate(void);


/***********************************************************************
 * Description: function to get the card pan and store it in static global variable
 * Inputs     :	void
 * return     : state (True or False)
 * scope      :	public
 **********************************************************************/
char* getCardPAN(void);;


/***********************************************************************
 * Description: this function to call all the three function above and return
 *              the data in one struct
 * Inputs     :	void
 * return     : struct in type cardData_t has card hoder name, expiry date and pan
 * scope      :	public
 **********************************************************************/
cardData_t* getAllCardData(void);

#endif