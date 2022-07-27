#include "IntCtrl.h"


const  Nvic_CfgType Nvic_Cfg[NVIC_ACTIVATED_INT_SIZE]={
    /* Interrupt_Number     Group_Priority    SubGroup_Priority*/
    {Int_16_32_Timer_0B,              1,                0   },
    {Int_16_32_Timer_0A,           0,                0   }
};