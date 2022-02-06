/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 2 (connect to TX of other device)
 * TX is digital pin 3 (connect to RX of other device)

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
#include <SoftwareSerial.h>

SoftwareSerial mySerial(A1, A1); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  
  Serial.println("3");

}
void loop(){ // run over and over
  char name[1024] = "";
  int i = 0;
  if(mySerial.available())
  {
    while(mySerial.available()){
      name[i] = mySerial.read(); 
      ++i;
    }
    sendOkMessage();
    printName(name);
    //Serial.println("4");
    //Serial.print(mySerial.read());
  }
  
  //Serial.println(name);
    // char answer[2] = "OK";
    // char name[1024] = "";
    // int i = 0;
    // while(mySerial.available())
    // {
    //   i = mySerial.read();
    //   mySerial.println(i);
    // }
    // for(i=0; i < 2; ++i){
    //   mySerial.write(answer[i]);
    // }
  //  if(mySerial.available())
//  {
//    Serial.write(mySerial.read());
//  }
}

void sendOkMessage(){
 Serial.println("Goodnight moon!");
 char answer[3] = "OK\n"; 
 for(int i = 0; i < 3; ++i){
    mySerial.write(answer[i]);
  }
}
void printName(const char name[1024]){

  for(int i = 0; name[i] != '\0'; ++i){
    Serial.println(name[i]);
  }
}
