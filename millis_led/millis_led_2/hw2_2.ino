const int led_pwm_R = 11;
const int led_pwm_G = 10;
const int led_pwm_Y = 9;
 
unsigned long l3, l4, l5, l6, l7;
unsigned long interval = 40;

int p = 0;
int fDir, fDir_G, fDir_Y  = 0; 
int fade, fade_G, fade_Y = 0; 
int fDir_GG = 0; 


void setup() {  
  l3 = 0;
  l5 = 0;
  l6 = 0;
  l7 = 0;

} 

void loop() {

l4 = millis();
  
if(p == 0){  
  if ( l4- l3 >= interval){ 
    l3= l4;
    if (!fDir){ 
        fade += 5;
        if (fade >= 255){ 
            fade = 255; fDir = 1; } 
        } 
    else { 
        fade -= 5;
        if (fade <= 0){ 
            fade = 0; fDir = 0; p = 1;} 
        }
  }

   analogWrite(led_pwm_R, fade);
}

if(p == 1){   
  if (l4 - l5 >= interval){ 
    l5 = l4;
    if (!fDir_G){ 
        fade_G += 5;
        if (fade_G >= 255){ 
            fade_G = 255; 
            fDir_G = 1; } 
        } 
    else { 
        fade_G -= 5;
        if (fade_G <= 0){ 
            fade_G = 0; 
            fDir_G = 0; 
            p = 2;} 
        }
  }
   analogWrite(led_pwm_G, fade_G);

}

if(p == 2){   
  if (l4 - l6 >= interval){ 
    l6 = l4;
    if (!fDir_Y){ 
        fade_Y += 5;
        if (fade_Y >= 255){ 
            fade_Y = 255; 
            fDir_Y = 1; } 
        } 
    else { 
        fade_Y -= 5;
        if (fade_Y <= 0){ 
            fade_Y = 0; 
            fDir_Y = 0;
            p = 3;} 
        }
  }
   analogWrite(led_pwm_Y, fade_Y);
}

if(p == 3){   
  if (l4 - l7 >= interval){ 
    l7 = l4;
    if (!fDir_GG){ 
        fade_G += 5;
        if (fade_G >= 255){ 
            fade_G = 255; 
            fDir_GG = 1; } 
        } 
    else { 
        fade_G -= 5;
        if (fade_G <= 0){ 
            fade_G = 0; 
            fDir_GG = 0; 
            p = 0;} 
        }
  }
   analogWrite(led_pwm_G, fade_G);

}
    
     } 
