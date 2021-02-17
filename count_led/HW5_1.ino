const int LEDR = 11;
const int LEDG = 10;
const int LEDB = 9;

const int Vib = 3;
byte count = 0;

void setup() {
  pinMode(LEDR,OUTPUT);
  pinMode(LEDG,OUTPUT);
  pinMode(LEDB,OUTPUT);
  pinMode(Vib,INPUT);
  Serial.begin(9600);
  attachInterrupt(1, countVib, FALLING);

}

void loop() {
  if(count != 0){
    count = 0;
    Serial.println(1);
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDB, HIGH);
    delay(100);
    
  }else{
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, LOW);
    delay(100);
  }
}

void countVib(){
  count++;
}
