/*******************************************************************
 *  FILE DESCIPTION
 *  --------------------------------------------------------------*/
/**     \file  Port_Int.c
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
  #include "Port_Int.h"
  #include "Mcu_Hw.h"
  
/******************************************************************
 *  	LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************************/
/*TODO WHO WHERE TO PUT THOSE #DEFINES*/




/******************************************************************
 *  	LOCAL DATA
 *****************************************************************/
 
/******************************************************************
 *  	GLOBAL DATA PROTOTYPES
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
 * \Syntax          : void Port_Init(void)
 * \Description     : initialize Nvic\SCB Module by parsing the configuration
 *                    into Nvic\SCB registers
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value    : None
 *****************************************************************/   
void Port_Init(const Port_ConfigType*ConfigPtr)
{
    /*TODO : Configure grouping\SubGrouping System in APINT register in SCB*/
	
    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/

    /*TODO : Enable\Disable based on user configurations ion NVIC_ENx and SCB_Sys Resigters*/
}


/******************************************************************
 *  	END OF FILE: Port_Int.c
 *****************************************************************/

