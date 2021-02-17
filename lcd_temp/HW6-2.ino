#include <LiquidCrystal.h>

const int led = 13;
const int temp = 1;
float set = 22.0, cur;
float val = 0;
const int RS = 2; const int EN = 3;
const int D4 = 4; const int D5 = 5;
const int D6 = 6; const int D7 = 7;
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);

byte degree[8] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000
};

byte fan_off[8] = {
  B00100,
  B00100,
  B00100,
  B11111,
  B00100,
  B00100,
  B00100,
  B00000
};
byte fan_on[8] = {
  B00100,
  B10101,
  B01110,
  B11111,
  B01110,
  B10101,
  B00100,
  B00000
};


void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.createChar(0, degree);
  lcd.createChar(1, fan_off);
  lcd.createChar(2, fan_on);

  lcd.setCursor(0,0); lcd.print("Set:");
  lcd.setCursor(10,0); lcd.write((byte)0);
  lcd.setCursor(11,0); lcd.print("C");
  lcd.setCursor(0,1); lcd.print("Cur:");
  lcd.setCursor(10,1); lcd.write((byte)0);
  lcd.setCursor(11,1); lcd.print("C");
}

void loop() {
  val = analogRead(temp);
  cur = val * 5 * 100 / 1024.0;
  lcd.setCursor(6,0); lcd.print(set, 1);
  lcd.setCursor(6,1); lcd.print(cur, 1);
  lcd.setCursor(15,1);

  if(cur > set){
    lcd.write(2);
    digitalWrite(led,HIGH);
  }else{
    lcd.write(1);
    digitalWrite(led,LOW);
  }
  delay(500);
}
