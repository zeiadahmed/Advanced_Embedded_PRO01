/*******************************************************************
 *  FILE DESCIPTION
 *  --------------------------------------------------------------*/
/**     \file  Gpt.c
 *      \brief nested vector Interrupt controllrt Driver
 *
 *      \details the Driver Configure ALL MCU interrupts Priority into
 *               groups and subgroups Enable NVIC Interrupt Gate for Peripherals
 *
 ******************************************************************/

/******************************************************************
 *  INCLUDES
 *****************************************************************/
  #include "Std_Types.h"
  #include "Gpt.h"
  #include "Mcu_Hw.h"
  
/******************************************************************
 *  	LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************************/
  #define INTERRUP_HANDLERS_NUMBER 12
  #define CONFIG_32_BIT_IN_16_32_MODE 0x0
  #define CONFIG_16_BIT_IN_16_32_MODE 0x4

/******************************************************************
 *  	LOCAL DATA
 *****************************************************************/
  GptNotification Interrupt_Service_Routiens[INTERRUP_HANDLERS_NUMBER];

static uint32 PortAdresList[12]={
         TIMER_0_16_32_BIT        ,
         TIMER_1_16_32_BIT        ,
         TIMER_2_16_32_BIT        ,
         TIMER_3_16_32_BIT        ,
         TIMER_4_16_32_BIT        ,
         TIMER_5_16_32_BIT        ,
         WIDE_TIMER_0_32_64_BIT   ,
         WIDE_TIMER_1_32_64_BIT   ,
         WIDE_TIMER_2_32_64_BIT   ,
         WIDE_TIMER_3_32_64_BIT   ,
         WIDE_TIMER_4_32_64_BIT   ,
         WIDE_TIMER_5_32_64_BIT   
};

/******************************************************************
 *  	GLOBAL DATA
 *****************************************************************/
 
/******************************************************************
 *  	LOCAL FUNCTION PROTOTYPES
 *****************************************************************/
  
/******************************************************************
 *  	LOCAL FUNCTIONS
 *****************************************************************/
void Clear_Interrupt_Status(Gpt_ChannelType Channel){
  /*TODO CLEAR INTERRUPT FLAG BY SETTING THE FIELD IN GPTMICR REGISTER*/
}



/******************************************************************
 *  	GLOBAL FUNCTIONS
 *****************************************************************/


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
void Gpt_Init(const Gpt_ConfigType *ConfigPtr){
  for (uint32 index=0;index<GPT_CONFIG_ARRAY_SIZE;index++){
  uint8 channelId = ConfigPtr[index].channelId;
  
  

  

  /*TODO ENABLE TIMER BY SETTING THE CORRESPONDING BIT IN RCGCTIMER REGISTER*/
  SET_BIT(GET_REGISTER_POINTER(SYSTEM_CONTROL_BUS_ADRESS+RCGCTIMER),channelId%6);

 


  /*STOP TIMER*/
  Gpt_StopTimer(channelId);

  
  /*TODO SET 16/32 OR 32/64 MODE IN GPTMCFG REGISTER*/
  GET_REGISTER_POINTER(PortAdresList[channelId]+GPTMCFG)=CONFIG_32_BIT_IN_16_32_MODE;

  /*TODO SELECT ONE SHOT OR PERIODIC MODE FROM TAMR FEILD IN GPTMTAMR FOR TIMER A*/
  GET_REGISTER_POINTER(PortAdresList[channelId]+GPTMTAMR)|=ConfigPtr[index].channelMode; //channelMode=0x2 which is continous
  

  /*TODO ENABLE STALL BIT */
  // SET_BIT(GET_REGISTER_POINTER(PortAdresList[channelId]+GPTMCTL),TASTALL); 





  /*TODO SELECT ONE SHOT OR PERIODIC MODE FROM TBMR FEILD IN GPTMTBMR FOR TIMER B*/
  
  /*TODO SELECT COUNT UP OR DOWN FROM TACDIR FEILD ON GPTMTAMR FOR TIMER A*/
  CLR_BIT(GET_REGISTER_POINTER(PortAdresList[channelId]+GPTMTAMR),TACDIR); 

  /*TODO SELECT COUNT UP OR DOWN FROM TBCDIR FEILD ON GPTMTBMR FOR TIMER B*/
  Interrupt_Service_Routiens[channelId]=ConfigPtr->gptNotification;
  
  if(Interrupt_Service_Routiens[channelId] != NULL )

    Gpt_EnableNotification(channelId);
  
  else
  
    Gpt_DisableNotification(channelId);
  
  
  
  /*TODO LOAD INITIAL VALUE FOR TIMER IN GPTMTAILR*/

  /*TODO LOAD INITIAL VALUE FOR TIMER IN GPTMTBILR*/

  Gpt_StartTimer(channelId,ConfigPtr[index].tickValue);

  }
}

