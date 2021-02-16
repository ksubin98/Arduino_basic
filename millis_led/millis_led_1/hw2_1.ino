const int led_r = 13;
const int led_g = 12;
const int led_y = 8;

unsigned long l1, l2, l3, l4, l5, l6;
unsigned long interval1 = 2000;
unsigned long interval2 = 4000;
unsigned long interval3 = 6000;
int fON_r = 0;
int fON_g = 0;
int fON_y = 0;


void setup() {
  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(led_y, OUTPUT);

  l1 = 0;
  l3 = 0;
  l5 = 0;
  
}

void loop() {
  l2 = millis();

  if(l2 -l1 >= interval1) {
    l1 = l2;

    if(!fON_r) {
      fON_r = HIGH;
    } else { fON_r = LOW;}

    digitalWrite(led_r, fON_r);
  }


  l4 = millis();

  if(l4 -l3 >= interval2) {
    l3 = l4;

    if(!fON_g) {
      fON_g = HIGH;
    } else { fON_g = LOW;}

    digitalWrite(led_g, fON_g);

}

  l6 = millis();
  
  if(l6 -l5 >= interval3) {
    l5 = l6;

    if(!fON_y) {
      fON_y = HIGH;
    } else { fON_y = LOW;}

    digitalWrite(led_y, fON_y);
  }
}
