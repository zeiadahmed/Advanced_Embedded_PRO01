/*******************************************************************
 *  FILE DESCIPTION
 *  --------------------------------------------------------------*/
/**     File:  IntCtrl.h
 *      Module: IntCtrl
 *
 *      Description: header file for IntCtrl.Module
 *
 *
 ******************************************************************/
 #ifndef IntCtrl_H
 #define IntCtrl_H
/******************************************************************
 *  INCLUDES
 *****************************************************************/
  #include "Std_Types.h"
  #include "IntCtrl_Cfg.h"
  
/******************************************************************
 *  	LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************************/
 
/******************************************************************
 *  	LOCAL DATA
 *****************************************************************/
 
/******************************************************************
 *  	GLOBAL DATA
 *****************************************************************/
 
/******************************************************************
 *  	LOCAL FUNCTION PROTOTYPES
 *****************************************************************/
  
/******************************************************************
 *  	LOCAL FUNCTIONS
 *****************************************************************/
 
/******************************************************************
 *  	GLOBAL FUNCTIONS
 *****************************************************************/


/******************************************************************
 * \Syntax          : void IntCtrl_Init(void)
 * \Description     : initialize Nvic\SCB Module by parsing the configuration
 *                    into Nvic\SCB registers
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value    : None
 *****************************************************************/   
void IntCtrl_Init(void);
#endif /*IntCCtrl_H*/

/******************************************************************
 *  	END OF FILE: IntCtrl.h
 *****************************************************************/

