#include "Port_Int.h"
#include "Port_Int_Cfg.h"


/*
Pin Mode Selection:

GPIO 
Uart0
SSI0
I2C0
JTAG_SWD

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
    /*Gpio_Pin_Mode  Gpio_Pin_Level_Value  Gpio_Pin_Direction  Gpio_Pin_Attach  Gpio_Pin_Output_Current */
      {GPIO , Edge_Trig ,OUTPUT,Pull_Up,Pin_Amp_2},
      {GPIO , Level_Trig ,INPUT,Pull_down,Pin_Amp_4},
      {GPIO , Edge_Trig ,OUTPUT,Pull_Up,Pin_Amp_2}


};

