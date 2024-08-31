/*
Author:Ahmed Elwakad
date:22/8/2024
version :1.0

*/
#ifndef LEDMAT_INTERFACE_H
#define LEDMAT_INTERFACE_H

void HLEDMAT_voidInit();
void HLEDMAT_voidDisplay(u8 *copy_u8Data);
void HLEDMAT_voidScrollText(u8 *text[], u16 textLength, u32 scrollDelay);
void  HLEDMAT_voidDisableAllColumnsandrows();
#endif
