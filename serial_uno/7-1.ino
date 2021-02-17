const int R = 9;
const int G = 10;
const int B = 11;

boolean state = false;

byte c;


void setup() {
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {
  if(Serial.available()){
    c = Serial.read();

    if(c == 'r'){
      state = !state;
      digitalWrite(R, state);
    }

    if(c == 'g'){
      state = !state;
      digitalWrite(G, state);
    }

    if(c == 'b'){
      state = !state;
      digitalWrite(B, state);
    }

  }
}
