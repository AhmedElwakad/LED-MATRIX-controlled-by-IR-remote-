/*
Author: Ahmed Elwakad
version: 1.0
date:17/8/2024
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"
#include "SYSTICK_private.h"


static void(*MSTK_CallBack)(void);

static u8 MSTK_u8ModeOfInterval;

//#define SYSTICK_CLK_SRC     SYSTICK_SRC_AHB_DEV_8

void MSTK_voidInit(){
  #if   SYSTICK_CLK_SRC==SYSTICK_SRC_AHB
    STK->CTRL=0x00000004;
  #elif SYSTICK_CLK_SRC==SYSTICK_SRC_AHB_DEV_8
    STK->CTRL=0x00000000;
  #endif
}
void MSTK_voidBusyWaitMiliSec(u16 copy_u16TimeValue){

 u32 local_u32time =(u32)copy_u16TimeValue*1000;
 STK->LOAD = local_u32time;
 SET_BIT(STK->CTRL,0);
 while(!GET_BIT(STK->CTRL,16));

 CLR_BIT(STK->CTRL,0);
 STK->LOAD =0;
 STK->VAL = 0;

}
void MSTK_voidBusyWaitMicroSec(u32 copy_u32TimeValue){

 STK->LOAD= copy_u32TimeValue;
 SET_BIT(STK->CTRL,0);
 while(!GET_BIT(STK->CTRL,16));

  CLR_BIT(STK->CTRL,0);
  STK->LOAD =0;
  STK->VAL = 0;
}

void MSTK_voidStopInterval(void){
CLR_BIT(STK->CTRL,1);


  CLR_BIT(STK->CTRL,0);
  STK->LOAD =0;
  STK->VAL = 0;
}

u32  MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	
	Local_u32ElapsedTime = STK -> LOAD - STK -> VAL ;
	
	return Local_u32ElapsedTime;
}

u32  MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainTime;
	
	Local_u32RemainTime = STK -> VAL ;
	
	return Local_u32RemainTime;
}


void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/*Disable Timer*/
	 CLR_BIT(STK->CTRL,0);
	 STK->VAL = 0;

	/* Load ticks to load register */
	STK -> LOAD = Copy_u32Ticks;
	
	/* Start Timer */
	SET_BIT(STK->CTRL, 0);
	
	/* Save CallBack */
	MSTK_CallBack = Copy_ptr;
	
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL, 1);
}

void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	STK -> LOAD = Copy_u32Ticks;
	
	/* Start Timer */
	SET_BIT(STK->CTRL, 0);
	
	/* Save CallBack */
	MSTK_CallBack = Copy_ptr;
	
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL, 1);
}


void SysTick_Handler(void)
{
	u8 Local_u8Temporary;
	
	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK->CTRL, 1);
	
		/* Stop Timer */
		SET_BIT(STK->CTRL, 0);
//		STK -> LOAD = 0;
//		STK -> VAL  = 0;
	}
	
	/* Callback notification */
	MSTK_CallBack();
	
	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(STK->CTRL,16);
}
