#include <HID-Project.h>
#include <HID-Settings.h>

int prevPin = 7;
int playPausePin = 2;
int nextPin = 3;
int mutePin = 10;

void setup() {

  pinMode(prevPin, INPUT);
  pinMode(playPausePin, INPUT);
  pinMode(nextPin, INPUT);
  pinMode(mutePin, INPUT);

  digitalWrite(prevPin, HIGH);
  digitalWrite(playPausePin, HIGH);
  digitalWrite(nextPin, HIGH);
  digitalWrite(mutePin, HIGH);

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
}
