const int R = 11;
const int G = 10;
const int B = 9;

const int Trig = 2;
const int Echo = 4;
int Max = 200;
int Min = 0;
long T,L;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);

}

void loop() {
  digitalWrite(Trig, LOW); delayMicroseconds(2);
  digitalWrite(Trig, HIGH); delayMicroseconds(10);
  digitalWrite(Trig, LOW); 

  T = pulseIn(Echo, HIGH);
  L = T/58.2;
  Serial.println(L);

  if( L > 0 && L<10) digitalWrite(R, HIGH);
  else if( L >=10 && L < 15) digitalWrite(G, HIGH);
  else if( L >=15 && L < 30) digitalWrite(B, HIGH);
  else {
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  }
}
