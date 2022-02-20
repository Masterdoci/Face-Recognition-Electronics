/*
  Software serial multple serial test

  Receives from the hardware serial, sends to software serial.
  Receives from software serial, sends to hardware serial.

  The circuit:
   RX is digital pin 2 (connect to TX of other device)
   TX is digital pin 3 (connect to RX of other device)

  Note:
  Not all pins on the Mega and Mega 2560 support change interrupts,
  so only the following can be used for RX:
  10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

  Not all pins on the Leonardo support change interrupts,
  so only the following can be used for RX:
  8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

  created back in the mists of time
  modified 25 May 2012
  by Tom Igoe
  based on Mikal Hart's example

  This example code is in the public domain.

*/
#include "TFT9341Touch.h"
#include <Wire.h>
#include <RTC.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(A1, A1); // RX, TX
static DS1307 RTC;

void setup()
{
  RTC.begin();
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }



  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);

}
void readUntil(char message[], char terminator) {
  int i = 0;
  while (true) {
    if (mySerial.available()) {
      message[i] = mySerial.read();
      if (message[i] == terminator) {
        message[i] = '\0';
        break;
      }
      ++i;
    }
  }
}
void loop() { // run over and over
  char message[1024] = "";
  if (mySerial.available())
  {
    readUntil(message , '#');
    printName(message);
  }
}


void printName(char message[]) {
  char date[1024] = "";
  char logOutput[1024] = "";
  getDate(date);
  sprintf(logOutput , "%s: %s Entered", date , message);
  Serial.println("To do");
  Serial.println(logOutput);
}

void getDate(char date[]){
  sprintf(date, "%d-%d-%d %d:%d:%d",
    RTC.getDay(),
    RTC.getMonth(),
    RTC.getYear(),
    RTC.getHours(),
    RTC.getMinutes(),
    RTC.getSeconds()
  );
}
