#ifndef DISPLAY_H
#define DISPLAY_H

#include <lvgl.h>
#include "HAL_Button.h"

#define LCD_BL_PIN 12
#define LCD_BL_PWM_CHANNEL 1


class Display
{
private:


public:
	void init();
	void routine();
	void setBackLight(float);
};

void Display_Init();
void Power_Shutdown();

#endif