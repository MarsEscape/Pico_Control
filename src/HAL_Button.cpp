#include "HAL_Button.h"

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
void clickEC11();
void doubleclickEC11();
void longPressStartEC11();
void longPressEC11();
void longPressStopEC11();


OneButton button1(KEY1_PIN, true);
OneButton button2(KEY2_PIN, true);
OneButton button3(KEY3_PIN, true);
OneButton buttonEC11(EC11_KEY_PIN, true);

void Key_Init(void)
{
    pinMode(CONFIG_POWER_EN_PIN,OUTPUT); 
    digitalWrite(CONFIG_POWER_EN_PIN,LOW);   
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

  buttonEC11.attachClick(clickEC11);
  buttonEC11.attachDoubleClick(doubleclickEC11);
  buttonEC11.attachLongPressStart(longPressStartEC11);
  buttonEC11.attachLongPressStop(longPressStopEC11);
  buttonEC11.attachDuringLongPress(longPressEC11); 
}

void KeyBoard(void)
{
    button1.tick();
    button2.tick();
    button3.tick();
    buttonEC11.tick();

    if (lastEncoderValue != encoder.getCount())
    {
        int now_count = encoder.getCount();
        if(blekeyboard.isConnected())
        {
            if (now_count > lastEncoderValue)
             {
             blekeyboard.write(KEY_MEDIA_VOLUME_DOWN);
            }
             else
            {
             blekeyboard.write(KEY_MEDIA_VOLUME_UP);
             lv_slider_set_value(ui_Slider1,10,LV_ANIM_ON);
            }
            }
        lastEncoderValue = now_count;
    }
    
}

void click1() {
  blekeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
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
  blekeyboard.write(KEY_MEDIA_NEXT_TRACK);
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
  blekeyboard.write(KEY_MEDIA_PLAY_PAUSE);
} 

void doubleclick3() {
  

} 

void longPressStart3() {

} 


void longPress3() {

} 


void longPressStop3() {
  Serial.println("Button 1 longPress stop");
} 

void clickEC11() {
  blekeyboard.write(KEY_MEDIA_MUTE);
} 

void doubleclickEC11() {
  
  Serial.println("Button 1 doubleclick.");
} 

void longPressStartEC11() {
    Power_Shutdown();
  Serial.println("Button 1 longPress start");
} 


void longPressEC11() {
  // Power_Shutdown();
  Serial.println("Button 1 longPress...");
} 


void longPressStopEC11() {
  Serial.println("Button 1 longPress stop");
} 