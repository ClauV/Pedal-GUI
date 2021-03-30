/*
  
OpenLP Pedal arduino code
- when button pressed write UP
*/

#include "Button2.h";

#define PEDAL_PIN 2
#define CLICK_TIME 10 //ms

Button2 button = Button2(PEDAL_PIN);

void setup() {
  //start serial connection
  Serial.begin(9600);
  
  button.setLongClickTime(1000);
  button.setDoubleClickTime(400);
  
  button.setClickHandler(click);
  button.setDoubleClickHandler(doubleClick);
  
  pinMode(PEDAL_PIN, INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void click(Button2& btn) {
    Serial.println("UP");
}

void doubleClick(Button2& btn) {
    Serial.println("DOWN");
}

void loop() {
 
   button.loop();
   //delay();
  

}
