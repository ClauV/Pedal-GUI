/*
  
OpenLP Pedal arduino code
- when button pressed write UP
*/

#include "Button2.h";

#define PEDAL_PIN 2

#define LONG_CLICK_TIME 1500
#define DOUBLE_CLICK_TIME 400

Button2 button = Button2(PEDAL_PIN);

uint32_t clickNo = 0;
uint32_t doubleClickNo = 0;
String received;

void setup() {
  //start serial connection
  Serial.begin(9600);
  
  button.setLongClickTime(LONG_CLICK_TIME);
  button.setDoubleClickTime(DOUBLE_CLICK_TIME);
  
  button.setClickHandler(clickHandler);
  button.setDoubleClickHandler(doubleClickHandler);
  button.setLongClickHandler(longpressHandler);
  
  pinMode(PEDAL_PIN, INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void longpressHandler(Button2& btn) {
    unsigned int time = btn.wasPressedFor();
    Serial.print("You clicked ");
    if (time > 1500) {
        Serial.print("a really really long time.");
    } else if (time > 1000) {
        Serial.print("a really long time.");
    } else if (time > 500) {
        Serial.print("a long time.");        
    } else {
        Serial.print("long.");        
    }
    Serial.print(" (");        
    Serial.print(time);        
    Serial.println(" ms)");
}

void clickHandler(Button2& btn) {
    Serial.println("UP");
}

void doubleClickHandler(Button2& btn) {
    Serial.println("DOWN");
}

void loop() {
   button.loop();
   //received = Serial.readString();
 
   if (received.indexOf("GET") != -1)
      Serial.println("GET command");
   
   //delay();
  
}
