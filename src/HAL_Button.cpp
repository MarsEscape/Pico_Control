#include "HAL_Button.h"


int BTN1_State,BTN2_State,BTN3_State,BTN4_State;
bool BTN1_State_flag=0,BTN2_State_flag=0,BTN3_State_flag=0,BTN4_State_flag=0;
BleKeyboard blekeyboard;

ESP32Encoder encoder;
int lastEncoderValue = 0;

void click1();
void doubleclick1();
void longPressStart1();
void longPress1();
void longPressStop1();
void click2();
void doubleclick2();
void longPressStart2();
void longPress2();
void longPressStop2();
void click3();
void doubleclick3();
void longPressStart3();
void longPress3();
void longPressStop3();


OneButton button1(KEY1_PIN, true);
OneButton button2(KEY2_PIN, true);
OneButton button3(KEY3_PIN, true);
// OneButton buttonEC11(EC11_KEY_PIN, true);

void Key_Init(void)
{
    pinMode(CONFIG_POWER_EN_PIN,OUTPUT);   
    digitalWrite(CONFIG_POWER_EN_PIN,HIGH); 
    blekeyboard.begin();
    ESP32Encoder::useInternalWeakPullResistors = UP;
    encoder.attachSingleEdge(EC11_A_PIN, EC11_B_PIN);


  button1.attachClick(click1);
  button1.attachDoubleClick(doubleclick1);
  button1.attachLongPressStart(longPressStart1);
  button1.attachLongPressStop(longPressStop1);
  button1.attachDuringLongPress(longPress1);

  button2.attachClick(click2);
  button2.attachDoubleClick(doubleclick2);
  button2.attachLongPressStart(longPressStart2);
  button2.attachLongPressStop(longPressStop2);
  button2.attachDuringLongPress(longPress2);

  button3.attachClick(click3);
  button3.attachDoubleClick(doubleclick3);
  button3.attachLongPressStart(longPressStart3);
  button3.attachLongPressStop(longPressStop3);
  button3.attachDuringLongPress(longPress3);
}

void KeyBoard(void)
{
    // digitalWrite(21,HIGH); 

    button1.tick();
    button2.tick();
    button3.tick();
    // delay(10);


    // if (lastEncoderValue != encoder.getCount())
    // {
    //     int now_count = encoder.getCount();
    //     if(blekeyboard.isConnected())
    //     {
    //         if (now_count > lastEncoderValue)
    //          {
    //          blekeyboard.write(KEY_MEDIA_VOLUME_DOWN);
    //         }
    //          else
    //         {
    //          blekeyboard.write(KEY_MEDIA_VOLUME_UP);
    //          lv_slider_set_value(ui_Slider1,10,LV_ANIM_ON);
    //         }
    //         }
    //     lastEncoderValue = now_count;
    // }
    
    //  BTN1_State = digitalRead(KEY1_PIN);
    //  BTN2_State = digitalRead(KEY2_PIN);
    //  BTN3_State = digitalRead(KEY3_PIN);
    //  BTN3_State = digitalRead(EC11_KEY_PIN);   
}

void click1() {

} 

void doubleclick1() {
  Serial.println("Button 1 doubleclick.");
} 

void longPressStart1() {
  Serial.println("Button 1 longPress start");
} 


void longPress1() {
  // screen.setBackLight(0.5);  
  // delay(100);
  // digitalWrite(21, LOW);
  Power_Shutdown();
  Serial.println("Button 1 longPress...");
} 


void longPressStop1() {
  
  Serial.println("Button 1 longPress stop");
} 


// ... and the same for button 2:

void click2() {
  blekeyboard.write(KEY_MEDIA_VOLUME_UP);
} // click2


void doubleclick2() {
  Serial.println("Button 2 doubleclick.");
} // doubleclick2


void longPressStart2() {
  Serial.println("Button 2 longPress start");
} // longPressStart2


void longPress2() {
  Serial.println("Button 2 longPress...");
} // longPress2

void longPressStop2() {
  Serial.println("Button 2 longPress stop");
} // longPressStop2

void click3() {
  blekeyboard.write(KEY_MEDIA_VOLUME_DOWN);
} 

void doubleclick3() {
  
  Serial.println("Button 1 doubleclick.");
} 

void longPressStart3() {
  Serial.println("Button 1 longPress start");
} 


void longPress3() {
  digitalWrite(21, LOW);
  Serial.println("Button 1 longPress...");
} 


void longPressStop3() {
  Serial.println("Button 1 longPress stop");
} 