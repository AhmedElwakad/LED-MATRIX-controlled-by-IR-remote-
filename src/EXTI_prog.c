/*
Author: Ahmed Elwakad
version: 1.0
date:12/8/2024
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*EXTI_CALLBACK[16])(void);
static u8 EXTI_InterruptNum ;

void MEXTI_voidInit(){
    #if EXTI_MODE == RISING     
    SET_BIT(EXTI->RTSR , EXTI_LINE);

    #elif EXTI_MODE == FALLING
    SET_BIT(EXTI->FTSR , EXTI_LINE);

    #elif EXTI_MODE == ON_CHANGE
    SET_BIT(EXTI->RTSR , EXTI_LINE);
    SET_BIT(EXTI->FTSR ,EXTI_LINE );

    #else #error ("Wrong Mode and Line choice")
    #endif

    CLR_BIT(EXTI -> IMR ,EXTI_LINE);
}
void MEXTI_voidEnableEXTI(u8 copy_u8Line){
        SET_BIT(EXTI ->IMR ,copy_u8Line);
}

void MEXTI_voidDisableEXTI(u8 copy_u8Line){
       CLR_BIT(EXTI -> IMR ,copy_u8Line);
}

void MEXTI_voidSwTrigger(u8 copy_u8Line){
    SET_BIT(EXTI ->SWIER ,copy_u8Line);
}

void MEXTI_voidSetSignalLatch(EXTI_line_t copy_Line , EXTI_mode_t copy_Mode){
       switch(copy_Mode){
         case RISING:    SET_BIT(EXTI->RTSR , copy_Line); break;
         case FALLING:   SET_BIT(EXTI->FTSR , copy_Line); break;
         case ON_CHANGE: SET_BIT(EXTI->RTSR , copy_Line);
                         SET_BIT(EXTI->FTSR , copy_Line);
                         break;
        default: break;
       }
       SET_BIT(EXTI ->IMR ,copy_Line);
}

void MEXTI_voidResetSignalLatch(EXTI_line_t copy_Line , EXTI_mode_t copy_Mode){
       switch(copy_Mode){
         case RISING:    CLR_BIT(EXTI->RTSR , copy_Line); break;
         case FALLING:   CLR_BIT(EXTI->FTSR , copy_Line); break;
         case ON_CHANGE: CLR_BIT(EXTI->RTSR , copy_Line);
                         CLR_BIT(EXTI->FTSR , copy_Line);
                         break;
        default: break;
       }
       SET_BIT(EXTI ->IMR ,copy_Line);
}

void MEXTI_voidSetCallBack(void (*copy_ptr)(void), u8 copy_u8InterruptNum){
  EXTI_InterruptNum=copy_u8InterruptNum;
  EXTI_CALLBACK[copy_u8InterruptNum]=copy_ptr;
  
}

void EXTI0_IRQHandler(void){
     
       EXTI_CALLBACK[EXTI_InterruptNum]();
       //clearing pending bit
       SET_BIT(EXTI->PR,EXTI_InterruptNum);
}
void EXTI1_IRQHandler(void){

       EXTI_CALLBACK[EXTI_InterruptNum]();
       //clearing pending bit
       SET_BIT(EXTI->PR,EXTI_InterruptNum);
}
