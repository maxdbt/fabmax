#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX
int ledPin = 8;

void setup()
{
pinMode(ledPin, OUTPUT);
// set the data rate for the SoftwareSerial port
mySerial.begin(9600);

}

void loop() // run over and over
{
// mySerial.println("Hello, world?");
// delay(500);
mySerial.listen();

// while there is data coming in, read it and send back

while (mySerial.available() > 0) {
int blk = mySerial.read();
mySerial.print("echo ");
blk = blk -48;
mySerial.println(blk);
if(blk < 10){ // avoid too many blinks
myBlink(blk);
}
}

}

void myBlink(int rpt){
for(int i= 0; i<rpt; i++){
digitalWrite(ledPin, HIGH); // turn the LED on (HIGH is the voltage level)
delay(150); // wait for a second
digitalWrite(ledPin, LOW); // turn the LED off by making the voltage LOW
delay(150); // wait for a second 
}

}


