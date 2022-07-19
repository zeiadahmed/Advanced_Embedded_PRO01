/*******************************************************************
 *  FILE DESCIPTION
 *  --------------------------------------------------------------*/
/**     File:  Port_Int.h
 *      Module: Port_Int
 *
 *      Description: Initialize Port Configrations Data Structures 
 *                   And Functions Prototypes
 *
 *
 ******************************************************************/
 #ifndef Port_Int_H
 #define Port_Int_H
/******************************************************************
 *  INCLUDES
 *****************************************************************/
#include "Std_Types.h"


  
/******************************************************************
 *  	LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************************/
 
/******************************************************************
 *  	LOCAL DATA
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
typedef enum{
 
  GPIO =0 ,
  Uart0   ,
  SSI0    ,
  I2C0    ,
  JTAG_SWD,

}Gpio_Pin_Mode;

typedef enum{
 
  Edge_Trig=0, //GPIOIS 0
  Level_Trig   //GPIOIS 1

}Gpio_Pin_Level_Value;

typedef enum{
 
  OUTPUT =0 ,
  INPUT

}Gpio_Pin_Direction;

typedef enum{
 
  Pull_Up=0,
  Pull_down,
  Open_Drain

}Gpio_Pin_Attach;

typedef enum{
  
  Pin_Amp_2 = 0,
  Pin_Amp_4    ,
  Pin_Amp_8 

}Gpio_Pin_Output_Current;



typedef struct 
{

  Gpio_Pin_Mode             pinMode;
  Gpio_Pin_Level_Value      pinLevelValue;
  Gpio_Pin_Direction        pinDirection;
  Gpio_Pin_Attach           pinAttach;
  Gpio_Pin_Output_Current   pinOutputCurrent;

}Port_ConfigType;


/******************************************************************
 *  	GLOBAL DATA PROTOTYPES
 *****************************************************************/
  extern const Port_ConfigType ConfigType [];


/******************************************************************
 *  	GLOBAL FUNCTIONS PROTOTYPES
 *****************************************************************/

void Port_Init(const Port_ConfigType* ConfigPtr);

#endif /*Port_Int_H*/

/******************************************************************
 *  	END OF FILE: Port_Int.h
 *****************************************************************/

