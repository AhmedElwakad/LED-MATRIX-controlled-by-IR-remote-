/*
author: Ahmed Elwakad
version: 1.0
date: 1/7/2024
*/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"


void MGPIO_voidSetPinDirection(u8 copy_u8PORT,u8 copy_u8PIN ,u8 copy_u8Mode){

switch(copy_u8PORT){
    case GPIOA:
             if(copy_u8PIN <= 7){

                GPIOA_CRL &= ~ ((0b1111) << (copy_u8PIN*4)); //reseting the configeration and the mode

                GPIOA_CRL |= ((copy_u8Mode) << (copy_u8PIN*4));//setting the configeration and the mode
             }
             else if(copy_u8PIN <= 15){
                copy_u8PIN = copy_u8PIN-8;

                GPIOA_CRH &= ~ ((0b1111) << (copy_u8PIN*4)); //reseting the configeration and the mode

                GPIOA_CRH |= ((copy_u8Mode) << (copy_u8PIN*4));//setting the configeration and the mode
             
             }
             break;

    case GPIOB:
            if(copy_u8PIN <= 7){

                GPIOB_CRL &= ~ ((0b1111) << (copy_u8PIN*4)); //reseting the configeration and the mode

                GPIOB_CRL |= ((copy_u8Mode) << (copy_u8PIN*4));//setting the configeration and the mode
             }
             else if(copy_u8PIN <= 15){
                copy_u8PIN = copy_u8PIN-8;

                GPIOB_CRH &= ~ ((0b1111) << (copy_u8PIN*4)); //reseting the configeration and the mode

                GPIOB_CRH |= ((copy_u8Mode) << (copy_u8PIN*4));//setting the configeration and the mode
            
             }
              break;

    case GPIOC:
            if(copy_u8PIN <= 7){

                GPIOC_CRL &= ~ ((0b1111) << (copy_u8PIN*4)); //reseting the configeration and the mode

                GPIOC_CRL |= ((copy_u8Mode) << (copy_u8PIN*4));//setting the configeration and the mode
             }
             else if(copy_u8PIN <= 15){
                copy_u8PIN = copy_u8PIN-8;

                GPIOC_CRH &= ~ ((0b1111) << (copy_u8PIN*4)); //reseting the configeration and the mode

                GPIOC_CRH |= ((copy_u8Mode) << (copy_u8PIN*4));//setting the configeration and the mode
             
             }
              break;

    default: break;

}


}

void MGPIO_voidSetPinValue(u8 copy_u8PORT,u8 copy_u8PIN ,u8 copy_u8Value){

switch(copy_u8PORT){
    case GPIOA:
    if(copy_u8Value==GPIO_HIGH){
        SET_BIT(GPIOA_ODR,copy_u8PIN);
    }
    else if(copy_u8Value==GPIO_LOW){
        CLR_BIT(GPIOA_ODR,copy_u8PIN);
    }
    break;

    case GPIOB:
    if(copy_u8Value==GPIO_HIGH){
        SET_BIT(GPIOB_ODR,copy_u8PIN);
    }
    else if(copy_u8Value==GPIO_LOW){
        CLR_BIT(GPIOB_ODR,copy_u8PIN);
    }
    break;

    case GPIOC:
    if(copy_u8Value==GPIO_HIGH){
        SET_BIT(GPIOC_ODR,copy_u8PIN);
    }
    else if(copy_u8Value==GPIO_LOW){
        CLR_BIT(GPIOC_ODR,copy_u8PIN);
    }
    break;

    default: break;
}

}

u8 MGPIO_voidGetPinValue(u8 copy_u8PORT,u8 copy_u8PIN ){
u8 local_u8result;
switch(copy_u8PORT){
    case GPIOA: local_u8result= GET_BIT(GPIOA_IDR,copy_u8PIN);
    break;

    case GPIOB: local_u8result= GET_BIT(GPIOA_IDR,copy_u8PIN);
    break;

    case GPIOC: local_u8result= GET_BIT(GPIOA_IDR,copy_u8PIN);
    break;
    
    default: break;
}
return local_u8result;
}


void MGPIO_voidSet7ConsecutivePins(u8 copy_u8PORT,u8 copy_u8HighEndBit,u8 copy_u8Data){
	switch(copy_u8PORT){

	    case GPIOA:
	    	 GPIOA_ODR &= ~(0x7F <<copy_u8HighEndBit);
	    	 GPIOA_ODR |= (copy_u8Data <<copy_u8HighEndBit);
	    break;

	    case GPIOB:
	    	GPIOB_ODR &= ~(0x7F <<copy_u8HighEndBit);
	    	GPIOB_ODR |= (copy_u8Data <<copy_u8HighEndBit);
	    break;

	    case GPIOC:
	    	GPIOC_ODR &= ~(0x7F <<copy_u8HighEndBit);
	    	GPIOC_ODR |= (copy_u8Data <<copy_u8HighEndBit);
	    break;

	    default: break;



	}
}
