/*
Author: Ahmed Elwakad
version: 1.0
date:12/8/2024
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"




void	MAFIO_voidSetEXTIConfiguration(AFIO_EXTI_LINE_t copy_Line ,AFIO_EXTI_PORTS_t copy_PortMap)
{
	u8 Local_u8RegIndex = 0 ;		
	/* Assign to EXTICRX register									*/
	if(copy_Line <= 3 )
	{
			Local_u8RegIndex = 0;
	}
	else if(copy_Line<=7)
	{
			/*	another	solution									*/
			/*	line 7 => 1.... 									*/
			/*	Local_u8RegIndex = copy_u8Line/4					*/
			/*	copy_u8Line = copy_u8Line%4 => (3 in the EXTICR2)	*/	
		Local_u8RegIndex = 1;
		copy_Line -= 4;
	}
	else if(copy_Line<=11)
	{
		Local_u8RegIndex = 2;
		copy_Line -= 8;
	
	}
	else if(copy_Line<=15)
	{
		Local_u8RegIndex = 3;
		copy_Line -= 12;
	}
	AFIO->EXTICR[Local_u8RegIndex] &= ~((0b1111) << (copy_Line * 4));
	AFIO->EXTICR[Local_u8RegIndex]  |= ((copy_PortMap) << (copy_Line * 4));
}
