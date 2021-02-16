const int pinLM35 = 1;
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

  val = analogRead(pinLM35);
  int temp = ((val*5*100)/1024);
  Serial.println(temp);

  if(temp>24){
    digitalWrite(LEDB, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, HIGH);

    delay(1000);
    
  } else{
    digitalWrite(LEDB, HIGH);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, LOW); 
    
    delay(1000); 
  }


}
