/*
Author: Ahmed Elwakad
version: 1.0
date:10/8/2024
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidEnableInterrupt(u8 copy_u8IntNumber){
    if( copy_u8IntNumber<=31){
        NVIC_ISER0=(1<<copy_u8IntNumber);
    }
    else if(copy_u8IntNumber<=59 ){
        copy_u8IntNumber -=  32; //to make it range from 0 to 31
        NVIC_ISER1=(1<<copy_u8IntNumber);
    }
    else{
        /*return error*/
    }
}

void MNVIC_voidDisableInterrupt(u8 copy_u8IntNumber){
    if( copy_u8IntNumber<=31){
        NVIC_ICER0=(1<<copy_u8IntNumber);
    }
    else if(copy_u8IntNumber<=59 ){
        copy_u8IntNumber -=  32; 
        NVIC_ICER1=(1<<copy_u8IntNumber);
    }
    else{
        /*return error*/
    }
}
void MNVIC_voidSetPendingFlag(u8 copy_u8IntNumber){
    if( copy_u8IntNumber<=31){
        NVIC_ISPR0=(1<<copy_u8IntNumber);
    }
    else if(copy_u8IntNumber<=59 ){
        copy_u8IntNumber -=  32; 
        NVIC_ISPR1=(1<<copy_u8IntNumber);
    }
    else{
        /*return error*/
    }
}
void MNVIC_voidClearPendingFlag(u8 copy_u8IntNumber){
    if( copy_u8IntNumber<=31){
        NVIC_ICPR0=(1<<copy_u8IntNumber);
    }
    else if(copy_u8IntNumber<=59 ){
        copy_u8IntNumber -=  32; 
        NVIC_ICPR1=(1<<copy_u8IntNumber);
    }
    else{
        /*return error*/
    }
}
u8 MNVIC_voidGetActiveFlag(u8 copy_u8IntNumber){
    u8 local_u8Result;
    if( copy_u8IntNumber<=31){
        local_u8Result = GET_BIT(NVIC_IABR0,copy_u8IntNumber);
    }
    else if(copy_u8IntNumber<=59 ){
        copy_u8IntNumber -=  32; 
        local_u8Result = GET_BIT(NVIC_IABR1,copy_u8IntNumber);
    }
    else{
        /*return error*/
    }
    return local_u8Result;
}


void MNVIC_voidSetPriority(s8 copy_s8IntID,u8 copy_u8GroupPriority,u8 copy_u8SubGroupPriority){
   u8 local_u8Priority = (copy_u8SubGroupPriority|(copy_u8GroupPriority<<((NVIC_GROUP_SUB_DISTRIBUTION-0x05FA0300)/256))); //note: 256 = 0x100
   // core peripheral (it can be with -ve id number)

   //external peripheral
   if( copy_s8IntID >= 0){
        NVIC_IPR[copy_s8IntID] = local_u8Priority << 4;
   }
   SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBUTION;
}