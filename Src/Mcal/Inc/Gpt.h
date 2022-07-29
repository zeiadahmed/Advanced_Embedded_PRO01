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

void Gpt_Init(const Gpt_ConfigType *ConfigPtr);

void Gpt_DisableNotification (Gpt_ChannelType Channel);

void Gpt_EnableNotification (Gpt_ChannelType Channel);

void Gpt_StartTimer (Gpt_ChannelType Channel,Gpt_ValueType Value);

void Gpt_StopTimer (Gpt_ChannelType Channel);

void Gpt_Notification_Channel ( void );

Gpt_ValueType Gpt_GetTimeElapsed ( Gpt_ChannelType Channel);

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

