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
#define NVIC_INTERRUPT_ENABLE								((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define NVIC_INTERRUPT_DIABLE								((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180))
#define NVIC_INTERRUPT_PEND							     	((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x200))
#define NVIC_INTERRUPT_UNPEND							    ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x280))
#define NVIC_INTERRUPT_ACTIVE								((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180))
#define NVIC_INTERRUPT_PRI						   	        ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x200))
#define NVIC_INTERRUPT_SWTRIG								((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x280))
#define APINT                                               ((volatile APINT_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                             ((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))

/*GPIO PORT ADRESSES*/

#define GPIO_Port_A  0x40058000
#define GPIO_Port_B  0x40059000
#define GPIO_Port_C  0x4005A000
#define GPIO_Port_D  0x4005B000
#define GPIO_Port_E  0x4005C000
#define GPIO_Port_F  0x4005D000

/* GPIO REGISTER OFFSETS*/

#define GPIODATA           0x000
#define GPIODIR            0x400
#define GPIOIS             0x404
#define GPIOIBE            0x408
#define GPIOIEV            0x40C
#define GPIOIM             0x410
#define GPIORIS            0x414
#define GPIOMIS            0x418
#define GPIOICR            0x41C
#define GPIOAFSEL          0x420
#define GPIODR2R           0x500
#define GPIODR4R           0x504
#define GPIODR8R           0x508
#define GPIOODR            0x50C
#define GPIOPUR            0x510
#define GPIOPDR            0x514
#define GPIOSLR            0x518
#define GPIODEN            0x51C
#define GPIOLOCK           0x520
#define GPIOCR             0x524
#define GPIOAMSEL          0x528
#define GPIOPCTL           0x52C
#define GPIOADCCTL         0x530
#define GPIOMACTL          0x534
#define GPIOPERIPH_ID_4    0xFD0
#define GPIOPERIPH_ID_5    0xFD4
#define GPIOPERIPH_ID_6    0xFD8
#define GPIOPERIPH_ID_7    0xFDC
#define GPIOPERIPH_ID_0    0xFE0
#define GPIOPERIPH_ID_1    0xFE4
#define GPIOPERIPH_ID_2    0xFE8
#define GPIOPERIPH_ID_3    0xFEC
#define GPIOPCELL_ID0      0xFF0
#define GPIOPCELL_ID1      0xFF4
#define GPIOPCELL_ID2      0xFF8
#define GPIOPCELL_ID3      0xFFC







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

