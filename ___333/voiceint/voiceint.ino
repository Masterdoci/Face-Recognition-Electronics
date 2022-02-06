
#include <SPI.h>
#include <ISD4004.h>

#define recordPin  2
//#define ledPin   13 

ISD4004 voice(6,8);//ss,int


void setup() {
pinMode(recordPin, INPUT_PULLUP);
 //digitalWrite(ledPin, LOW);
}

void loop() {
  if(!digitalRead(recordPin))
  {
   // digitalWrite(ledPin, HIGH); // turn LED on:
    delay(20);
voice.StartRecord(0);
while(!digitalRead(recordPin));
voice.StopRecord();
voice.PlayInt(0);
// digitalWrite(ledPin, LOW); // turn LED off:
  }
}
