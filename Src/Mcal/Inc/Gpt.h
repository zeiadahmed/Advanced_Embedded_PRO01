/*******************************************************************
 *  FILE DESCIPTION
 *  --------------------------------------------------------------*/
/**     File:  Gpt.h
 *      Module: GPT
 *
 *      Description: header file for Gpt.Module
 *
 *
 ******************************************************************/
 #ifndef GPT_H
 #define GPT_H
/******************************************************************
 *  INCLUDES
 *****************************************************************/
#include "Std_Types.h"
#include "Gpt_Cfg.h"

  
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


/*Gpt_Tick_ValueType*/

typedef uint32 Gpt_ValueType;

/*Gpt_Notification_Type*/

typedef void(* GptNotification ) (void);

/*Gpt_ChannelType*/

typedef enum
{
    Timer_0_16_32_Bit      =0   ,
    Timer_1_16_32_Bit           ,
    Timer_2_16_32_Bit           ,
    Timer_3_16_32_Bit           ,
    Timer_4_16_32_Bit           ,
    Timer_5_16_32_Bit           ,
    Wide_Timer_0_32_64_Bit      ,
    Wide_Timer_1_32_64_Bit      ,
    Wide_Timer_2_32_64_Bit      ,
    Wide_Timer_3_32_64_Bit      ,
    Wide_Timer_4_32_64_Bit      ,
    Wide_Timer_5_32_64_Bit    

}Gpt_ChannelType;

/*Gpt_Mode_Type*/

typedef enum
{
    
    GPT_CH_MODE_ONESHOT   = 0x1,
    GPT_CH_MODE_CONTINOUS = 0x2

}Gpt_Channel_Mode_Type;

/*Gpt_ModeType*/

typedef enum
{
    GPT_MODE_NORMAL= 0,
    GPT_MODE_SLEEP

}Gpt_Mode_Type;



/*Gpt_PredefTimerType*/

typedef struct 
{
    /*TODO SEE IF YOU WILL ADD TICK FREQURNCY*/
    boolean GPT_PREDEF_TIMER_100US_32BIT;
    boolean GPT_PREDEF_TIMER_US_16BIT;
    boolean GPT_PREDEF_TIMER_1US_24BIT;
    boolean GPT_PREDEF_TIMER_1US_32BIT;
    
}Gpt_Driver_Cfg_Type;

/*Gpt_ConfigType*/
typedef struct 
{
    Gpt_ChannelType channelId;
    Gpt_ValueType tickValue;
    Gpt_ValueType maxTickValue;
    Gpt_Channel_Mode_Type channelMode;
    GptNotification	gptNotification;

}Gpt_ConfigType;




/******************************************************************
 * \Syntax          : void Gpt_Init(const Gpt_ConfigType *ConfigPtr)
 * \Description     : Initialize the general purpose timers according 
 *                    to user configurations
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : ConfigPtr the array of user configurations for each selected timer
 * \Parameters (out): None
 * \Return value    : None
 *****************************************************************/

void Gpt_Init(const Gpt_ConfigType *ConfigPtr);

/******************************************************************
 * \Syntax          : void Gpt_DisableNotification(Gpt_ChannelType Channel)
 * \Description     : disables the Interrupt on a given channel 
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Channel channel to disable its interrupts
 * \Parameters (out): None
 * \Return value    : None
 *****************************************************************/

void Gpt_DisableNotification (Gpt_ChannelType Channel);

/******************************************************************
 * \Syntax          : void Gpt_EnableNotification(Gpt_ChannelType Channel)
 * \Description     : enables the Interrupt on a given channel 
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Channel channel to enable its interrupts
 * \Parameters (out): None
 * \Return value    : None
 *****************************************************************/

void Gpt_EnableNotification (Gpt_ChannelType Channel);

/******************************************************************
 * \Syntax          : void Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType Value)
 * \Description     : enables the timer TEN feild to start the timer
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Channel the channel number to start
 *                    Value the preload value to start the timer with
 * \Parameters (out): None
 * \Return value    : None
 *****************************************************************/

void Gpt_StartTimer (Gpt_ChannelType Channel,Gpt_ValueType Value);

/******************************************************************
 * \Syntax          : void Gpt_StopTimer(Gpt_ChannelType Channel)
 * \Description     : disables the timer TEN feild to stop the timer
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Channel the channel number to stop
 * \Parameters (out): None
 * \Return value    : None
 *****************************************************************/

void Gpt_StopTimer (Gpt_ChannelType Channel);

/******************************************************************
 * \Syntax          : Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
 * \Description     : returns the number of counted ticks from the start of the timer
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Channel the channel id to get its elapsed tick value
 * \Parameters (out): Gpt_ValueType the elapsed tick value 
 * \Return value    : None
 *****************************************************************/

Gpt_ValueType Gpt_GetTimeElapsed ( Gpt_ChannelType Channel );

/******************************************************************
 * \Syntax          : Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
 * \Description     : returns the number of ticks still remaining for the timer to reset
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Channel the channel id to get its remaining tick value
 * \Parameters (out): Gpt_ValueType the remaining tick value 
 * \Return value    : None
 *****************************************************************/

Gpt_ValueType Gpt_GetTimeRemaining (Gpt_ChannelType Channel);



/******************************************************************
 *  	GLOBAL DATA PROTOTYPES
 *****************************************************************/
extern const  Gpt_ConfigType Gpt_Cfg[];
extern const  Gpt_Driver_Cfg_Type Gpt_Driver_Cfg[];
extern boolean Timer0Flag;

#endif /*GPT_H*/

/******************************************************************
 *  	END OF FILE: Gpt.h
 *****************************************************************/

