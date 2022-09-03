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

typedef struct {
    int month;
    int year;
}transactionDate_t;

typedef struct {
    cardData_t cardData;
    transactionDate_t transDate;
    int transAmount;
}terminalData_t;


/***********************************************************************
                             Functions
 **********************************************************************/

 /***********************************************************************
   * Description:
   * Inputs     :	void
   * return     :
   * scope      :	public
   **********************************************************************/
cardData_t* terminalGetAllCardData(void);

/***********************************************************************
  * Description:
  * Inputs     :	void
  * return     :
  * scope      :	public
  **********************************************************************/
terminalData_t terminalGetAllTerminalData(void);

 /***********************************************************************
  * Description: 
  * Inputs     :	void
  * return     :	
  * scope      :	public
  **********************************************************************/
transactionDate_t getTransactionDate(void);


/***********************************************************************
 * Description: 
 * Inputs     :	void
 * return     :
 * scope      :	public
 **********************************************************************/
state_t isCardExpried(expiryDate_t copyExpireDate, transactionDate_t copyTransactionDate);


/***********************************************************************
 * Description:
 * Inputs     :	void
 * return     :
 * scope      :	public
 **********************************************************************/
int gatTransactionAmount(void);


/***********************************************************************
 * Description:
 * Inputs     :	void
 * return     :
 * scope      :	public
 **********************************************************************/
state_t isBelowMaxAmount(int copy_amount);


/***********************************************************************
 * Description:
 * Inputs     :	void
 * return     :
 * scope      :	public
 **********************************************************************/
void setMaxAmount(int copy_maxAmount);



#endif