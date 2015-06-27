#include <Wire.h>


byte addr1 = 1;
byte addr2 = 2;
void setup()
{
Serial.begin(9600);

pinMode(13,OUTPUT);
Wire.begin(); // join i2c bus (address optional for master)
}



void loop()
{

digitalWrite(13,LOW);

byte x= 1;
Serial.print("send to ");
Serial.println(addr1);
digitalWrite(13,HIGH);
Wire.beginTransmission(addr1); // transmit to device #1
Wire.write(x); // sends one byte
Wire.endTransmission(); // stop transmitting
delay(400);
Wire.requestFrom(addr1, 1); // request 6 bytes from slave device #2

while (Wire.available()) // slave may send less than requested
{
byte c = Wire.read(); // receive a byte as character
Serial.print("receive from ");
Serial.print(addr1);
Serial.print(" - ");
Serial.println(c); // print the character
}
digitalWrite(13,LOW);
delay(2000);


Serial.print("send to ");
Serial.println(addr2);
digitalWrite(13,HIGH);
Wire.beginTransmission(addr2); // transmit to device #2
Wire.write(x); // sends one byte
Wire.endTransmission(); // stop transmitting
digitalWrite(13,LOW);
delay(400);
Wire.requestFrom(addr2, 1); // request 6 bytes from slave device #2
//
while (Wire.available()) // slave may send less than requested
{ 
byte c = Wire.read(); // receive a byte as character
Serial.print("receive from ");
Serial.print(addr2);
Serial.print(" - ");
Serial.println(c); // print the character
}
delay(2000);
} 
