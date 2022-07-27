#include "Gpt.h"
#include "Dio.h"

void counter(void){

    Gpt_StopTimer(Timer_0_16_32_Bit);

    Dio_ChannelType PORTF1 = {PortF,Pin1};

    Dio_LevelType level =   Dio_ReadPort(PortF);


    if(level != 0)
    {
        Dio_WritePort(PortF,0x0);
        Gpt_StartTimer(Timer_0_16_32_Bit,0x100);
    }
    else
    {
        Dio_WritePort(PortF,0x2);
        Gpt_StartTimer(Timer_0_16_32_Bit,0x200);
    }

}


const  Gpt_ConfigType Gpt_Cfg[GPT_CONFIG_ARRAY_SIZE]={
    /* Gpt_Channel     Gpt_Start_Tick_Value   Gpt_Max_Tick_Value     Gpt_Channel_Mode        GptNotification*/
    {Timer_0_16_32_Bit ,      0x400       ,           0         ,        GPT_CH_MODE_CONTINOUS    , (GptNotification)&counter  }
    // ,
//     {Timer_1_16_32_Bit ,      0       ,           0         ,        GPT_CH_MODE_ONESHOT      , 0 /*none*/  }
// 
};

const  Gpt_Driver_Cfg_Type Gpt_Driver_Cfg[PRE_DEFINED_TIMERS_ARRAY_SIZE]=
/*   PREDEF_TIMER_100US_32BIT    , PREDEF_TIMER_US_16BIT  ,   PREDEF_TIMER_1US_24BIT ,  PREDEF_TIMER_1US_32BIT*/
     {        DISABLE            ,        DISABLE         ,         DISABLE          ,           DISABLE       };

