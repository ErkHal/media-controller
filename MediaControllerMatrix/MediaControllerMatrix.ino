/*
 * Author ErkHal
 * https://github.com/ErkHal/
 * MediaControllerMatrix.ino
 * 
 * A small sketch used with my self-made mechanical media keypad.
 */
#include <Keypad.h>
#include "HID-Project.h"

const byte ROWS = 2;
const byte COLS = 3;

//Media keys
char hexaKeys[ROWS][COLS] = {
  {MEDIA_VOLUME_DOWN, MEDIA_VOLUME_MUTE, MEDIA_VOLUME_UP},
       {MEDIA_PREVIOUS, MEDIA_PLAY_PAUSE, MEDIA_NEXT},
};

/*
//Another configuration
char hexaKeys[ROWS][COLS] = {
  {KEYPAD_7, KEYPAD_8, KEYPAD_9},
  {KEYPAD_4, KEYPAD_5, KEYPAD_6},
};
*/

byte rowPins[ROWS] = {2, 3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {21, 20, 19}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
customKeypad.

void setup(){
  Consumer.begin();
}
  
void loop(){
  checkPressedKeys();
}

void checkPressedKeys() {
  byte customKey = customKeypad.getKey();
  if (customKey){
    Consumer.write(customKey);
    delay(500);
  }
}
