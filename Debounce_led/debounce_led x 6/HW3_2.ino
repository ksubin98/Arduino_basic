const int pinLEDR = 10;
const int pinLEDG = 9;
const int pinLEDB = 8;
const int pinLEDRR = 13;
const int pinLEDGG = 12;
const int pinLEDBB = 11;
const int pinButton[3] = {2, 3, 4};
boolean currentButton[3] = {LOW, LOW, LOW};
boolean lastButton[3] = {LOW, LOW, LOW};
const int pinButton_2[3] = {5, 6, 7};
boolean lastButton_2[3] = {LOW, LOW, LOW};
boolean currentButton_2[3] = {LOW, LOW, LOW};
int ledMode[3] = {0,0,0};
int ledMode_2[3] = {0,0,0};

void setup() {
  pinMode(pinLEDRR, OUTPUT);
  pinMode(pinLEDGG, OUTPUT);
  pinMode(pinLEDBB, OUTPUT);
  pinMode(pinLEDR, OUTPUT);
  pinMode(pinLEDG, OUTPUT);
  pinMode(pinLEDB, OUTPUT);
  pinMode(pinButton[0], INPUT);
  pinMode(pinButton[1], INPUT);
  pinMode(pinButton[2], INPUT);
  pinMode(pinButton_2[0], INPUT);
  pinMode(pinButton_2[1], INPUT);
  pinMode(pinButton_2[2], INPUT);
}

boolean debounce(boolean last, int pin) {
  
  boolean current = digitalRead(pin);
  
  if(current != last) {
    delay(5); 
    current = digitalRead(pin);
  }
  return current;
}

void loop() {
  for(int i=0; i<3; i++)
  currentButton[i] = debounce(lastButton[i],pinButton[i]);

  for(int i=0; i<3; i++) {
    if(currentButton[i] == HIGH && lastButton[i] == LOW) {
      ledMode[i]++; 
      
      if (ledMode[i] > 1) 
      ledMode[i] = 0;
    }
    lastButton[i] = currentButton[i];
    setMode(ledMode[i] + 2*i);
  }

  for(int j=0; j<3; j++)
  currentButton_2[j] = debounce(lastButton_2[j],pinButton_2[j]);
  
   for(int j=0; j<3; j++) {
    if(currentButton_2[j] == HIGH && lastButton_2[j] == LOW) {
      ledMode_2[j]++; if (ledMode_2[j] > 1)  ledMode_2[j] = 0;
    }
    lastButton_2[j] = currentButton_2[j];
    setMode2(ledMode_2[j] + 2*j);
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

void setMode2(int mode2) {
  switch (mode2) {
    case 0: digitalWrite(pinLEDRR, LOW);
            digitalWrite(pinLEDGG, LOW);
            digitalWrite(pinLEDBB, LOW);
            break;
    case 1: digitalWrite(pinLEDRR, HIGH);
            digitalWrite(pinLEDGG, LOW);
            digitalWrite(pinLEDBB, LOW);
            break;
    case 2: digitalWrite(pinLEDRR, LOW);
            digitalWrite(pinLEDGG, LOW);
            digitalWrite(pinLEDBB, LOW);
            break;
    case 3: digitalWrite(pinLEDRR, LOW);
            digitalWrite(pinLEDGG, HIGH);
            digitalWrite(pinLEDBB, LOW);
            break;
    case 4: digitalWrite(pinLEDRR, LOW);
            digitalWrite(pinLEDGG, LOW);
            digitalWrite(pinLEDBB, LOW);
            break;
    case 5: digitalWrite(pinLEDRR, LOW);
            digitalWrite(pinLEDGG, LOW);
            digitalWrite(pinLEDBB, HIGH);
            break;     
  }
}
