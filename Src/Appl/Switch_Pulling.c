/*******************************************************************
 *  FILE DESCIPTION
 *  --------------------------------------------------------------*/
/**     \file  Switch_Pulling.c
 *      \brief detecting any presses on the 2 Switches controlling the PWM
 *
 *
 ******************************************************************/

/******************************************************************
 *  INCLUDES
 *****************************************************************/
  
  #include "Std_Types.h"
  #include "Mcu_Hw.h"
  #include "Dio.h"
  #include "Gpt.h"
  #include "Port_Int.h"
/******************************************************************
 *  	LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************************/

/******************************************************************
 *  	LOCAL DATA
 *****************************************************************/
uint8 mode = 0;
boolean IncDefFlag=HIGH;


/******************************************************************
 *  	GLOBAL DATA
 *****************************************************************/

uint32 off_Time= 1;
uint32 on_Time = 1;


/******************************************************************
 *  	LOCAL FUNCTION PROTOTYPES
 *****************************************************************/
  
/******************************************************************
 *  	LOCAL FUNCTIONS
 *****************************************************************/

/******************************************************************
 *  	LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************************/


/******************************************************************
 *  	GLOBAL FUNCTIONS
 *****************************************************************/


/******************************************************************
 * \Syntax          : void Detect_Press(void)
 * \Description     : pulls on the value of the switches on port f
 *                    controlling the switch modes and increamenting/decrementing
 *                    of LED on/off time
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value    : None
 *****************************************************************/   

void Detect_Press (void){

    Dio_PortType SwitchStatus = Dio_ReadPort(PortF);
    boolean switchPin0State = SwitchStatus & 0x1;
    boolean switchPin4State = (SwitchStatus & 0x10)>>4;

    if (switchPin0State == HIGH){
        Dio_WritePort(PortF,0x00);
        mode++;
        if(mode>2) {
            mode=0;
            Timer0Flag=HIGH;
        }
    }

    if (switchPin4State == HIGH){
        
        Dio_WritePort(PortF,0x00);
        if (mode == 1){
            if(IncDefFlag)
                off_Time++;
            else 
                off_Time--;
            }
        else if(mode == 2)
            {
            if(IncDefFlag)
                on_Time++;
            else 
                on_Time--;
            }
        else if(mode == 0)
        {

            if(IncDefFlag == HIGH)IncDefFlag=LOW;

            else IncDefFlag=HIGH;
        
        }

    }

    if(mode != 0){

        Gpt_StopTimer(Timer_0_16_32_Bit);
    
    }


}
 
  
/******************************************************************
 *  	END OF FILE: Dio.c
 *****************************************************************/



   