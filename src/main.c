/*
 * main.c
 *
 *  Created on: Aug 28, 2024
 *      Author: Gaming
 */



/*
 * main.c
 *
 *  Created on: Aug 28, 2024
 *      Author: Ahmed Elwakad
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "SYSTICK_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"
#include "IR_COMM_interface.h"
#include "LEDMAT_interface.h"

// arrays for the data of the LED MATRIX
u8 A[8]={0, 56, 68, 68, 124, 68, 68, 0};
u8 H[8]={0, 68, 68, 68, 124, 68, 68, 0};
u8 M[8]={0, 68, 108, 84, 68, 68, 68, 0};
u8 E[8]={0, 124, 64, 64, 120, 64, 124, 0};
u8 O[8]={0, 56, 68, 68, 68, 68, 56, 0};
u8 I[8]={0, 124, 16, 16, 16, 16, 124, 0};
u8 S[8]={0, 60, 64, 64, 60, 4, 120, 0};
u8 R[8]={0, 56, 68, 68, 120, 80, 72, 0};
u8 D[8]={0, 112, 72, 68, 68, 72, 112, 0};

//some text to show
#define HOSSAM {H,O,S,S,A,M}
#define AHMED  {A,H,M,E,D}


// buttons data numbers
#define BUTTON_1    69
#define BUTTON_2    70
#define BUTTON_3    71
#define BUTTON_UP   24
#define BUTTON_DOWN 82


//this variable controls the speed of the scrolling text
volatile u32 speed=60000;

//variable to control the scrolling
extern u8 global_u8DisableScroll;

//variable to receive data from IR receiver
extern u8 u8Data;

//function to make buzzer sound when using the IR remote
void BuzzerSound(){
	MGPIO_voidSetPinValue(GPIOA,PIN9,GPIO_HIGH);
	delay_ms(15);
	MGPIO_voidSetPinValue(GPIOA,PIN9,GPIO_LOW);
	delay_us(1000);
}


void main(){
	 RCC_voidInitSysClock();
	 RCC_voidEnableClock(RCC_APB2,RCC_GPIOA); //initiate GPIOA
	 RCC_voidEnableClock(RCC_APB2,RCC_GPIOB); //initiate GPIOB
	 RCC_voidEnableClock(RCC_APB2,RCC_AFIO);  //initiate AFIO

	 // PA9  is output for buzzer
	 MGPIO_voidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_2MHZ_PP);

     HIR_COMM_voidInit();//initiate IR Communication

     HLEDMAT_voidInit(); //initiate led matrix

     //setting some text
     u8 *text1[]=HOSSAM;
     u8 *text2[]=AHMED;

     //variable to detect if new data came from IR receiver
     u8 prevData=200;

	while(1){

		if (prevData != u8Data  ){
			BuzzerSound();
			prevData=u8Data;

		}

		if(u8Data ==BUTTON_DOWN){
		               speed +=10000;
		               u8Data=0;
		               global_u8DisableScroll=1;
		         }
		else if(u8Data ==BUTTON_UP){
		           speed -=10000;
		           if (speed <20000){
		        	   speed=20000;
		           }
		           u8Data=0;
		           global_u8DisableScroll=1;
		         }
		else if(u8Data == BUTTON_1){

    	 HLEDMAT_voidScrollText(text1,6,speed);

      }
		else if(u8Data ==BUTTON_2){

    	 HLEDMAT_voidScrollText(text2,5,speed);

     }

		else if(u8Data ==BUTTON_3){

            u8Data=0;
            global_u8DisableScroll=1;
         }




	}
}



