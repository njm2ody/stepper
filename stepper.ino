#include <Stepper.h>

// 1 step == 5.625 angles
const float one_step = 5.625;

Stepper motor = Stepper(64, 8, 9, 10, 11); // steps = 360/5.625, pins
const int rotate_angle = 30; 
const int delay_time = 5000;

const int rotate_steps = (int) rotate_angle/one_step; // coefficient

int count_steps = 0;

void setup(){
    motor.setSpeed(128);
    Serial.begin(9600);
}

void loop(){
  static boolean flag_end = false;
  
  if(test_angle()) {
    turn();
  }
  else{
    if(!flag_end){
      Serial.println('Z');
      flag_end = true;
    }
  }
  
}

void turn(){
    motor.step(rotate_angle * rotate_steps);
    Serial.println('S');
    delay(delay_time);
    Serial.println('A');
    Serial.println('4');
    count_steps++; 
}

boolean test_angle(){
  return count_steps * rotate_angle < 180;
}
