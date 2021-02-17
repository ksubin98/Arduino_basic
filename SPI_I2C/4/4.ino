#include <Wire.h>
#define sv2 9

byte i = 0;
const int led =3;
float set = 24;

void setup() {
  Wire.begin(sv2);
  Wire.onReceive(receiveEvent);
  pinMode(led,OUTPUT);
}

void loop() {
  
  delay(100);
}

void receiveEvent(int howMany) {

  byte c;
  while (Wire.available()){
    c = Wire.read();
    Serial.print(c);
  }
  if (c > set) {
    digitalWrite(led, HIGH);
  }else {
     digitalWrite(led,LOW);
  }
}
