/*
Author: Ahmed Elwakad
version: 1.0
date:10/8/2024
*/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/*NVIC base address 0xE000E100*/
#define NVIC_OFFSET_ADDRESS 0xE000E100

#define NVIC_ISER0  (*((volatile u32*)(NVIC_OFFSET_ADDRESS + 0x000))) //enable external interrupts from 0 to 31
#define NVIC_ISER1  (*((volatile u32*)(NVIC_OFFSET_ADDRESS + 0x004))) //enable external interrupts from 32 to 63

#define NVIC_ICER0  (*((volatile u32*)(NVIC_OFFSET_ADDRESS + 0x080))) //disable external interrupts from 0 to 31
#define NVIC_ICER1  (*((volatile u32*)(NVIC_OFFSET_ADDRESS + 0x084))) //disable external interrupts from 32 to 63

#define NVIC_ISPR0  (*((volatile u32*)(NVIC_OFFSET_ADDRESS + 0x100))) //set pending flag from 0 to 31
#define NVIC_ISPR1  (*((volatile u32*)(NVIC_OFFSET_ADDRESS + 0x104))) //set pending flag from 32 to 63

#define NVIC_ICPR0  (*((volatile u32*)(NVIC_OFFSET_ADDRESS + 0x180))) //clear pending flag from 0 to 31
#define NVIC_ICPR1  (*((volatile u32*)(NVIC_OFFSET_ADDRESS + 0x184))) //clear pending flag from 32 to 63

#define NVIC_IABR0  (*((volatile u32*)(NVIC_OFFSET_ADDRESS + 0x200))) //to read the active flag from 0 to 31
#define NVIC_IABR1  (*((volatile u32*)(NVIC_OFFSET_ADDRESS + 0x204))) //to read the active flag  from 32 to 63

#define NVIC_IPR    ((volatile u8*)(NVIC_OFFSET_ADDRESS + 0x300)) 
 /* we cast it as (u8*) pointer  
 because its byte accessable so we can access it byte by byte 
 example: NVIC_IPR[0] , NVIC_IPR[1],..... 
 note1: each interrupt uses only 4 MSB  in each byte 
 note2: we didn't dereference it because we want to use it as pointer to array  
*/

/*---------------------------------------------------------------------------------------------------*/
/*SCB base address 0xE000E100*/
#define SCB_OFFSET_ADDRESS 0xE000ED00

#define SCB_AIRCR  (*((volatile u32*)(SCB_OFFSET_ADDRESS + 0x0C))) // by using this register we will spicify the priority group for each interrupt


/*Group Types*/
#define NVIC_GROUP_4_SUB_0 0x05FA0300 //4 bits for group and 0 bit for sub
#define NVIC_GROUP_3_SUB_1 0x05FA0400 //3 bits for group and 1 bit for sub
#define NVIC_GROUP_2_SUB_2 0x05FA0500 //2 bits for group and 2 bit for sub
#define NVIC_GROUP_1_SUB_3 0x05FA0600 //1 bits for group and 3 bit for sub
#define NVIC_GROUP_0_SUB_4 0x05FA0700 //0 bits for group and 4 bit for sub

#endif