/*
Author: Ahmed Elwakad
version: 1.0
date:12/8/2024
*/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H



typedef enum{
EXTI_LINE0 ,
EXTI_LINE1 ,
EXTI_LINE2 ,
EXTI_LINE3 ,
EXTI_LINE4 ,
EXTI_LINE5 ,
EXTI_LINE6 ,
EXTI_LINE7 ,
EXTI_LINE8 ,
EXTI_LINE9 ,
EXTI_LINE10,
EXTI_LINE11,
EXTI_LINE12,
EXTI_LINE13,
EXTI_LINE14,
EXTI_LINE15
}EXTI_line_t;

typedef enum{
EXTI_RISING   ,
EXTI_FALLING  ,
EXTI_ON_CHANGE
}EXTI_mode_t;

void MEXTI_voidInit();//you should specify the line and the mode from the config file
void MEXTI_voidEnableEXTI(u8 copy_u8Line); 
void MEXTI_voidDisableEXTI(u8 copy_u8Line); 
void MEXTI_voidSwTrigger(u8 copy_u8Line);

void MEXTI_voidSetSignalLatch(EXTI_line_t copy_Line , EXTI_mode_t copy_Mode);
void MEXTI_voidResetSignalLatch(EXTI_line_t copy_Line , EXTI_mode_t copy_Mode);
void MEXTI_voidSetCallBack(void (*copy_ptr)(void), u8 copy_u8InterruptNum);

#endif
