/*******************************************************************
 *  FILE DESCIPTION
 *  --------------------------------------------------------------*/
/**     \file  Dio.c
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
  #include "Dio.h"
  #include "Mcu_Hw.h"
  
/******************************************************************
 *  	LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************************/


/******************************************************************
 *  	LOCAL DATA
 *****************************************************************/
static uint32 PortAdresList[6]={
                  GPIO_Port_A,
                  GPIO_Port_B,
                  GPIO_Port_C,
                  GPIO_Port_D,
                  GPIO_Port_E,
                  GPIO_Port_F
};
/******************************************************************
 *  	GLOBAL DATA
 *****************************************************************/
 
/******************************************************************
 *  	LOCAL FUNCTION PROTOTYPES
 *****************************************************************/
  
/******************************************************************
 *  	LOCAL FUNCTIONS
 *****************************************************************/


Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){

  uint32 portAdress      =   PortAdresList[ChannelId.port];
  // uint32 pinBitMask      =   portAdress+((0x1<<ChannelId.pin)<<2);             
  // uint32 pinDataAdress   =   pinBitMask+GPIODATA;
  // Dio_LevelType level    =  GET_REGISTER_POINTER(pinDataAdress);
  Dio_LevelType level    =  GET_REGISTER_POINTER(portAdress+0xFF<<2);
  level=(level>>ChannelId.pin)&0x1;
  return level;


}

void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level){

  uint32 portAdress      =   PortAdresList[ChannelId.port];
  uint32 pinBitMask      =   portAdress+((0x1<<ChannelId.pin)<<2);             
  uint32 pinDataAdress   =   pinBitMask+GPIODATA;
  GET_REGISTER_POINTER(pinDataAdress)= Level << ChannelId.pin;
  




}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId){

  uint32 portAdress       =   PortAdresList[PortId];
  uint32 portBitMask      =   portAdress+(0xFF<<2);
  uint32 portDataAdress   =   portBitMask+GPIODATA;
  Dio_PortLevelType level =   GET_REGISTER_POINTER(portDataAdress);
  return level;

}


void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level){

  uint32 portAdress       =   PortAdresList[PortId];
  uint32 portBitMask      =   portAdress+(0xFF<<2);
  uint32 portDataAdress   =   portBitMask+GPIODATA; 
  GET_REGISTER_POINTER(portDataAdress) = Level;


}

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId){
  Dio_LevelType currentLevel = Dio_ReadChannel(ChannelId);
  Dio_WriteChannel(ChannelId, currentLevel== 0 ? 1:0);
  return currentLevel== 0 ? 1:0;


}
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



/******************************************************************
 *  	END OF FILE: Dio.c
 *****************************************************************/

