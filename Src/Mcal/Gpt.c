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

  GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMTAILR)=Value;  
  SET_BIT(GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMCTL),TAEN);
  SET_BIT(GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMICR),TATOCINT);



}

void Gpt_StopTimer (Gpt_ChannelType Channel){
  
  CLR_BIT(GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMCTL),TAEN);
  SET_BIT(GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMICR),TATOCINT);

  
}

void Gpt_Notification_Channel ( void );

Gpt_ValueType Gpt_GetTimeElapsed ( Gpt_ChannelType Channel){

  /*TODO GET THE VALUE OF THE CURRENT TIMER*/
  /*TODO SUBTRACT CURRENT VALUE MAX REGISTER CAPACITY */
  return GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMTAILR) - GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMTAV); 



}

Gpt_ValueType Gpt_GetTimeRemaining (Gpt_ChannelType Channel){

  /*TODO GET THE VALUE OF THE CURRENT TIMER*/
  return GET_REGISTER_POINTER(PortAdresList[Channel]+GPTMTAV); 



}





void TIMER0A_Handler(void){
  
  GptNotification Timer0_CallBack =  Interrupt_Service_Routiens[Timer_0_16_32_Bit];
  if (Timer0_CallBack != NULL){
  SET_BIT(GET_REGISTER_POINTER(Timer_0_16_32_Bit+GPTMICR),TATOCINT);
  Timer0_CallBack();

  }

}





/******************************************************************
 *  	END OF FILE: Gpt.c
 *****************************************************************/

