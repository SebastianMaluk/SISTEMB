#include <Stepper.h>


// with a motor stopped, accelerate to a speed and then decelerate to a stop
// using a ramp function

// driver pin connections
const int stepsPerRevolution = 2038;


// stepper motor object
Stepper myStepper(stepsPerRevolution, 11, 10, 9, 8);


int motorSpeed = 1;
int motorDirection = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myStepper.setSpeed(motorSpeed);

  
  delay(2000);
  ramp()


}

void loop() {
  // put your main code here, to run repeatedly:
}

void ramp() {
  for (int i = 0; i < 100; i++) {
    myStepper.setSpeed(i);
    myStepper.step(stepsPerRevolution);
    delay(100);
  }
  for (int i = 100; i > 0; i--) {
    myStepper.setSpeed(i);
    myStepper.step(stepsPerRevolution);
    delay(100);
  }
}
// void ramp() {
//     // ramp up to speed
//     for (int i = 0; i < motorSpeed; i++) {
//         myStepper.setSpeed(i);
//         myStepper.step(1);
//     }
//     // ramp down to stop
//     for (int i = motorSpeed; i > 0; i--) {
//         myStepper.setSpeed(i);
//         myStepper.step(1);
//     }
// }