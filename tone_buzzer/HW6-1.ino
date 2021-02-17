const int buzzer = 11;
const int button[8] = {2,3,4,5,6,7,8,9};
const int tones[] = {262, 294, 330, 349, 392, 440, 494, 523};


void setup() {
 pinMode(buzzer, OUTPUT);
 for(int i =0; i<8; i++){
  pinMode(button[i], INPUT);
 }

}

void loop() {
  for(int i=0; i<8; i++){
      if(digitalRead(button[i]) == HIGH){
        tone(buzzer, tones[i], 20);
      }
  }
  
}
