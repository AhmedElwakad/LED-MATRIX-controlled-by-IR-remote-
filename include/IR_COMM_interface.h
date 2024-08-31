/**
 * Author:Ahmed Elwakad
 * date:27/8/2024
 * version:1.0
 *
 */
#ifndef IR_COMM_INTERFACE_H
#define IR_COMM_INTERFACE_H

typedef enum{
	IR_BUTTON_1,
	IR_BUTTON_2,
	IR_BUTTON_3,
	IR_BUTTON_4,
	IR_BUTTON_5,
	IR_BUTTON_6,
	IR_BUTTON_7,
	IR_BUTTON_8,
	IR_BUTTON_9,
	IR_BUTTON_0,
	IR_BUTTON_STAR,
	IR_BUTTON_HASHTAG,
	IR_BUTTON_UP,
	IR_BUTTON_DOWN,
	IR_BUTTON_LEFT,
	IR_BUTTON_RIGHT,
	IR_BUTTON_OK
}IR_BUTTON_t;

void HIR_COMM_voidInit();
void HIR_COMM_voidSetButtonFunction(void (*copy_ptr)(void),IR_BUTTON_t copy_ButtonType);

#endif
