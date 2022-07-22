#include "Port_Int.h"
#include "Port_Int_Cfg.h"


/*
Pin Mode Selection:

TODO MAKE APPROPRIATE MODE SELECTION

Pin Level Value:
Edge_Trig
Level_Trig

Pin Direction:
OUTPUT
INPUT

Pin Attachment:
Pull_Up
Pull_down
Open_Drain

Pin Output Current:
Pin_Amp_2
Pin_Amp_4
Pin_Amp_8

*/

const Port_ConfigType ConfigType [DIO_CONFIG_ARRAY_SIZE]={

    /*Gpio_Pin_Mode  Gpio_Pin_Level_Value  Gpio_Pin_Direction  Gpio_Pin_Attach  Gpio_Pin_Output_Current pinInterruptType*/

      { { PortB , Pin0 }  , GPIO , HIGH  , OUTPUT , Pull_Up , Pin_Amp_2 ,  NONE         },
      { { PortB , Pin1 }  , GPIO , HIGH  , OUTPUT , Pull_Up , Pin_Amp_2 ,  FALLING_EGDE },
      { { PortB , Pin2 }  , GPIO , HIGH  , OUTPUT , Pull_Up , Pin_Amp_2 ,  HIGH_LEVELS  },
      { { PortB , Pin3 }  , GPIO , HIGH  , OUTPUT , Pull_Up , Pin_Amp_2 ,  BOTH_EDGES   },
      { { PortB , Pin4 }  , GPIO , HIGH  , OUTPUT , Pull_Up , Pin_Amp_2 ,  NONE         },
      { { PortB , Pin5 }  , GPIO , HIGH  , OUTPUT , Pull_Up , Pin_Amp_2 ,  NONE         }


};


