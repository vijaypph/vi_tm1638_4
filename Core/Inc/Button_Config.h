/*
 * Button_Config.h
 *
 *  Created on: Dec 19, 2023
 *      Author: Lenovo
 */


#ifndef INC_BUTTON_CONFIG_H_
#define INC_BUTTON_CONFIG_H_
#define R_F 1
#define DECREMENT 2
#define START_STOP 4
#define INCREMENT 8
#define ULTRA_SELECT 16
#define MOTOR_SELECT 32
#define BLANK 64

void bar_led_status(void);
void UltraSelect(void);
void MotorSelect(void);
void StartMachine(void);
void ReverseForward(void);
#endif /* INC_BUTTON_CONFIG_H_ */
