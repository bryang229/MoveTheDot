#include "LedControl.h"
const int SW_pin = 3;
const int X_pin = 0;
const int Y_pin = 1;
const int joyStick5V = 6;

LedControl lc = LedControl(12, 10, 11, 1);

void setup() {
  pinMode(joyStick5V, OUTPUT);
  pinMode(SW_pin, INPUT);
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
  digitalWrite(joyStick5V, HIGH);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

  int row = 5;
  int column = 4;
void screen() {
  byte positions[9] = {
    B00000000,
    B10000000,
    B01000000,
    B00100000,
    B00010000,
    B00001000,
    B00000100,
    B00000010,
    B00000001
  };
  lc.clearDisplay(0);
  lc.setRow(0,row,positions[column]);
  row = newRow();
  column = newColumn();
  Serial.println(analogRead(Y_pin));
  Serial.println(analogRead(X_pin));
  
}

int newRow() {
  if (analogRead(Y_pin) >= 0 && analogRead(Y_pin) <= 128) {
    return 0;
  }
  else if (analogRead(Y_pin) >= 129 && analogRead(Y_pin) <= 256) {
    return 1;
  }
  else if (analogRead(Y_pin) >= 257 && analogRead(Y_pin) <= 384) {
    return 2;
  }
  else if (analogRead(Y_pin) >= 385 && analogRead(Y_pin) <= 512) {
    return 3;
  }
  else if (analogRead(Y_pin) >= 513 && analogRead(Y_pin) <= 639) {
    return 4;
  }
  else if (analogRead(Y_pin) >= 640 && analogRead(Y_pin) <= 767) {
    return 5;
  }
  else if (analogRead(Y_pin) >= 768 && analogRead(Y_pin) <= 895) {
    return 6;
  }
  else if (analogRead(Y_pin) >= 896 && analogRead(Y_pin) <= 1023) {
    return 7;
  }
  return 5;

}
int newColumn() {
    if (analogRead(X_pin) >= 0 && analogRead(X_pin) <= 128) {
    return 1;
  }
  else if (analogRead(X_pin) >= 129 && analogRead(X_pin) <= 256) {
    return 2;
  }
  else if (analogRead(X_pin) >= 257 && analogRead(X_pin) <= 384) {
    return 3;
  }
  else if (analogRead(X_pin) >= 385 && analogRead(X_pin) <= 512) {
    return 4;
  }
  else if (analogRead(X_pin) >= 513 && analogRead(X_pin) <= 639) {
    return 5;
  }
  else if (analogRead(X_pin) >= 640 && analogRead(X_pin) <= 767) {
    return 6;
  }
  else if (analogRead(X_pin) >= 768 && analogRead(X_pin) <= 895) {
    return 7;
  }
  else if (analogRead(X_pin) >= 896 && analogRead(X_pin) <= 1023) {
    return 8;
  }
  return 5;
}

void loop() {
  screen();
}
