const int pinLED = 13;
byte c;


void setup() {
 Serial.begin(9600);
 pinMode(pinLED, OUTPUT);

}

void loop() {
  if(Serial.available()){
    c = Serial.read();

    if(c == '1'){
      digitalWrite(pinLED, HIGH);
      Serial.println("LED on");
    }else if (c =='0'){
      digitalWrite(pinLED, LOW);
      Serial.println("LED off");
    }
  }

}
