/*******************************************************************
 *  FILE DESCIPTION
 *  --------------------------------------------------------------*/
/**     File:  IntCtrl_Types.h
 *      Module: IntCtrl
 *
 *      Description: Interrupt vector table for Nvic
 *
 *
 ******************************************************************/
 #ifndef IntCtrl_Types_H
 #define IntCtrl_Types_H
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
 *  	GLOBAL DATA TYPES AND STRUCTURES
 *****************************************************************/
typedef enum
{
  Int_GPIO_Port_A=0        ,
  Int_GPIO_Port_B          ,
  Int_GPIO_Port_C          ,
  Int_GPIO_Port_D          ,
  Int_GPIO_Port_E          ,
  Int_UART_0               ,
  Int_UART_1               ,
  Int_SSI_0                ,
  Int_I2C_0                ,
  Int_PWM0_Fault           ,
  Int_PWM0_Generator_0     ,
  Int_PWM0_Generator_1     ,
  Int_PWM0_Generator_2     ,
  Int_QEI_0                ,
  Int_ADC0_Sequence_0      ,
  Int_ADC0_Sequence_1      ,
  Int_ADC0_Sequence_2      ,
  Int_ADC0_Sequence_3      ,
  Int_Watchdog_timer_0_1   ,
  Int_16_32_Timer_0A       ,
  Int_16_32_Timer_0B       ,
  Int_16_32_Timer_1A       ,
  Int_16_32_Timer_1B       ,
  Int_16_32_Timer_2A       ,
  Int_16_32_Timer_2B       ,
  Int_Analog_Comparator_0  ,
  Int_Analog_Comparator_1  ,

  // 27 reserved

  Int_System_Control=28    ,
  Int_Flash_EEPROM_CTRL    ,
  Int_GPIO_Port_F          ,
  
  // 31-32 reserved
  
  Int_UART_2=33            ,
  Int_SSI_1                ,
  Int_16_32_Timer_3A       ,
  Int_16_32_Timer_3B       ,
  Int_I2C_1                ,
  Int_QEI_1                ,
  Int_CAN_0                ,
  Int_CAN_1                ,
  
  // 41-42 reserved
  
  Int_Hibernation_Module=43,
  Int_USB                  ,
  Int_PWM0_Generator_3     ,
  Int_uDMA_Error           ,
  Int_ADC1_Sequence_0      ,
  Int_ADC1_Sequence_1      ,
  Int_ADC1_Sequence_2      ,
  Int_ADC1_Sequence_3      ,
  
  // 52-56 reserved
  
  Int_SSI_2=57             ,
  Int_SSI_3                ,
  Int_UART_3               ,
  Int_UART_4               ,
  Int_UART_5               ,
  Int_UART_6               ,
  Int_UART_7               , 
   
  // 64-67 reserved
  
  Int_I2C_2=68             ,
  Int_I2C_3                ,
  Int_16_32_Timer_4A       ,
  Int_16_32_Timer_4B       ,
   
  // 72-91 reserved
  
  Int_16_32_Timer_5A=92    ,
  Int_16_32_Timer_5B       ,
  Int_32_64_Timer_0A       ,
  Int_32_64_Timer_0B       ,
  Int_32_64_Timer_1A       ,
  Int_32_64_Timer_1B       ,
  Int_32_64_Timer_2A       ,
  Int_32_64_Timer_2B       ,
  Int_32_64_Timer_3A       ,
  Int_32_64_Timer_3B       ,
  Int_32_64_Timer_4A       ,
  Int_32_64_Timer_4B       ,
  Int_32_64_Timer_5A       ,
  Int_32_64_Timer_5B       ,
  Int_System_Exception     ,
  
  // 107-133 reserved
  
  Int_PWM1_Generator_0=134 ,
  Int_PWM1_Generator_1     ,
  Int_PWM1_Generator_2     ,
  Int_PWM1_Generator_3     ,
  Int_PWM1_Fault           , 

}Nvic_IntType;

typedef struct 
{
  Nvic_IntType interruptNumber;
  uint8        groupPriority;
  uint8        subgroupPriotity;

}Nvic_CfgType;

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
#endif /*IntCtrl_H*/

/******************************************************************
 *  	END OF FILE: IntCtrl_Types.h
 *****************************************************************/

