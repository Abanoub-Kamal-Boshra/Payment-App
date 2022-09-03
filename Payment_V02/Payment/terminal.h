/************************************************************************************/
/*	Author		:	Abanoub Kamal                                       			*/
/* 	Version		:	V01																*/
/*	Date		: 	23 August 2022													*/
/* 	Notes		:																	*/
/************************************************************************************/
#ifndef TERMINAL_H
#define TERMINAL_H

/***********************************************************************
                             Typedefs
 **********************************************************************/
typedef struct ST_terminalData_t
{
    float transAmount;
    float maxTransAmount;
    uint8_t transactionDate[11];
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
    REPACE_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t;
/***********************************************************************
                             Functions
 **********************************************************************/

 /***********************************************************************
   * Description:
   * Inputs     :	void
   * return     :
   * scope      :	public
   **********************************************************************/
EN_terminalError_t getTransactionDate(ST_terminalData_t* termData);

/***********************************************************************
  * Description:
  * Inputs     :	void
  * return     :
  * scope      :	public
  **********************************************************************/
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData);

/***********************************************************************
 * Description: 
 * Inputs     :	void
 * return     :
 * scope      :	public
 **********************************************************************/
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData);

/***********************************************************************
 * Description:
 * Inputs     :	void
 * return     :
 * scope      :	public
 **********************************************************************/
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData);

/***********************************************************************
 * Description:
 * Inputs     :	void
 * return     :
 * scope      :	public
 **********************************************************************/
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData);


#endif