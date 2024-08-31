/*
Author: Ahmed Elwakad
version: 1.0
date:10/8/2024
*/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


void MNVIC_voidEnableInterrupt(u8 copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(u8 copy_u8IntNumber);
void MNVIC_voidSetPendingFlag(u8 copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 copy_u8IntNumber);
u8 MNVIC_voidGetActiveFlag(u8 copy_u8IntNumber);
void MNVIC_voidSetPriority(s8 copy_s8IntID,u8 copy_u8GroupPriority,u8 copy_u8SubGroupPriority);


#endif
