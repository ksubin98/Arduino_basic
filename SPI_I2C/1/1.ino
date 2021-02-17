const int s2 = 9;
volatile boolean done = false;
volatile byte data;
float set = 24.0;
const int led=7;

void setup(){
  pinMode(MOSI, INPUT);
  pinMode(led, OUTPUT);
  SPCR |= _BV(SPE);

  SPCR &= ~_BV(MSTR);

  SPCR |= _BV(SPIE);

}

void loop() {

  if(done){
    if((int)data > set)
      digitalWrite(led, HIGH);
    else 
      digitalWrite(led, LOW);
      done=false;

  }

}

 
ISR(SPI_STC_vect){

  byte c = SPDR;

  data=c;

  done = true;

}
