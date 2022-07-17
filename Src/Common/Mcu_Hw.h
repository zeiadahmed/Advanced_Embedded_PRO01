/*******************************************************************
 *  FILE DESCIPTION
 *  --------------------------------------------------------------*/
/**     File:  Mcu_Hw.h
 *      Module: Mcu_Hw
 *
 *      Description: header file for register definition
 *
 *
 ******************************************************************/
 #ifndef Mcu_Hw_H
 #define Mcu_Hw_H
/******************************************************************
 *  INCLUDES
 *****************************************************************/
#include "Std_Types.h"
  
/******************************************************************
 *  	GLOBAL DATA TYPES AND STRUCTURES
 *****************************************************************/
typedef struct 
{
    /* data */
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1;

}INTCTRL_BF;

typedef struct 
{
    /* data */
    uint32 VECTRESET :1;
    uint32 VECTCLRACT:1;
    uint32 SYSRESREQ :1;
    uint32           :5;
    uint32 PRIGROUP  :3;
    uint32           :4;
    uint32 ENDIANESS :1;
    uint32 VECTKEY   :16;
}APINT_BF;

typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

typedef union 
{
    uint32 R;
    APINT_BF B;
}APINT_Tag;



 


/******************************************************************
 *  	GLOBAL CONSTANT
 *****************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS                      0xE000E000
#define APINT                                           *((volatile APINT_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                         *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
/******************************************************************
 *  	LOCAL DATA
 *****************************************************************/
 
/******************************************************************
 *  	GLOBAL DATA
 *****************************************************************/
 

#endif /*Mcu_Hw_H*/

/******************************************************************
 *  	END OF FILE: Mcu_Hw.h
 *****************************************************************/

