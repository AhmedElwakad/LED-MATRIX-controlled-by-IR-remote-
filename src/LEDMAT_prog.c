/*
Author:Ahmed Elwakad
date:22/8/2024
version :1.0

*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "LEDMAT_interface.h"
#include "LEDMAT_private.h"
#include "LEDMAT_config.h"



void HLEDMAT_voidInit(){
    //initiating the rows to be output
MGPIO_voidSetPinDirection(LEDMAT_ROW0_PIN,OUTPUT_SPEED_2MHZ_PP);
MGPIO_voidSetPinDirection(LEDMAT_ROW1_PIN,OUTPUT_SPEED_2MHZ_PP);
MGPIO_voidSetPinDirection(LEDMAT_ROW2_PIN,OUTPUT_SPEED_2MHZ_PP);
MGPIO_voidSetPinDirection(LEDMAT_ROW3_PIN,OUTPUT_SPEED_2MHZ_PP);
MGPIO_voidSetPinDirection(LEDMAT_ROW4_PIN,OUTPUT_SPEED_2MHZ_PP);
MGPIO_voidSetPinDirection(LEDMAT_ROW5_PIN,OUTPUT_SPEED_2MHZ_PP);
MGPIO_voidSetPinDirection(LEDMAT_ROW6_PIN,OUTPUT_SPEED_2MHZ_PP);
MGPIO_voidSetPinDirection(LEDMAT_ROW7_PIN,OUTPUT_SPEED_2MHZ_PP);
 //initiating the columns to be output
MGPIO_voidSetPinDirection(LEDMAT_COL0_PIN,OUTPUT_SPEED_2MHZ_PP);
MGPIO_voidSetPinDirection(LEDMAT_COL1_PIN,OUTPUT_SPEED_2MHZ_PP);
MGPIO_voidSetPinDirection(LEDMAT_COL2_PIN,OUTPUT_SPEED_2MHZ_PP);
MGPIO_voidSetPinDirection(LEDMAT_COL3_PIN,OUTPUT_SPEED_2MHZ_PP);
MGPIO_voidSetPinDirection(LEDMAT_COL4_PIN,OUTPUT_SPEED_2MHZ_PP);
MGPIO_voidSetPinDirection(LEDMAT_COL5_PIN,OUTPUT_SPEED_2MHZ_PP);
MGPIO_voidSetPinDirection(LEDMAT_COL6_PIN,OUTPUT_SPEED_2MHZ_PP);
MGPIO_voidSetPinDirection(LEDMAT_COL7_PIN,OUTPUT_SPEED_2MHZ_PP);
}

void HLEDMAT_voidDisplay(u8 *copy_u8Data){


//enable column 0
disableAllColumns();
setRowValues(copy_u8Data[0]);
MGPIO_voidSetPinValue(LEDMAT_COL0_PIN,GPIO_LOW);
delay_us(2500); //delay for 2.5ms

//enable column 1
disableAllColumns();
setRowValues(copy_u8Data[1]);
MGPIO_voidSetPinValue(LEDMAT_COL1_PIN,GPIO_LOW);
delay_us(2500); //delay for 2.5ms

//enable column 2
disableAllColumns();
setRowValues(copy_u8Data[2]);
MGPIO_voidSetPinValue(LEDMAT_COL2_PIN,GPIO_LOW);
delay_us(2500); //delay for 2.5ms

//enable column 3
disableAllColumns();
setRowValues(copy_u8Data[3]);
MGPIO_voidSetPinValue(LEDMAT_COL3_PIN,GPIO_LOW);
delay_us(2500); //delay for 2.5ms

//enable column 4
disableAllColumns();
setRowValues(copy_u8Data[4]);
MGPIO_voidSetPinValue(LEDMAT_COL4_PIN,GPIO_LOW);
delay_us(2500); //delay for 2.5ms

//enable column 5
disableAllColumns();
setRowValues(copy_u8Data[5]);
MGPIO_voidSetPinValue(LEDMAT_COL5_PIN,GPIO_LOW);
delay_us(2500); //delay for 2.5ms

//enable column 6
disableAllColumns();
setRowValues(copy_u8Data[6]);
MGPIO_voidSetPinValue(LEDMAT_COL6_PIN,GPIO_LOW);
delay_us(2500); //delay for 2.5ms

//enable column 7
disableAllColumns();
setRowValues(copy_u8Data[7]);
MGPIO_voidSetPinValue(LEDMAT_COL7_PIN,GPIO_LOW);
delay_us(2500); //delay for 2.5ms


}

static void  disableAllColumns(){

/*disable all columns */
MGPIO_voidSetPinValue(LEDMAT_COL0_PIN,GPIO_HIGH);
MGPIO_voidSetPinValue(LEDMAT_COL1_PIN,GPIO_HIGH);
MGPIO_voidSetPinValue(LEDMAT_COL2_PIN,GPIO_HIGH);
MGPIO_voidSetPinValue(LEDMAT_COL3_PIN,GPIO_HIGH);
MGPIO_voidSetPinValue(LEDMAT_COL4_PIN,GPIO_HIGH);
MGPIO_voidSetPinValue(LEDMAT_COL5_PIN,GPIO_HIGH);
MGPIO_voidSetPinValue(LEDMAT_COL6_PIN,GPIO_HIGH);
MGPIO_voidSetPinValue(LEDMAT_COL7_PIN,GPIO_HIGH);

}

