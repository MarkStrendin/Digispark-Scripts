#include "DigiKeyboard.h"

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(1, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(1, HIGH);

  // Payload
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);

  // WIN+R
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);

  // Notepad
  DigiKeyboard.print("notepad.exe");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  // Message
  DigiKeyboard.print("This message was automatically typed by a USB device.");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print("It could have stolen your saved passwords, or deleted your files before you knew what was happening.");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print("In fact, it will start deleting your files in 30 seconds - if you don't remove it first.");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  for(int x = 30; x > 0; x--) {
    digitalWrite(1,HIGH);
    DigiKeyboard.print(x);
    DigiKeyboard.print(" ");
    delay(50);
    digitalWrite(1,LOW);
    delay(950);
  }  

  DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_N);

  DigiKeyboard.delay(500);
  
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);  
  DigiKeyboard.print("cmd /C dir /B /S %USERPROFILE%");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);  
  
  // Turn the LED on to indicate we're done
  digitalWrite(1,LOW);
  
  // Do nothing forever
  while(true) {    
    digitalWrite(1, HIGH);    
    delay(100);
    digitalWrite(1, LOW);
    delay(100);
  }
}
