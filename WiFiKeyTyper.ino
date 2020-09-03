#include "DigiKeyboard.h"

char WIFIKEY [] = "BIGLONGPASSWORDGOESHERE";

void setup() {
  // initialize the digital pin as an output.
  pinMode(1, OUTPUT);
}

void loop() {
  // Light the LED to indicate we're writing
  digitalWrite(1, HIGH);
  
  // Payload
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1000);

  // Type password
  for(int x = 0; x < strlen(WIFIKEY); x++) {
    DigiKeyboard.print(WIFIKEY[x]);
    DigiKeyboard.delay(500); 
  }  
  
  // Blink the LED to indicate that we're done
  digitalWrite(1,LOW);
  
  // Do nothing forever
  while(true) {
    digitalWrite(1, HIGH);
    delay(100);
    digitalWrite(1, LOW);
    delay(100);
  }
}
