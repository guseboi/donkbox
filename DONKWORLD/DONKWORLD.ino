#include <TVout.h>
#include "fontALL.h"
#include "img.h"
#include "img2.h"
#include "img3.h"

const int buttonpin1 = 2;
const int buttonpin2 = 3;
const int buttonpin3 = 4;
const int buttonpin4 = 5;
const int buttonpin5 = 6;
const int ledpin = 13;

int buttonstate1 = 0;
int buttonstate2 = 0;
int buttonstate3 = 0;
int buttonstate4 = 0;
int buttonstate5 = 0;

TVout TV;

int zOff = 150;
int xOff = 0;
int yOff = 0;
int cSize = 50;
int view_plane = 64;
float angle = PI / 60;


void setup() {
  pinMode(buttonpin1, INPUT_PULLUP);
  pinMode(buttonpin2, INPUT_PULLUP);
  pinMode(buttonpin3, INPUT_PULLUP);
  pinMode(buttonpin4, INPUT_PULLUP);
  pinMode(buttonpin5, INPUT_PULLUP);
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, HIGH);

  TV.begin(PAL);
  TV.select_font(font8x8);
  TV.bitmap(0, 0, img);


}


void loop() {

  buttonstate1 = digitalRead(buttonpin1);
  buttonstate2 = digitalRead(buttonpin2);
  buttonstate3 = digitalRead(buttonpin3);
  buttonstate4 = digitalRead(buttonpin4);
  buttonstate5 = digitalRead(buttonpin5);

  if (buttonstate1 == LOW) {
    TV.clear_screen();
    delay(200);
    TV.bitmap(0, 0, img);
    delay(200);
    TV.bitmap(0, 40, img);
    delay(400);
  }

  if (buttonstate2 == LOW) {
    TV.println("FLASHBACK");
    delay(200);
    TV.println("RAVE");
    delay(200);
    TV.println("COMMITTEE");
    delay(200);
  }

  if (buttonstate3 == LOW) {
    TV.bitmap(0, 0, img2);
    delay(200);
    TV.bitmap(0, 0, img3);
    delay(200);
  }

  if (buttonstate4 == LOW) {
    TV.clear_screen();
    delay(40);
  }

  if (buttonstate5 == LOW) {
    TV.invert(2);
    delay(40);
  }
}
