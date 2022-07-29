/*******************************************************************
 *  FILE DESCIPTION
 *  --------------------------------------------------------------*/
/**     \file  IntCtrl.c
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
  #include "IntCtrl.h"
  #include "Mcu_Hw.h"
  
/******************************************************************
 *  	LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************************/

 #define NVIC_GROUPING_SYSTEM_XXX  4
 #define NVIC_GROUPING_SYSTEM_XXY  5
 #define NVIC_GROUPING_SYSTEM_XYY  6
 #define NVIC_GROUPING_SYSTEM_YYY  7   

 #define APRINT_VECTKEY             0x05FA
 #define APRINT_VECTKEY_OFFSET      16
 #define PRIGROUP_OFFSET            8
 
 #define PRIORITY_REGISTER_BASE_OFFSET 0x400
 
 #define ENABLE_REGISTER_BASE_OFFSET   0x100

 #define DISABLE_INT_I()        __asm__("CPSID i");         /*  Disable interrupts and all fault handlers (set PRIMASK)          */
 #define DISABLE_INT_F()        __asm__("CPSID f");         /*  Disable interrupts and all fault handlers (set FAULTMASK)          */
 #define ENABLE_INT_I()         __asm__("CPSIE i");         /*  Enable interrupts and all fault handlers (set PRIMASK)          */
 #define ENABLE_INT_F()         __asm__("CPSIE f");         /*  Enable interrupts and all fault handlers (set FAULTMASK)          */
/******************************************************************
 *  	LOCAL DATA
 *****************************************************************/
 
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
 * \Syntax          : uint32 Get_Group_Priority(void)
 * \Description     : returns the 3 bit value corresponfing to grouping 
 *                    division chosen by the used
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : groupPriority the priority of interrupt sorted by group
 *                    subgroupPriotity the priority of the interrupt within the group
 * \Parameters (out): uint32 the value of the interrupt priority
 * \Return value    : None
 *****************************************************************/ 

 uint32 Get_Group_Priority(uint8 groupPriority,uint8 subgroupPriotity){
    switch (NVIC_GROUPING_SYSTEM)
    {
      case NVIC_GROUPING_SYSTEM_XXX:
        return groupPriority;
        break;
      case NVIC_GROUPING_SYSTEM_XXY:
        return (groupPriority<<1)+subgroupPriotity; 
        break;
      case NVIC_GROUPING_SYSTEM_XYY:
        return (groupPriority<<2)+subgroupPriotity;
        break;
      case NVIC_GROUPING_SYSTEM_YYY:
        return subgroupPriotity;
        break;
      default:
        break;
    }


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

void IntCtrl_Init(void)
{
    ENABLE_INT_F();
    ENABLE_INT_I();
    APINT->R|=(APRINT_VECTKEY<<APRINT_VECTKEY_OFFSET)+(NVIC_GROUPING_SYSTEM<<PRIGROUP_OFFSET);

    for(uint32 index ; index < NVIC_ACTIVATED_INT_SIZE ; index++){

      uint32 priorityRegisterNum=Nvic_Cfg[index].interruptNumber/4;          //0-44

      uint32 interruptPriorityInRegister=Nvic_Cfg[index].interruptNumber%4;  //0-3

      uint32 pri_Offset=PRIORITY_REGISTER_BASE_OFFSET+priorityRegisterNum*4; //0x400-0x488

      uint32 interruptShift=5+interruptPriorityInRegister*8;                 //5-29

      uint32 priority = Get_Group_Priority(Nvic_Cfg[index].groupPriority,Nvic_Cfg[index].subgroupPriotity);

      GET_REGISTER_POINTER(CORTEXM4_PERI_BASE_ADDRESS+pri_Offset)|=priority<<interruptShift;

      uint32 enableRegisterOffset=Nvic_Cfg[index].interruptNumber/32;          //0-10

      uint32 interruptPosInEnable=Nvic_Cfg[index].interruptNumber%32;          //0-31

      uint32 enable_Offset=ENABLE_REGISTER_BASE_OFFSET+enableRegisterOffset*4; //0x100 - 0x110

      SET_BIT(GET_REGISTER_POINTER(CORTEXM4_PERI_BASE_ADDRESS+enable_Offset),interruptPosInEnable);


   

    }

}


/******************************************************************
 *  	END OF FILE: IntCtrl.c
 *****************************************************************/

