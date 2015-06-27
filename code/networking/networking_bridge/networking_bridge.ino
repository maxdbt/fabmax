#include "TinyWireS.h" // wrapper class for I2C slave routines

#define I2C_SLAVE_ADDR 2 // i2c slave address 
//#define LED1_PIN 4 // ATtiny Pin 4
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 4); // RX, TX

void setup(){
//pinMode(LED1_PIN,OUTPUT); // 
// Blink(LED1_PIN,2); // show it's alive
TinyWireS.begin(I2C_SLAVE_ADDR); // init I2C Slave mode
mySerial.begin(9600);
}


void loop(){
byte byteRcvd = 0;
if (TinyWireS.available()){ // got I2C input!
byteRcvd = TinyWireS.receive(); // get the byte from master
// Blink(LED1_PIN,byteRcvd); 

TinyWireS.send(byteRcvd); // send it back to master 
mySerial.println(byteRcvd); 
}
}


void Blink(byte led, byte times){ // poor man's display
for (byte i=0; i< times; i++){
digitalWrite(led,HIGH);
delay (250);
digitalWrite(led,LOW);
delay (175);
}
}
