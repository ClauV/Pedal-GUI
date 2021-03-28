/*
  
OpenLP Pedal arduino code
- when button pressed write UP
*/

#define PEDAL_PIN 2
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
    Serial.println("ÜP");
    pedal = 0;
  }
  delay(1);
  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  //if (sensorVal == HIGH) {
   //digitalWrite(13, HIGH);
  // digitalWrite(13, LOW);

   
}
