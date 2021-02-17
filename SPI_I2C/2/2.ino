
volatile byte command=0;
volatile byte data=0;
const int LM35=1;
//float cur=0;

void setup() {
  Serial.begin(9600);
  pinMode(MISO, OUTPUT);
  pinMode(LM35, INPUT);
  SPCR |= _BV(SPE);
  SPCR &= ~_BV(MSTR);
  SPCR |= _BV(SPIE);
  
  
}

ISR(SPI_STC_vect){
  byte c=SPDR;
  switch(command){
    case 0:
      command=c;
      SPDR=0;
      break;

    case 's':
      SPDR = data;
      break;
  }
  
}

void loop() {
  data=(byte)(analogRead(LM35)*500/1024.0);
  Serial.println(data);
  delay(100);
  
  if(digitalRead(SS) == HIGH)
    command = 0;
}
