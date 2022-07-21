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


Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);





#endif /*Dio_H*/

/******************************************************************
 *  	END OF FILE: Dio.h
 *****************************************************************/

