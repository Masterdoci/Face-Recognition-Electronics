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
#include <Servo.h>
#include <SPI.h>
#include <ISD4004.h>
#include "TFT9341Touch.h"
#include <Wire.h>
#include <RTC.h>
#include <SoftwareSerial.h>


Servo myservo;
SoftwareSerial mySerial(A1, A1); // RX, TX
static DS1307 RTC;

#define recordPin  2

ISD4004 my_voice(6,8);//ss,int


void setup()
{
  // init the servo.
  myservo.attach(4);
  myservo.write(0);

//  pinMode(recordPin, INPUT_PULLUP);
  RTC.begin();

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for Native USB only
  }
    Serial.println("start project - employees sistem.");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);

}

void loop() { 
  String msg;
  if (mySerial.available())
  {
    msg = mySerial.readStringUntil('#');
    login_employee(msg);
  }
}

void login_employee(String user_name)
{
  // open the door and voice msg to the employee.
  my_voice.PlayInt(100);
  myservo.write(90);
  delay(5000);
  myservo.write(0);

  //print the employee name.
  Serial.println(user_name);
  
  // print the details of the login employee.
  Serial.print("entrance time: ");
  char date[1024] = "";
  getDate(date);
  Serial.println(date);
}


void getDate(char date[])
{
  sprintf(date, "%d-%d-%d %d:%d:%d",
    RTC.getDay(),
    RTC.getMonth(),
    RTC.getYear(),
    RTC.getHours(),
    RTC.getMinutes(),
    RTC.getSeconds()
  );
}
