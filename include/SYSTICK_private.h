/*
Author: Ahmed Elwakad
version: 1.0
date:17/8/2024
*/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

typedef struct 
{
   volatile u32 CTRL;
   volatile u32 LOAD;
   volatile u32 VAL;
   volatile u32 CALIB;
}STK_t;

#define STK_OFFSET_ADDRESS 0xE000E010
#define STK ((volatile STK_t*)STK_OFFSET_ADDRESS)

#define  SYSTICK_SRC_AHB            0
#define  SYSTICK_SRC_AHB_DEV_8      1

#define  MSTK_SINGLE_INTERVAL    0
#define  MSTK_PERIOD_INTERVAL    1


#endif