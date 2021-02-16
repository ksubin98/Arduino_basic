const int pinTilt = 3; 
const int LEDB = 10;
const int LEDG = 9;
const int LEDR = 8;

int val = 0;


void setup() {
  Serial.begin(9600);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDR, OUTPUT);

}

void loop() {
  val = analogRead(pinTilt);

  Serial.println(val);

  if(val==0 || val==1024){
    digitalWrite(LEDB, HIGH);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDR, HIGH);
    
  }else if(val>0 || val<1024){
    digitalWrite(LEDB, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, LOW);
  }

  delay(100);
}
