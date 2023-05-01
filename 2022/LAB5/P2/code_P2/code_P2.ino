// using servo.h set servo to angle received from serial

#include <Servo.h>

Servo servo;

int servoPin = 9; // pin 9 is the servo pin
int servoAngle = 0;

void setup() {
  // put your setup code here, to run once:
  servo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    servoAngle = Serial.parseInt();
    if (servoAngle > 180) {
      servoAngle = 180;
    }
    if (servoAngle < 0) {
      servoAngle = 0;
    }
    servo.write(servoAngle);
  }
}
