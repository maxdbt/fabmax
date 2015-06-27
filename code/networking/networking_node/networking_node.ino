#include "TinyWireS.h" // wrapper class for I2C slave routines

#define I2C_SLAVE_ADDR 1 // i2c slave address 
#define LED1_PIN 4 // ATtiny Pin 4


void setup(){
pinMode(LED1_PIN,OUTPUT); // 
Blink(LED1_PIN,3); // show it's alive
TinyWireS.begin(I2C_SLAVE_ADDR); // init I2C Slave mode
}


void loop(){
byte byteRcvd = 0;
if (TinyWireS.available()){ // got I2C input!
byteRcvd = TinyWireS.receive(); // get the byte from master
Blink(LED1_PIN,byteRcvd); 
TinyWireS.send(byteRcvd); // send it back to master 
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
