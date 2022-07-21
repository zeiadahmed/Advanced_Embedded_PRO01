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
  #include "Port_Int_Cfg.h"
  
/******************************************************************
 *  	LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************************/
#define MAX_PORT_NUMBER 6
#define GET_BIT_MASK(portAdress,pin) portAdress+((0x1<<pin)<<2)
#define GET_REGISTER_POINTER(RegisterAdress)   *((volatile uint32 *)(RegisterAdress))


/******************************************************************
 *  	LOCAL DATA
 *****************************************************************/
 static uint32 PortAdresList[MAX_PORT_NUMBER]={
                  GPIO_Port_A,
                  GPIO_Port_B,
                  GPIO_Port_C,
                  GPIO_Port_D,
                  GPIO_Port_E,
                  GPIO_Port_F
};
/******************************************************************
 *  	GLOBAL DATA PROTOTYPES
 *****************************************************************/
 


/******************************************************************
 *  	LOCAL FUNCTION PROTOTYPES
 *****************************************************************/
  
/******************************************************************
 *  	LOCAL FUNCTIONS
 *****************************************************************/
void Set_Output_Current(uint32 portMask,Pin_Num CurrentPin,PortPinOutputCurrent outCurrent){
   if (outCurrent == Pin_Amp_2)
      GET_REGISTER_POINTER(portMask+GPIODR2R)|=1<<(CurrentPin);
   else if (outCurrent == Pin_Amp_4)
      GET_REGISTER_POINTER(portMask+GPIODR4R)|=1<<(CurrentPin);
   else if (outCurrent == Pin_Amp_8) 
      GET_REGISTER_POINTER(portMask+GPIODR8R)|=1<<(CurrentPin);


}


void Set_Internal_Attachment(uint32 portMask,Pin_Num CurrentPin,PortPinInternalAttach attachment){
   if (attachment == Pull_Up)
      GET_REGISTER_POINTER(portMask+GPIOPUR)|=1<<(CurrentPin);
   else if (attachment == Pull_down)
      GET_REGISTER_POINTER(portMask+GPIOPDR)|=1<<(CurrentPin);
   else if (attachment == Open_Drain) 
      GET_REGISTER_POINTER(portMask+GPIOODR)|=1<<(CurrentPin);


}
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
  uint32 baseAdress;
  uint32 portMask;
   for (uint32 index ; index<DIO_CONFIG_ARRAY_SIZE;index++){
      uint32 currentPin=ConfigPtr[index].portPin.pin;
      uint32 currentPort=ConfigPtr[index].portPin.port;
      baseAdress=PortAdresList[currentPort];
      portMask=GET_BIT_MASK(baseAdress,currentPin);
      

      /*ENABLE AHB ON GPIOHBCTL REGISTER*/

      GET_REGISTER_POINTER(SYSTEM_CONTROL_BUS_ADRESS + GPIOHBCTL)|=1<<(currentPort);

      /*ENABLE CLOCK ON RCGCGPIO REGISTER*/

      GET_REGISTER_POINTER(SYSTEM_CONTROL_BUS_ADRESS + RCGCGPIO)|=1<<(currentPort);

      /*SET PIN DIRECTION ON GPIODIR REGISTER*/
      
      GET_REGISTER_POINTER(portMask)|= (ConfigPtr[index].pinDirection)<<(currentPin);

      /*SET PIN CURRENT ON GPIODR2R , GPIODR4R OR GPIODR8R REGISTERS*/

      Set_Output_Current(portMask,currentPin,ConfigPtr[index].pinOutputCurrent);

      /*SET PIN INTERNAL ATTACHMENT ON GPIOPUR , GPIODPDR OR GPIOODP REGISTER*/

      Set_Internal_Attachment(portMask,currentPin,ConfigPtr[index].pinAttach);

   }
   
   /*TODO MAKE CONDITION IF FUNCTION NOT EQUAL ZERO ENABLE GPIOAFSEL*/
   
   /*TODO MAKE CONDITION IF FUNCTION EQUAL ANALOG ENABLE GPIOAFSEL AND DIABLE GPIODENS*/
   
   /*TODO ENABLE DIGITAL I/O ON GPIODEN REGISTER*/

   /*TODO SET ALTERNAT FUNCTION ON GPIOPCTL AND GPIOAFSEL REGISTERS*/
   
   
   
   
   
   /*TODO ENABLE INTERRUPTS ON GPIOIM , GPIOIS , GPIOIBE AND GPIOLCR REGISTERS*/
}


/******************************************************************
 *  	END OF FILE: Port_Int.c
 *****************************************************************/

