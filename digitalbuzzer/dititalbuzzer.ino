const int pinBuzzer = 3;
int state = 0;

void setup() {
  pinMode(pinBuzzer , OUTPUT);

}

void loop() {
  if(state < 10){
    digitalWrite(pinBuzzer, HIGH); delay (100);
    digitalWrite(pinBuzzer, LOW); delay (100);
    state++;
  }else if (state>=10 && state < 15){
    tone(pinBuzzer, 262); delay(100); state++;
  }else if (state>=15 && state < 20){
    tone(pinBuzzer, 294); delay(100); state++;
  }else if (state>=20 && state < 25){
    tone(pinBuzzer, 330); delay(100); state++;
  }else if (state>=25 && state < 30){
    tone(pinBuzzer, 349); delay(100); state++;
  }else if (state>=30 && state < 35){
    tone(pinBuzzer, 392); delay(100); state++;
  }else if (state>=35 && state < 40){
    tone(pinBuzzer, 440); delay(100); state++;
  }else if (state>=40 && state < 45){
    tone(pinBuzzer, 494); delay(100); state++;
  }else if (state>=45 && state < 50){
    tone(pinBuzzer, 523); delay(200); state++;
  }else
  noTone(pinBuzzer);
  
}
