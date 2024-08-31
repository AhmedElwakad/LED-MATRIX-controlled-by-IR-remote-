/*
Author: Ahmed Elwakad
version: 1.0
date:12/8/2024
*/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

typedef struct{
volatile u32 EVCR;
volatile u32 MAPR;
volatile u32 EXTICR[4];
volatile u32 MAPR2;

}AFIO_t;

/*AFIO base address 0x40010000*/
#define AFIO_OFFSET_ADDRESS 0x40010000
#define AFIO   ((volatile AFIO_t*)AFIO_OFFSET_ADDRESS)

#endif