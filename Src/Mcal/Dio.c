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

/******************************************************************
 * \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
 * \Description     : returns the value on a given channel
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : ChannelId the channel struct indicating port and pin number  
 * \Parameters (out): Dio_LevelType
 * \Return value    : None
 *****************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){

  uint32 portAdress      =   PortAdresList[ChannelId.port];
  uint32 pinBitMask      =   portAdress+((0x1<<ChannelId.pin)<<2);             
  uint32 pinDataAdress   =   pinBitMask+GPIODATA;
  Dio_LevelType level    =  GET_REGISTER_POINTER(pinDataAdress);
  return level >> ChannelId.pin;


}

/******************************************************************
 * \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level)
 * \Description     : write a given level value on a chosen channel 
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Level the value to be written in the channel 
 *                    ChannelId the channel struct indicating port and pin number  
 * \Parameters (out): None
 * \Return value    : None
 *****************************************************************/

void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level){

  uint32 portAdress      =   PortAdresList[ChannelId.port];
  uint32 pinBitMask      =   portAdress+((0x1<<ChannelId.pin)<<2);             
  uint32 pinDataAdress   =   pinBitMask+GPIODATA;
  GET_REGISTER_POINTER(pinDataAdress)= Level << ChannelId.pin;
  
}

/******************************************************************
 * \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
 * \Description     : returns the value on a chosen port in the gpio
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : PortId the port id to read from
 * \Parameters (out): Dio_PortLevelType the value on the chosen port
 * \Return value    : None
 *****************************************************************/

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId){

  uint32 portAdress       =   PortAdresList[PortId];
  uint32 portBitMask      =   portAdress+(0xFF<<2);
  uint32 portDataAdress   =   portBitMask+GPIODATA;
  Dio_PortLevelType level =   GET_REGISTER_POINTER(portDataAdress);
  return level;

}

/******************************************************************
 * \Syntax          : void Dio_WritePort(void)
 * \Description     : writes a value on a chosen port in the gpio
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : PortId the port number to write on
 *                    Level the value to write on the desired port
 * \Parameters (out): None
 * \Return value    : None
 *****************************************************************/

void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level){

  uint32 portAdress       =   PortAdresList[PortId];
  uint32 portBitMask      =   portAdress+(0xFF<<2);
  uint32 portDataAdress   =   portBitMask+GPIODATA; 
  GET_REGISTER_POINTER(portDataAdress) = Level;


}

/******************************************************************
 * \Syntax          : Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
 * \Description     : toggle the value on a given channel 
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : ChannelId the channel that will be toggled
 * \Parameters (out): Dio_LevelType the new value of the channel after the toggle
 * \Return value    : None
 *****************************************************************/

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

