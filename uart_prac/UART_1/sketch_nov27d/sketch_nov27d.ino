#include <SoftwareSerial.h>

SoftwareSerial mySerial(4,5);

unsigned char c;
unsigned char b;

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // 입력 문자
  if(mySerial.available()){ // 사용자 정의 시리얼 
    c = mySerial.read();  

    Serial.write(c);  // or Serial.print(c);
  }

  if(Serial.available()){
    b = Serial.read();

    Serial.write(b);
    mySerial.write(b);
  }
}
