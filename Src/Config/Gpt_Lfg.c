#include "Gpt.h"
#include "Dio.h"

boolean Timer0Flag=LOW;
void counter(void){

        Gpt_StopTimer(Timer_0_16_32_Bit);
        Timer0Flag=HIGH;
      

    
}


const  Gpt_ConfigType Gpt_Cfg[GPT_CONFIG_ARRAY_SIZE]={
    /* Gpt_Channel     Gpt_Start_Tick_Value   Gpt_Max_Tick_Value     Gpt_Channel_Mode        GptNotification*/
    {Timer_0_16_32_Bit ,      0x400       ,           0         ,        GPT_CH_MODE_CONTINOUS    , (GptNotification)&counter  }

};

const  Gpt_Driver_Cfg_Type Gpt_Driver_Cfg[PRE_DEFINED_TIMERS_ARRAY_SIZE]=
/*   PREDEF_TIMER_100US_32BIT    ,  PREDEF_TIMER_1US_32BIT*/
     {        DISABLE            ,            DISABLE       };

