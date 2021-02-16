const int pinLEDR = 10;
const int pinLEDG = 9;
const int pinLEDB = 8;
const int pinButton[3] = {2, 3, 4};
boolean lastButton[3] = {LOW, LOW, LOW};
boolean currentButton[3] = {LOW, LOW, LOW};
int ledMode[3] = {0, 0, 0};

void setup() {
  pinMode(pinLEDR, OUTPUT);
  pinMode(pinLEDG, OUTPUT);
  pinMode(pinLEDB, OUTPUT);
  pinMode(pinButton[0], INPUT);
  pinMode(pinButton[1], INPUT);
  pinMode(pinButton[2], INPUT);
}

boolean debounce(boolean last, int pin) {
  boolean current = digitalRead(pin);
  if(current != last) {
    delay(5); current = digitalRead(pin);
  }
  return current;
}

void loop() {
  for(int i=0; i<3; i++)
  currentButton[i] =
  debounce(lastButton[i],
  pinButton[i]);

  for(int i=0; i<3; i++) {
    if(currentButton[i] == HIGH && lastButton[i] == LOW) {
      ledMode[i]++; if (ledMode[i] > 1) ledMode[i] = 0;
    }
    lastButton[i] = currentButton[i];
    setMode(ledMode[i] + 2*i);
  }
}

void setMode(int mode) {
  switch (mode) {
    case 0: digitalWrite(pinLEDR, LOW);
            digitalWrite(pinLEDG, LOW);
            digitalWrite(pinLEDB, LOW);
            break;
    case 1: digitalWrite(pinLEDR, HIGH);
            digitalWrite(pinLEDG, LOW);
            digitalWrite(pinLEDB, LOW);
            break;
    case 2: digitalWrite(pinLEDR, LOW);
            digitalWrite(pinLEDG, LOW);
            digitalWrite(pinLEDB, LOW);
            break;
    case 3: digitalWrite(pinLEDR, LOW);
            digitalWrite(pinLEDG, HIGH);
            digitalWrite(pinLEDB, LOW);
            break;
    case 4: digitalWrite(pinLEDR, LOW);
            digitalWrite(pinLEDG, LOW);
            digitalWrite(pinLEDB, LOW);
            break;
    case 5: digitalWrite(pinLEDR, LOW);
            digitalWrite(pinLEDG, LOW);
            digitalWrite(pinLEDB, HIGH);
            break;     
  }
}
