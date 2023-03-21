#include "TimerOne.h"

int ledPins[] = {3, 4, 5, 6, 7};
int state = 2;
int coldButton = 0;
int hotButton = 1;
int cold = 10;
int heat = 9;
bool state_changed = true;


// the setup function runs once when you press reset or power the board
void setup() {
  for (int i=0; i<5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(coldButton, INPUT_PULLUP);
  pinMode(hotButton, INPUT_PULLUP);
  pinMode(cold, OUTPUT);
  pinMode(heat, OUTPUT);
  Timer1.initialize(500000);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(coldButton) == LOW) {
    state_changed = true;
    state -= 1;
    while (digitalRead(coldButton) == LOW) {delay(100);}
  }
  if (digitalRead(hotButton) == LOW) {
    state_changed = true;
    state += 1;
    while (digitalRead(hotButton) == LOW) {delay(100);}
  }
  if (state_changed) {
    state %= 5;
    state_changed = false;
    for (int i=0; i<5; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    digitalWrite(ledPins[state], HIGH);
    if (state == 0) {
      Timer1.pwm(heat, 1024);
      Timer1.pwm(cold, 0);
    }
    if (state == 1) {
      Timer1.pwm(heat, 512);
      Timer1.pwm(cold, 0);
    }
    if (state == 2) {
      Timer1.pwm(heat, 0);
      Timer1.pwm(cold, 0);
    }
    if (state == 3) {
      Timer1.pwm(heat, 0);
      Timer1.pwm(cold, 512);
    }
    if (state == 4) {
      Timer1.pwm(heat, 0);
      Timer1.pwm(cold, 1024);
    }
  }
  delay(10);
}
