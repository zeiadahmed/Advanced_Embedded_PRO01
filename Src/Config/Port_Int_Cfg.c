#include "Port_Int.h"
#include "Port_Int.h"


/*attempted ISR callback*/

// uint32 mode =0;
uint32 offTime= 1;
uint32 onTime = 1;
boolean onOffFlag=HIGH;

void Switch_Callback(Pin_Num pin){
      /*mode changing switch*/
      if(pin==Pin0){
        // mode++;
        // if(mode>2) mode=0;
      }
      /*alternate function switch*/
      else if(pin==Pin4){

      // if (mode == 0)offTime++;

      // else if(mode == 1)onTime++;
      
      // else if(mode == 2)
      // {

      //   if(onOffFlag == HIGH)onOffFlag=LOW;

      //   else onOffFlag=HIGH;
      
      // }
    
    

  }
} 

const Port_ConfigType ConfigType [DIO_CONFIG_ARRAY_SIZE]={

    /*Gpio_Pin_Mode  Gpio_Pin_Level_Value  Gpio_Pin_Direction  Gpio_Pin_Attach  Gpio_Pin_Output_Current pinInterruptType*/

      { { PortB , Pin0 }  , GPIO , HIGH  , OUTPUT , Pull_Up , Pin_Amp_2 ,  NONE         ,  NULL},
      { { PortB , Pin1 }  , GPIO , HIGH  , OUTPUT , Pull_Up , Pin_Amp_2 ,  FALLING_EGDE ,  NULL},
      { { PortB , Pin2 }  , GPIO , HIGH  , OUTPUT , Pull_Up , Pin_Amp_2 ,  HIGH_LEVELS  ,  NULL},
      { { PortB , Pin3 }  , GPIO , HIGH  , OUTPUT , Pull_Up , Pin_Amp_2 ,  BOTH_EDGES   ,  NULL},
      { { PortB , Pin4 }  , GPIO , HIGH  , OUTPUT , Pull_Up , Pin_Amp_2 ,  NONE         ,  NULL},
      { { PortB , Pin5 }  , GPIO , HIGH  , OUTPUT , Pull_Up , Pin_Amp_2 ,  NONE         ,  NULL},
      { { PortF , Pin1 }  , GPIO , HIGH  , OUTPUT , Pull_Up , Pin_Amp_2 ,  NONE         ,  NULL},
      { { PortF , Pin0 }  , GPIO , HIGH  , INPUT  , Pull_Up , Pin_Amp_2 ,  BOTH_EDGES ,  (GpioNotification)&Switch_Callback},
      { { PortF , Pin4 }  , GPIO , HIGH  , INPUT  , Pull_Up , Pin_Amp_2 ,  LOW_LEVELS ,  (GpioNotification)&Switch_Callback}



};