static void setRowValues(u8 copy_u8Value){
u8 local_u8Bit;

//getting the data of the first bit of the first row 
local_u8Bit =GET_BIT(copy_u8Value,0);
//diplay the data 
MGPIO_voidSetPinValue(LEDMAT_ROW0_PIN,local_u8Bit);

local_u8Bit =GET_BIT(copy_u8Value,1);
MGPIO_voidSetPinValue(LEDMAT_ROW1_PIN,local_u8Bit);

local_u8Bit =GET_BIT(copy_u8Value,2);
MGPIO_voidSetPinValue(LEDMAT_ROW2_PIN,local_u8Bit);

local_u8Bit =GET_BIT(copy_u8Value,3);
MGPIO_voidSetPinValue(LEDMAT_ROW3_PIN,local_u8Bit);

local_u8Bit =GET_BIT(copy_u8Value,4);
MGPIO_voidSetPinValue(LEDMAT_ROW4_PIN,local_u8Bit);

local_u8Bit =GET_BIT(copy_u8Value,5);
MGPIO_voidSetPinValue(LEDMAT_ROW5_PIN,local_u8Bit);

local_u8Bit =GET_BIT(copy_u8Value,6);
MGPIO_voidSetPinValue(LEDMAT_ROW6_PIN,local_u8Bit);

local_u8Bit =GET_BIT(copy_u8Value,7);
MGPIO_voidSetPinValue(LEDMAT_ROW7_PIN,local_u8Bit);

}

u8 global_u8DisableScroll=1;
void HLEDMAT_voidScrollText(u8 *text[], u16 textLength, u32 scrollDelay) {
    s16 i, j;
    u8 displayBuffer[8] = {0};

    for (i = 0; i < textLength * 8; i++) {
    	if(global_u8DisableScroll){ //check whether to scroll or not
        for (j = 0; j < 8; j++) {
            // Shift the letters
            displayBuffer[j] = (i < 8) ? 0 : text[(i / 8) - 1][j] << (i % 8);
            displayBuffer[j] |= text[i / 8][j] >> (8 - (i % 8));
        }

        // Display the shifted letter
        HLEDMAT_voidDisplay(displayBuffer);
        delay_us(scrollDelay);

    }

    else{
    	break;
    }
    }

}

 void  HLEDMAT_voidDisableAllColumnsandrows(){
	 MGPIO_voidSetPinValue(LEDMAT_ROW0_PIN,GPIO_LOW);
	 MGPIO_voidSetPinValue(LEDMAT_ROW1_PIN,GPIO_LOW);
	 MGPIO_voidSetPinValue(LEDMAT_ROW2_PIN,GPIO_LOW);
	 MGPIO_voidSetPinValue(LEDMAT_ROW3_PIN,GPIO_LOW);
	 MGPIO_voidSetPinValue(LEDMAT_ROW4_PIN,GPIO_LOW);
	 MGPIO_voidSetPinValue(LEDMAT_ROW5_PIN,GPIO_LOW);
	 MGPIO_voidSetPinValue(LEDMAT_ROW6_PIN,GPIO_LOW);
	 MGPIO_voidSetPinValue(LEDMAT_ROW7_PIN,GPIO_LOW);
/*disable all columns */
MGPIO_voidSetPinValue(LEDMAT_COL0_PIN,GPIO_HIGH);
MGPIO_voidSetPinValue(LEDMAT_COL1_PIN,GPIO_HIGH);
MGPIO_voidSetPinValue(LEDMAT_COL2_PIN,GPIO_HIGH);
MGPIO_voidSetPinValue(LEDMAT_COL3_PIN,GPIO_HIGH);
MGPIO_voidSetPinValue(LEDMAT_COL4_PIN,GPIO_HIGH);
MGPIO_voidSetPinValue(LEDMAT_COL5_PIN,GPIO_HIGH);
MGPIO_voidSetPinValue(LEDMAT_COL6_PIN,GPIO_HIGH);
MGPIO_voidSetPinValue(LEDMAT_COL7_PIN,GPIO_HIGH);

}
