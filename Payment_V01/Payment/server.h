/************************************************************************************/
/*	Author		:	Abanoub Kamal                                       			*/
/* 	Version		:	V01																*/
/*	Date		: 	23 August 2022													*/
/* 	Notes		:																	*/
/************************************************************************************/
#ifndef SERVER_H
#define SERVER_H

#include "terminal.h"


/***********************************************************************
                             Typedefs
 **********************************************************************/
typedef struct {
    char pan[17];
    int balance;
}acountData_t;

typedef struct {
    char pan[50];
    transactionDate_t tDate;
    int amount;
}transactionData_t;

 /***********************************************************************
                              Functions
  **********************************************************************/

  /***********************************************************************
   * Description:
   * Inputs     :	void
   * return     :
   * scope      :	public
   **********************************************************************/
transactionData_t recieveTransactionData(void);

/***********************************************************************
 * Description:
 * Inputs     :	void
 * return     :
 * scope      :	public
 **********************************************************************/
state_t isValidAccount(char* copy_pan);


/***********************************************************************
 * Description:
 * Inputs     :	void
 * return     :
 * scope      :	public
 **********************************************************************/
state_t isAmountAvailable(char* copy_pan, int copy_amount);


/***********************************************************************
 * Description:
 * Inputs     :	void
 * return     :
 * scope      :	public
 **********************************************************************/
void saveTransaction(char* copy_pan, int copy_amount);



#endif