/**
 * Author:Ahmed Elwakad
 * date:27/8/2024
 * version:1.0
 *
 */
#ifndef IR_COMM_PRIVATE_H
#define IR_COMM_PRIVATE_H


#define GPIOA 0
#define GPIOB 1
#define GPIOC 2

#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7
#define PIN8  8
#define PIN9  9
#define PIN10  10
#define PIN11  11
#define PIN12  12
#define PIN13  13
#define PIN14  14
#define PIN15  15



static void getFrame();
static void takeAction();
static void voidplay();
static void NoFunction();
static void setcallbacktoNoFunction(void (*copy_ptr)(void));


#endif
