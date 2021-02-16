const int led_RED = 13;
const int led_GREEN = 12;
const int led_YELLOW = 8;

void setup() {

 pinMode(led_RED, OUTPUT);
 pinMode(led_GREEN, OUTPUT);
 pinMode(led_YELLOW, OUTPUT);
 

}

void loop() {

  digitalWrite(led_RED, HIGH);
  
  delay(1000);
  digitalWrite(led_RED, LOW);
  
  digitalWrite(led_GREEN, HIGH);
  delay(1000);
  digitalWrite(led_GREEN, LOW);
  
  digitalWrite(led_YELLOW, HIGH);
  delay(1000);
  digitalWrite(led_YELLOW, LOW);
 
  
  

  

}