void Gpt_DisableNotification (Gpt_ChannelType Channel){

  /*TODO DISABLE TIME OUT INTERRUPT FOR TIMER A BY CLEARING TATOIM BIT ON GPTMIMR REGISTER*/
  CLR_BIT(GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMIMR),TATOIM);
  /*TODO DISABLE TIME OUT INTERRUPT FOR TIMER B BY CLEARING TBTOIM BIT ON GPTMIMR REGISTER*/
  
}

void Gpt_EnableNotification (Gpt_ChannelType Channel){

  SET_BIT(GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMICR),TATOCINT);
  /*TODO ENABLE TIME OUT INTERRUPT FOR TIMER A BY SETTING TATOIM BIT ON GPTMIMR REGISTER*/
  SET_BIT(GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMIMR),TATOIM);
  /*TODO ENABLE TIME OUT INTERRUPT FOR TIMER B BY SETTING TBTOIM BIT ON GPTMIMR REGISTER*/

}

void Gpt_StartTimer (Gpt_ChannelType Channel,Gpt_ValueType Value){

  
  SET_BIT(GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMCTL),TAEN);
  GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMTAILR)=Value;
  SET_BIT(GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMICR),TATOCINT);
  /*TODO START TIMER BY WRITING 1 ON TAEN FEILD IN GPTMCTL REGISTER */
  /*TODO START TIMER BY WRITING 1 ON TBEN FEILD IN GPTMCTL REGISTER */
  


}

void Gpt_StopTimer (Gpt_ChannelType Channel){
  
  CLR_BIT(GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMCTL),TAEN);
  /*TODO STOP TIMER BY WRITING 0 ON TAEN FEILD IN GPTMCTL REGISTER */
  /*TODO STOP TIMER BY WRITING 0 ON TBEN FEILD IN GPTMCTL REGISTER */
  
}

void Gpt_Notification_Channel ( void );

Gpt_ValueType Gpt_GetTimeElapsed ( Gpt_ChannelType Channel){

  /*TODO GET THE VALUE OF THE CURRENT TIMER*/
  
  /*TODO SUBTRACT CURRENT VALUE MAX REGISTER CAPACITY */
  return 0xFFFFFFF-GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMTAV); 
  /*TODO GET THE VALUE OF PRESCALER TIMER*/
  /*TODO SUBTRACT PRESCALER VALUE FROM PRESCALER DIVISOR*/
  /*TODO MULTIPLY THE VALUE OF CURRENT TIMER BY PRESCALER DIVISER*/
  /*TODO ADD BOTH NUMBERS AND RETURN*/


}

Gpt_ValueType Gpt_GetTimeRemaining (Gpt_ChannelType Channel){

  /*TODO GET THE VALUE OF THE CURRENT TIMER*/
  return GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMTAV); 
  /*TODO GET THE VALUE OF PRESCALER TIMER*/
  /*TODO MULTIPLY THE VALUE OF CURRENT TIMER BY PRESCALER DIVISER*/
  /*TODO ADD BOTH NUMBERS AND RETURN*/


}





void TIMER0A_Handler(void){

  GptNotification Timer0_CallBack =  Interrupt_Service_Routiens[Timer_0_16_32_Bit];
  if (Timer0_CallBack != NULL)
  Timer0_CallBack();

}



// Std_ReturnType Gpt_GetPredefTimerValue (Gpt_PredefTimerType PredefTimer, uint32 * TimeValuePtr );


/******************************************************************
 *  	END OF FILE: Dio.c
 *****************************************************************/

  /*TODO STOP TIMER*/
  /*TODO ENABLE TIMER BY SETTING THE CORRESPONDING BIT IN RCGCTIMER REGISTER*/
  /*TODO ENABLE CLOCK GATING CONTROL BY SETTING CORRESPONDING BIT IN RCGC1 REGISTER*/
  /*TODO SET 16/32 OR 32/64 MODE IN GPTMCFG REGISTER*/
  /*TODO SELECT ONE SHOT OR PERIODIC MODE FROM TAMR FEILD IN GPTMTAMR FOR TIMER A*/
  /*TODO SELECT COUNT UP OR DOWN FROM TACDIR FEILD ON GPTMTAMR FOR TIMER A*/
  /*TODO LOAD INITIAL VALUE FOR TIMER IN GPTMTAILR*/
  /*TODO LOAD INITIAL VALUE FOR TIMER IN GPTMTBILR*/