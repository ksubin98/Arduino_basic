#include <Wire.h>
#define sv 8
byte data = 0;
const int pinLM35 = 1;


void setup() {
  Wire.begin(sv);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
}

void loop() {
  data = (byte)(analogRead(pinLM35) * 5 * 100 / 1024.0);
  //Serial.println(data);
  delay(100);
 }

void requestEvent() {
  Wire.write(data);
}
