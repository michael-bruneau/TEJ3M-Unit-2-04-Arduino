/*
  Created by: Michael Bruneau
  Created on: March 2025

  Sends power to RGB LED to create a color then pauses for one second and switches to the next colour
*/

// variables
int blinkDelay = 1000;
int voltage_output = 0;
int pin_select;
int for_loop_start = -1;
int total_loop_cycle = 2;
int counter = 0;

 // constants
 const int PIN_5 = 5;
 const int PIN_4 = 4;
 const int PIN_3 = 3;
 
  
// arrays
int voltage[] = {0, 5};
int pin[] = {PIN_5, PIN_3, PIN_4};

// setup
void setup()
{
  pinMode(PIN_5, OUTPUT);
  pinMode(PIN_4, OUTPUT);
  pinMode(PIN_3, OUTPUT);
}

// loops code
void loop() {
  for (int counter = 0; counter <= total_loop_cycle; counter++) {
    
    // turns off previous light
    if (for_loop_start > 0) {
    	digitalWrite(pin[for_loop_start - 1], LOW);
    }
    digitalWrite(pin[for_loop_start], HIGH);
    
    // Makes each loop one less than the last until it resets
    for_loop_start += 1;
      
  	for (int pin_select = for_loop_start; pin_select < 3; pin_select++) {
  		digitalWrite(pin[pin_select], HIGH);
  		delay(blinkDelay); // Wait for 1000 millisecond(s)
    	digitalWrite(pin[pin_select], LOW);
  	}
  }
  
  // reset
  counter = 0;
  for_loop_start = -1;
  pin_select = 0;
  
  // white light
  digitalWrite(PIN_5, HIGH);
  digitalWrite(PIN_3, HIGH);
  digitalWrite(PIN_4, HIGH);
  delay(blinkDelay); // Wait for 1000 millisecond(s)
  digitalWrite(PIN_5, LOW);
  digitalWrite(PIN_3, LOW);
  digitalWrite(PIN_4, LOW);
}
