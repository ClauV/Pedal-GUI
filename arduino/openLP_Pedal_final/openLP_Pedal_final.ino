/*
  
OpenLP Pedal arduino code
- when button pressed write UP
*/

#include "Button2.h";

#define PEDAL_PIN 2

#define LONG_CLICK_TIME 1500
#define DOUBLE_CLICK_TIME 400

Button2 button = Button2(PEDAL_PIN);

typedef struct {
uint32_t clickNo;
uint32_t doubleClickNo;
} buttonStat;

String received;

static buttonStat statistics = {0,0};

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
  
    if (time > 15000) {
        statistics.clickNo = 0;
        statistics.doubleClickNo = 0;       
    }
}

void clickHandler(Button2& btn) {
    Serial.println("UP");
    statistics.clickNo++;
    
}

void doubleClickHandler(Button2& btn) {
    Serial.println("DOWN");
    statistics.doubleClickNo++;
}

void getCommand() {
  Serial.print("STAT:(No of clicks=|");
  Serial.print(statistics.clickNo);
  Serial.print("|;No of double clicks=|");
  Serial.print(statistics.doubleClickNo);
  Serial.print("|)");
  Serial.println("");
}
void loop() {
   button.loop();
   //received = Serial.readString();
   if (Serial.available()) {
      received = Serial.readString();
      Serial.println(received);
      if (received.indexOf("GET") != -1) {
        Serial.println("GET command");
        getCommand();
      }
   }
   //delay();
  
}
