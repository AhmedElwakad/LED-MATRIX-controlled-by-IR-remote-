/*
Author: Ahmed Elwakad
version: 1.0
date:17/8/2024
*/
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

#define delay_ms MSTK_voidBusyWaitMiliSec
#define delay_us MSTK_voidBusyWaitMicroSec

void MSTK_voidInit();
void MSTK_voidBusyWaitMiliSec(u16 copy_u16TimeValue);
void MSTK_voidBusyWaitMicroSec(u32 copy_u32TimeValue);
void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidStopInterval(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainingTime(void);

#endif