const int led_pwm = 9; ; // l1번 핀을 pwm출력 핀으로 설정
unsigned long l3, l4; // l3, l4 반복주기 설정  
unsigned long interval2 = 30; 
int fDir = 0;// led의 상태를 저장할 변수 선언  -> led의 밝기변화가 +,- 인지 
int fade = 0;// led의 상태를 저장할 변수 선언  -> led의 밝기정도를 저장하는 변수  

void setup() {
  l3 = 0;  

}

void loop() {
  l4 = millis(); 
  if(l4 - l3 >= interval2){
    l3 = l4;
    if(!fDir){ //현재 led가 밝기변화가 +면 밝기 증가, 밝기가 255를 넘게 되면 변화방향 -로 저장  
      fade += 5;
      if(fade >= 255){
        fade = 255;
        fDir = 1;
      }
    }else { // 현재 led가 밝기변화가 -면 밝기 감소, 밝기가 0보다 작게되면 변화방향 +로 저장  
      fade -= 5;
      if(fade <=0 ){
        fade =0;
        fDir = 0;
      }
    }
    analogWrite(led_pwm, fade); // 상태 변수 fade에 따라 pwm 출
  }
}
