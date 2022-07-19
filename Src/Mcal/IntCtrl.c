/*******************************************************************
 *  FILE DESCIPTION
 *  --------------------------------------------------------------*/
/**     \file  IntCtrl.c
 *      \brief nested vector Interrupt controllrt Driver
 *
 *      \details the Driver Configure ALL MCU interrupts Priority into
 *               groups and subgroups Enable NVIC Interrupt Gate for Peripherals
 *
 ******************************************************************/

/******************************************************************
 *  INCLUDES
 *****************************************************************/
  #include "Std_Types.h"
  #include "IntCtrl.h"
  #include "Mcu_Hw.h"
  
/******************************************************************
 *  	LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************************/

 #define NVIC_GROUPING_SYSTEM_XXX  4
 #define NVIC_GROUPING_SYSTEM_XXY  5
 #define NVIC_GROUPING_SYSTEM_XYY  6
 #define NVIC_GROUPING_SYSTEM_YYY  7   

 #define APRINT_VECTKEY       0xFA05 
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
void IntCtrl_Init(void)
{
    /*TODO : Configure grouping\SubGrouping System in APINT register in SCB*/
    APINT->B.VECTKEY=APRINT_VECTKEY;
    APINT->B.PRIGROUP=NVIC_GROUPING_SYSTEM;
	
    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/

    /*TODO : Enable\Disable based on user configurations ion NVIC_ENx and SCB_Sys Resigters*/
}


/******************************************************************
 *  	END OF FILE: IntCtrl.c
 *****************************************************************/

