/*
  
OpenLP Pedal arduino code
- when button pressed write UP
*/

#define PEDAL_PIN 2
#define DELAY 350

volatile int pedal = 0;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(PEDAL_PIN, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(PEDAL_PIN), pedalPress_ISR, FALLING); // trigger when button pressed, but not when released.

}

void pedalPress_ISR() {
  pedal = 1;
}

void loop() {


  if (pedal == 1) {
    Serial.println("UP");
    digitalWrite(13, HIGH);
    delay(DELAY);
    digitalWrite(13, LOW);
    
    pedal = 0;
  }
  delay(1);


   
}
