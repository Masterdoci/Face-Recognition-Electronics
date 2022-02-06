/*************** Avi Hayun 27/7/18 ***************/
#include "TFT9341Touch.h"
#include <Wire.h>
#include <RTC.h>

tft9341touch LcdTouch(10, 9, 7, 2); //cs, dc ,tcs, tirq

static DS1307 RTC;

// CS  -  to digital pin 10 (CS pin Lcd)
// DC  -  to digital pin 9  (DC pin Lcd)
// TCS  - to digital pin 7  (CS pin Touch)
// IRQ  - to digital pin 2  (IRQ pin Touch)
// MISO - to digital pin 12 (MISO pin Lcd , DO pin Touch)
// MOSI - to digital pin 11 (MOSI pin Lcd , DI pin Touch)
// CLK  - to digital pin 13 (SCK pin Lcd & Touch)


void setup() {
  Serial.begin(9600);
  RTC.begin();

  Serial.print("Is Clock Running: ");
  if (RTC.isRunning())
  {
    Serial.println("Yes");
  }
  LcdTouch.begin();
  LcdTouch.setRotation(0);//0,1,2,3
  LcdTouch.setTextSize (2);
  LcdTouch.setCursor (40, 40);

  if (LcdTouch.touched()) {
    LcdTouch.print("press to set");
    LcdTouch.cal();
    while (1);
  }
  else
    LcdTouch.set(3780, 372, 489, 3811);

  screenMain();
}

void loop() {

  if (LcdTouch.touched())//if (digitalRead(IRQ) == 0)
  {
    LcdTouch.readTouch();  
    int ButtonNum = LcdTouch.ButtonTouch(LcdTouch.xTouch, LcdTouch.yTouch);
    
    if (ButtonNum == 1) // 110 > x > 20 , 70 > y > 20
    {
      screen1();
      screenMain();
    }
    else if (ButtonNum == 2) //if (110 > x > 20 , 150 > y > 100
    {
      screen2();
      screenMain();
    }
  }
}


void screenMain() {
  String str;
  int x = 1235;

  LcdTouch.fillScreen (BLACK);
  LcdTouch.printheb(120, 160, " אבי חיון ", 3, WHITE);
  LcdTouch.println();
  str = "avi  " + String(x) + "  " + float(x / 2);
  LcdTouch.setTextSize (2);
  LcdTouch.print(str);
  LcdTouch.drawButton(1, 20,  20, 90, 50, 10, RED, WHITE, "EXAM1", 2); // NumButton, x, y, width, height, r, Color, textcolor, label, textsize);
  LcdTouch.drawButton(2, 20,  100, 90, 50, 10, BLUE, WHITE, "EXAM2", 2);
}


void screen1() {
  LcdTouch.fillScreen (BLACK);
  LcdTouch.setTextColor(BLACK, CYAN);
  LcdTouch.setTextSize (3);
  LcdTouch.setCursor (25, 30);
  LcdTouch.println ("OK1");
  LcdTouch.setTextSize (1);
  LcdTouch.print ("Press Keyboard to return");

    LcdTouch.print(RTC.getDay());
    LcdTouch.print("-");
    LcdTouch.print(RTC.getMonth());
    LcdTouch.print("-");
    LcdTouch.print(RTC.getYear());
    LcdTouch.print(" ");
    LcdTouch.print(RTC.getHours());
    LcdTouch.print(":");
    LcdTouch.print(RTC.getMinutes());
    LcdTouch.print(":");
    LcdTouch.print(RTC.getSeconds());
    LcdTouch.print("");
  while (!LcdTouch.touched());
}


void screen2() {
  LcdTouch.fillScreen (RED);
  LcdTouch.setTextColor(BLACK, WHITE);
  LcdTouch.setTextSize (4);
  LcdTouch.setCursor (25, 30);
  LcdTouch.println ("OK2");
  LcdTouch.setTextSize (1);
  LcdTouch.print ("Press Keyboard to return");
  LcdTouch.fillRect(10, 150, 80, 50, BLUE); // x, y,width,height
  LcdTouch.fillTriangle(180, 100, 210, 150, 140, 235, CYAN); // x0, y0, x1, y1, x2, y2, color
  LcdTouch.fillCircle(120, 120, 30, WHITE); // x, y, r, color

  while (!LcdTouch.touched());
}
