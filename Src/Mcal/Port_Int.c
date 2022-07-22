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
void Set_Output_Current(uint32 baseAdress,Pin_Num CurrentPin,PortPinOutputCurrent outCurrent){
   if (outCurrent == Pin_Amp_2)
      SET_BIT(GET_REGISTER_POINTER(baseAdress+GPIODR2R),CurrentPin);
   else if (outCurrent == Pin_Amp_4)
      SET_BIT(GET_REGISTER_POINTER(baseAdress+GPIODR4R),CurrentPin);
   else if (outCurrent == Pin_Amp_8) 
      SET_BIT(GET_REGISTER_POINTER(baseAdress+GPIODR8R),CurrentPin);


}


void Set_Internal_Attachment(uint32 baseAdress,Pin_Num CurrentPin,PortPinInternalAttach attachment){
   if (attachment == Pull_Up)
      SET_BIT(GET_REGISTER_POINTER(baseAdress+GPIOPUR),CurrentPin);
   else if (attachment == Pull_down)
      SET_BIT(GET_REGISTER_POINTER(baseAdress+GPIOPDR),CurrentPin);
   else if (attachment == Open_Drain) 
      SET_BIT(GET_REGISTER_POINTER(baseAdress+GPIOODR),CurrentPin);


}

void Set_Port_Pin_Functionality(uint32 baseAdress,Pin_Num currentPin,Dio_PortType currentPort,PortPinMode mode,Dio_LevelType level){
   
   if (mode == ANALOG_FUNCTION){

      
      CLR_BIT(GET_REGISTER_POINTER(baseAdress+GPIODEN),currentPin);
      SET_BIT(GET_REGISTER_POINTER(baseAdress+GPIOAMSEL),currentPin);

   }

   else if (mode == GPIO ) {
      
      CLR_BIT(GET_REGISTER_POINTER(baseAdress+GPIOAFSEL),currentPin);
      SET_BIT(GET_REGISTER_POINTER(baseAdress+GPIODEN),currentPin);
      Dio_ChannelType pin = {currentPort,currentPin};
      Dio_WriteChannel(pin,level);


   }

   else {

      SET_BIT(GET_REGISTER_POINTER(baseAdress+GPIOAFSEL),currentPin);
      SET_BIT(GET_REGISTER_POINTER(baseAdress+GPIODEN),currentPin);
      GET_REGISTER_POINTER(baseAdress+GPIOPCTL)|=mode<<(currentPin*4);

   }

}

void Set_Interrupts(uint32 baseAdress,Pin_Num currentPin,Interrupt_Type interruptType){
   CLR_BIT(GET_REGISTER_POINTER(baseAdress + GPIOIM),currentPin);
   if(interruptType != NONE){
      
      if(interruptType == FALLING_EGDE){
         CLR_BIT(GET_REGISTER_POINTER(baseAdress + GPIOIS),currentPin);
         CLR_BIT(GET_REGISTER_POINTER(baseAdress + GPIOIBE),currentPin);
         CLR_BIT(GET_REGISTER_POINTER(baseAdress + GPIOIEV),currentPin);
      }
      
      else if(interruptType == RISING_EDGE){
         CLR_BIT(GET_REGISTER_POINTER(baseAdress + GPIOIS),currentPin);
         CLR_BIT(GET_REGISTER_POINTER(baseAdress + GPIOIBE),currentPin);
         SET_BIT(GET_REGISTER_POINTER(baseAdress + GPIOIEV),currentPin);
      }

      

      else if(interruptType == HIGH_LEVELS){
         SET_BIT(GET_REGISTER_POINTER(baseAdress + GPIOIS),currentPin);
         CLR_BIT(GET_REGISTER_POINTER(baseAdress + GPIOIBE),currentPin);
         SET_BIT(GET_REGISTER_POINTER(baseAdress + GPIOIEV),currentPin);
      }
      
      else if(interruptType == LOW_LEVELS){
         SET_BIT(GET_REGISTER_POINTER(baseAdress + GPIOIS),currentPin);
         CLR_BIT(GET_REGISTER_POINTER(baseAdress + GPIOIBE),currentPin);
         CLR_BIT(GET_REGISTER_POINTER(baseAdress + GPIOIEV),currentPin);
      }
      
      else if(interruptType == BOTH_EDGES){
         CLR_BIT(GET_REGISTER_POINTER(baseAdress + GPIOIS),currentPin);
         SET_BIT(GET_REGISTER_POINTER(baseAdress + GPIOIBE),currentPin);
        
      }
      
      SET_BIT(GET_REGISTER_POINTER(baseAdress + GPIOICR),currentPin);
      SET_BIT(GET_REGISTER_POINTER(baseAdress + GPIOIM),currentPin);

     
   }
   

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
      
      

      /*ENABLE AHB ON GPIOHBCTL REGISTER*/

      SET_BIT(GET_REGISTER_POINTER(SYSTEM_CONTROL_BUS_ADRESS + GPIOHBCTL),currentPort);

      /*ENABLE CLOCK ON RCGCGPIO REGISTER*/

      SET_BIT(GET_REGISTER_POINTER(SYSTEM_CONTROL_BUS_ADRESS + RCGCGPIO),currentPort);

      /*SET PIN DIRECTION ON GPIODIR REGISTER*/

      if(ConfigPtr[index].pinDirection)
         SET_BIT(GET_REGISTER_POINTER(baseAdress + GPIODIR),currentPin);
      else
         CLR_BIT(GET_REGISTER_POINTER(baseAdress + GPIODIR),currentPin);

      /*SET PIN CURRENT ON GPIODR2R , GPIODR4R OR GPIODR8R REGISTERS*/

      Set_Output_Current(baseAdress,currentPin,ConfigPtr[index].pinOutputCurrent);

      /*SET PIN INTERNAL ATTACHMENT ON GPIOPUR , GPIODPDR OR GPIOODP REGISTER*/

      Set_Internal_Attachment(baseAdress,currentPin,ConfigPtr[index].pinAttach);

      /*SET ALTERNAT FUNCTION ON GPIOPCTL AND GPIOAFSEL REGISTERS*/

      Set_Port_Pin_Functionality(baseAdress,currentPin,currentPort,ConfigPtr[index].pinMode,ConfigPtr[index].pinLevelValue);

      /*SET GPIO PINS AS INTERRUPT*/

      Set_Interrupts(baseAdress,currentPin,ConfigPtr[index].pinInterruptType);
      

      



   }
   
   


}


/******************************************************************
 *  	END OF FILE: Port_Int.c
 *****************************************************************/

