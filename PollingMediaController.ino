/*
 * This sketch uses HID library by NicoHood https://github.com/NicoHood/HID
 * 
 * Author Erkki Halinen 2018
 * 
 * Simple sketch that polls for button presses and 
 * sends a media key press
 * when a button is pressed.
 */
#include <HID-Project.h>
#include <HID-Settings.h>

/* 
 *  You can modify these pinouts to suit your board layout
 */

// Pro Micro pinout 
int prevPin = 2;
int playPausePin = 4;
int nextPin = 9;

int volDownPin = 21;
int volUpPin = 10;
int mutePin = 18;

void setup() {

  pinMode(prevPin, INPUT);
  pinMode(playPausePin, INPUT);
  pinMode(nextPin, INPUT);
  
  pinMode(mutePin, INPUT);
  pinMode(volDownPin, INPUT);
  pinMode(volUpPin, INPUT);

  digitalWrite(prevPin, HIGH);
  digitalWrite(playPausePin, HIGH);
  digitalWrite(nextPin, HIGH);
  
  digitalWrite(mutePin, HIGH);
  digitalWrite(volUpPin, HIGH);
  digitalWrite(volDownPin, HIGH);

  Consumer.begin();

}

void loop() {

  if(digitalRead(prevPin) == 0) {

      Consumer.write(MEDIA_PREVIOUS);
      delay(150);
    }
  if(digitalRead(playPausePin) == 0) {

      Consumer.write(MEDIA_PLAY_PAUSE);
      delay(150);
    }

  if(digitalRead(nextPin) == 0) {

      Consumer.write(MEDIA_NEXT);
      delay(150);
    }

  if(digitalRead(mutePin) == 0) {

      Consumer.write(MEDIA_VOLUME_MUTE);
      delay(200);
    }
    
  if(digitalRead(volUpPin) == 0) {

      Consumer.write(MEDIA_VOLUME_UP);
      delay(200);
    }
    
  if(digitalRead(volDownPin) == 0) {

      Consumer.write(MEDIA_VOLUME_DOWN);
      delay(200);
    }
}
