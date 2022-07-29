/*******************************************************************
 *  FILE DESCIPTION
 *  --------------------------------------------------------------*/
/**     File:  Dio.h
 *      Module: Dio
 *
 *      Description: header file for Dio.Module
 *
 *
 ******************************************************************/
 #ifndef Dio_H
 #define Dio_H
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
 *  	GLOBAL DATA TYPES AND STRUCTURES
 *****************************************************************/
 
typedef uint32 Dio_PortLevelType;
typedef enum
{
         PortA =0,
         PortB   ,
         PortC   ,
         PortD   ,
         PortE   ,
         PortF    

}Dio_PortType;

typedef enum
{
    LOW = 0,
    HIGH

}Dio_LevelType;

typedef enum
{
         Pin0 =0,
         Pin1   ,
         Pin2   ,
         Pin3   ,
         Pin4   ,
         Pin5   ,
         Pin6   ,
         Pin7 
}Pin_Num;


typedef struct
{

    /*TODO MAKE STRUCT TO REPRESENT CHANNEL TYPE (PORT,PIN)*/
    Dio_PortType port;
    Pin_Num pin;

}Dio_ChannelType;


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


Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

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

void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);

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

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

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

void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);

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

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);





#endif /*Dio_H*/

/******************************************************************
 *  	END OF FILE: Dio.h
 *****************************************************************/

