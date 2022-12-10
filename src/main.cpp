#include <Arduino.h>
#include <TFT_eSPI.h> 
#include "BleKeyboard.h"
#include <ESP32Encoder.h>
#include <lvgl.h>
#include "display.h"
#include "ui.h"
#include "HAL/HAL.h"
#include "HAL_Button.h"
 
// ESP32Encoder encoder;
// Display screen;
// BleKeyboard blekeyboard;
// int lastEncoderValue = 0;

TaskHandle_t handleTaskLvgl;
TaskHandle_t handleTaskMadio;
void TaskLvglUpdate(void* parameter);
void TaskMadioControl(void* parameter);

void setup() {
  // put your setup code here, to run once:
    Key_Init();  
    Display_Init();                                                  
    // screen.init();                //TFT初始化  缓冲区初始化
    // screen.setBackLight(0.5);     //设置背光                
    ui_init();
    xTaskCreate(
        TaskLvglUpdate,
        "LvglThread",
        20000,
        nullptr,
        3,
        &handleTaskLvgl);

     xTaskCreate(
        TaskMadioControl,
        "MadioThread",
        2048,
        nullptr,
        4,
        &handleTaskMadio);

}

void loop() {
    delay(5);
      
}

void TaskLvglUpdate(void* parameter)
{
    for (;;)
    {
        lv_task_handler();
        delay(5);
    }
}

void TaskMadioControl(void* parameter)
{
  for(;;)
  {
    KeyBoard();
    delay(5);
  }
}
