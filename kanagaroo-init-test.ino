#include <SoftwareSerial.h>
#include <Kangaroo.h>

// Arduino TX (pin 11) goes to Kangaroo S1
// Arduino RX (pin 10) goes to Kangaroo S2
// Arduino GND         goes to Kangaroo 0V
// Arduino 5V          goes to Kangaroo 5V (OPTIONAL, if you want Kangaroo to power the Arduino)
#define TX_PIN 11
#define RX_PIN 10

// Mixed mode channels on Kangaroo are, by default, 'D' and 'T'.
SoftwareSerial  SerialPort(RX_PIN, TX_PIN);
KangarooSerial  K(SerialPort);
KangarooChannel Drive(K, 'D');
KangarooChannel Turn(K, 'T');

void setup()
{
  Serial.begin(9600);
  SerialPort.begin(9600);
  SerialPort.listen();
  Serial.println("Before start");
  Drive.start();
  Serial.println("after drive start");
  Turn.start();
  
  Drive.si(0);
  Turn.si(0);
}

void loop()
{
  // Drive 500 ticks (relative to where we are right now), then wait 1 second.
  Drive.pi(500).wait();
  delay(1000);
 
  // Turn 500 ticks (relative to where we are right now), then wait 1 second.
  Turn.pi(500).wait();  
  delay(1000);
}
