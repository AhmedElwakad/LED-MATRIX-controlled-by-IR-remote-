/**
 * Author:Ahmed Elwakad
 * date:27/8/2024
 * version:1.0
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"
#include "LEDMAT_interface.h"
#include "IR_COMM_interface.h"
#include "IR_COMM_config.h"
#include "IR_COMM_private.h"

#define NULL ((void *)0)

static void (*IR_CALLBACK[17])(void);
static u8 global_u8ButtonNumber;

void HIR_COMM_voidInit(){

	    MGPIO_voidSetPinDirection(GPIOA,PIN0,INPUT_PULLUP_PULLDOWN);
	    MGPIO_voidSetPinValue(GPIOA,PIN0,GPIO_HIGH);

	    MAFIO_voidSetEXTIConfiguration(AFIO_EXTI_LINE0,AFIO_EXTI_GPIOA);
	    MEXTI_voidSetSignalLatch(EXTI_LINE0,EXTI_FALLING);
	    MEXTI_voidSetCallBack(getFrame,0);//setting callback function
	    MNVIC_voidEnableInterrupt(6);//enable EXTI0 interrupt

	    MSTK_voidInit(); //enable systick AHB/8 = 1MHZ

	    /*setting all call back function to make no function
	     * this will make sure there wont be any error while useing the remote
	     * */
	    setcallbacktoNoFunction(NoFunction);

}

void HIR_COMM_voidSetButtonFunction(void (*copy_ptr)(void),IR_BUTTON_t copy_ButtonType){
    //saving function number
	global_u8ButtonNumber = copy_ButtonType;

    //setting the functionality of a button
	IR_CALLBACK[copy_ButtonType]=copy_ptr;
}



static volatile  u8 u8StartFlag=0;
static volatile  u32 u32FrameData[50]={0};
static volatile  u8 u8EdgeCounter =0;
volatile  u8 u8Data=0;
extern u8 global_u8DisableScroll;

static void getFrame(){
	if(u8StartFlag ==0){

		/*
		 * we sensed the starting bit
		 * now wait for the next falling edge (which is the beginning of the data)
		 */
		MSTK_voidSetIntervalSingle(100000,takeAction);
		//setting the flag makes it unable to enter here again until getting the frame
		u8StartFlag=1;
	}
	else{
	//get the elapsed time between two falling edge so that we can know if its 1 or 0
     u32FrameData[u8EdgeCounter]=MSTK_u32GetElapsedTime();
     // wait for the next falling edge
     MSTK_voidSetIntervalSingle(100000,takeAction);
     //increase the counter to be able to get the elapsed time of the next bit
     u8EdgeCounter++;

	}


}

static void takeAction(){
	/*
	 * we entered this function because there's no
	 * other data to send (no falling edge received)
	 * */
	s16 i;
	u8Data=0;
 // now we begin to extract the data from the array of elapsed time
    if(u32FrameData[0]>=10000 && u32FrameData[17+i] <=14000){
	for(i=0;i<8;i++){
		if(u32FrameData[17+i]>=2000 && u32FrameData[17+i] <=2300){//indicating its 1
			SET_BIT(u8Data,i);
		}
		else{//indicating its 0
			CLR_BIT(u8Data,i);
		}
	}
    }
    else{
    	/*invalid frame*/
    }
    //we will execute the function of the corresponding button based on the data received
    //voidplay();

    if(u8Data==71 ) {
    	global_u8DisableScroll=0;
    }




    u8StartFlag =0;//reset it to be able to sense the stating bit again
    u32FrameData[0]=0;//to make it unable to process the data in it
    u8EdgeCounter =0; //reset the counter

}

static void voidplay(){
switch(u8Data){
/*button 1    */   case 69:     IR_CALLBACK[0] (); break;
/*button 2    */   case 70:     IR_CALLBACK[1] (); break;
/*button 3    */   case 71:     IR_CALLBACK[2] (); break;
/*button 4    */   case 68:     IR_CALLBACK[3] (); break;
/*button 5    */   case 64:     IR_CALLBACK[4] (); break;
/*button 6    */   case 67:     IR_CALLBACK[5] (); break;
/*button 7    */   case 7 :     IR_CALLBACK[6] (); break;
/*button 8    */   case 21:     IR_CALLBACK[7] (); break;
/*button 9    */   case 9 :     IR_CALLBACK[8] (); break;
/*button 0    */   case 25:     IR_CALLBACK[9] ();  break;
/*button *    */   case 22:     IR_CALLBACK[10]();  break;
/*button #    */   case 13:     IR_CALLBACK[11]();  break;
/*button up   */   case 24:     IR_CALLBACK[12]();  break;
/*button down */   case 82:     IR_CALLBACK[13]();  break;
/*button left */   case 8 :     IR_CALLBACK[14]();  break;
/*button right*/   case 90:     IR_CALLBACK[15]();  break;
/*button ok   */   case 28:     IR_CALLBACK[16]();  break;
                   default:                         break;
}
}

static void NoFunction(){
	asm("NOP");
}
static void setcallbacktoNoFunction(void (*copy_ptr)(void)){
	 for(u8 i=0;i<17;i++){
		    	IR_CALLBACK[i]=copy_ptr;
		    }
}
