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
#include "Dio.h"
#include "Port_Int_Cfg.h"

  
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


typedef void(* GpioNotification ) (Pin_Num pin);



typedef struct{
  Dio_PortType port;
  Pin_Num  pin;
}PortPin;

typedef enum{
 
  GPIO = 0     ,
  FUNCTION1    , 
  FUNCTION2    ,
  FUNCTION3    ,
  FUNCTION4    ,
  FUNCTION5    ,
  FUNCTION6    ,
  FUNCTION7    ,
  FUNCTION8    ,
  FUNCTION9    ,
  FUNCTION10   ,
  FUNCTION11   ,
  FUNCTION12   ,
  FUNCTION13   ,
  FUNCTION14   , 
  FUNCTION15   ,
  ANALOG_FUNCTION    
  
}PortPinMode;


typedef enum{
  NONE = 0     ,
  FALLING_EGDE , //GPIOIS=0 , GPIOIBE=0 , GPIOIEV=0 
  RISING_EDGE  , //GPIOIS=0 , GPIOIBE=0 , GPIOIEV=1
  HIGH_LEVELS  , //GPIOIS=1 , GPIOIBE=0 , GPIOIEV=1
  LOW_LEVELS   , //GPIOIS=1 , GPIOIBE=0 , GPIOIEV=0
  BOTH_EDGES     //GPIOIS=0 , GPIOIBE=1 , GPIOIEV=x 

}Interrupt_Type;




typedef enum{
 
  OUTPUT =0 ,
  INPUT

}PortPinDirection;

typedef enum{
 
  Pull_Up=0,
  Pull_down,
  Open_Drain

}PortPinInternalAttach;

typedef enum{
  
  Pin_Amp_2 = 0,
  Pin_Amp_4    ,
  Pin_Amp_8 

}PortPinOutputCurrent;



typedef struct 
{

  PortPin                portPin;
  PortPinMode            pinMode;
  Dio_LevelType          pinLevelValue;
  PortPinDirection       pinDirection;
  PortPinInternalAttach  pinAttach;
  PortPinOutputCurrent   pinOutputCurrent;
  Interrupt_Type         pinInterruptType;
  GpioNotification       pinNotification;


}Port_ConfigType;


/******************************************************************
 *  	GLOBAL DATA PROTOTYPES
 *****************************************************************/
  extern const Port_ConfigType ConfigType [];
  // extern uint32 mode ;
  extern uint32 offTime;
  extern uint32 onTime ;
  extern boolean onOffFlag;

/******************************************************************
 *  	GLOBAL FUNCTIONS PROTOTYPES
 *****************************************************************/

extern void Port_Init(const Port_ConfigType* ConfigPtr);

#endif /*Port_Int_H*/

/******************************************************************
 *  	END OF FILE: Port_Int.h
 *****************************************************************/

