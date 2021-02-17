#include <Wire.h>
#define s2 9
byte data = 0;
const int led = 5;
float set = 24.0;

void setup() {
  Wire.begin(s2);
//  Wire.onRequest(requestEvent);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  
  if(Wire.available()){
    
    data = Wire.read();
    
    if((int)data > set)
      digitalWrite(led, HIGH);
     else
      digitalWrite(led,LOW);
  }
 }

/*void requestEvent() {
  Wire.write(data);
}*/
