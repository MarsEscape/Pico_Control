#ifndef _HAL_BUTTON_H
#define _HAL_BUTTON_H
#include "Arduino.h"
#include "BleKeyboard.h"
#include <ESP32Encoder.h>
#include "ui.h"
#include "ui_helpers.h"
#include "lvgl.h"
#include "ui.h"
#include "OneButton.h"
#include "display.h"

// #include "../../../lv_examples.h"

#define EC11_A_PIN 25
#define EC11_B_PIN 34
#define EC11_KEY_PIN 35
#define KEY1_PIN 5
#define KEY2_PIN 32
#define KEY3_PIN 33
#define CONFIG_POWER_EN_PIN 21



void KeyBoard(void);
void Key_Init(void);


#endif