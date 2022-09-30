#include <Arduino.h>
// I, William Ohia, 000791775, I acknowledge that this is my own work and 
// no other person's work has been copied without acknowledgement. 
// button states
#define BTN_UP  1
#define BTN_DOWN  0

// levels
#define Up 1
#define DOWN 0


bool pButtonState = false;
int btnState = BTN_UP;

void setup() {
  // put your setup code here, to run once:
   // configure the USB serial monitor
 Serial.begin(115200);

  // configure pin D4 as a digital output - this is the LED
 pinMode(D4, OUTPUT);

  // configure pin D5 as digital input - this is the pushbutton
 pinMode(D5, INPUT_PULLUP);

// set default PWM range
 analogWriteRange(1023);
}

void loop() {
  // put your main code here, to run repeatedly:
  int iVal;
   //double val;
   //int pushButton; 
   if(digitalRead(D5) == DOWN){
    if(btnState == BTN_UP){
      btnState = BTN_DOWN;
      pButtonState = !pButtonState;
    }
   } else {
    btnState = BTN_UP;
   }

   if(pButtonState == false){
    analogWrite(D4, 1023);
   } else {
    iVal = analogRead(A0);
    analogWrite(D4, iVal);
   }

   delay(1);

 
}