/*******************************************************************
 *  FILE DESCIPTION
 *  --------------------------------------------------------------*/
/**     \file  LED_PWM.c
 *      \brief pwm frequency controller
 *
 *      \details controles the on and off time fo an led based on 
 *               timer interrupt flag
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



/******************************************************************
 *  	GLOBAL DATA
 *****************************************************************/
 extern uint32 on_Time ;
 extern uint32 off_Time ;
 
/******************************************************************
 *  	LOCAL FUNCTION PROTOTYPES
 *****************************************************************/
  
/******************************************************************
 *  	LOCAL FUNCTIONS
 *****************************************************************/

/******************************************************************
 *  	LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************************/
#define OneSecond 0xF42400

/******************************************************************
 *  	GLOBAL FUNCTIONS
 *****************************************************************/


/******************************************************************
 * \Syntax          : void Flip_Led(void)
 * \Description     : flips the state of the LED and sets the on and off time for the PWM
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value    : None
 *****************************************************************/   

void Flip_Led (void){

        if(Timer0Flag)
        {
            Gpt_StopTimer(Timer_0_16_32_Bit);

            Dio_ChannelType PORTF1 = {PortF,Pin1};

            Dio_LevelType level =   Dio_ReadPort(PortF);

            if(level != 0)
            {

                Dio_WritePort(PortF,0x0);

                Gpt_StartTimer(Timer_0_16_32_Bit,off_Time*OneSecond);

            }

            else
            {

                Dio_WritePort(PortF,0x2);

                Gpt_StartTimer(Timer_0_16_32_Bit,on_Time*OneSecond);
                
            }
            
            Timer0Flag=LOW;

        }
    
}
 
  
  
 

  





/******************************************************************
 *  	END OF FILE: LED_PWM.c
 *****************************************************************/



   