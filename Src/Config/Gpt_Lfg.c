#include "Gpt.h"


void counter(void){

    Gpt_StopTimer(Timer_0_16_32_Bit);
    

}


const  Gpt_ConfigType Gpt_Cfg[GPT_CONFIG_ARRAY_SIZE]={
    /* Gpt_Channel     Gpt_Start_Tick_Value   Gpt_Max_Tick_Value     Gpt_Channel_Mode        GptNotification*/
    {Timer_0_16_32_Bit ,      0x9896800       ,           0         ,        GPT_CH_MODE_CONTINOUS    , (GptNotification)&counter  }
    // ,
//     {Timer_1_16_32_Bit ,      0       ,           0         ,        GPT_CH_MODE_ONESHOT      , 0 /*none*/  }
// 
};

const  Gpt_Driver_Cfg_Type Gpt_Driver_Cfg[PRE_DEFINED_TIMERS_ARRAY_SIZE]=
/*   PREDEF_TIMER_100US_32BIT    , PREDEF_TIMER_US_16BIT  ,   PREDEF_TIMER_1US_24BIT ,  PREDEF_TIMER_1US_32BIT*/
     {        DISABLE            ,        DISABLE         ,         DISABLE          ,           DISABLE       };

