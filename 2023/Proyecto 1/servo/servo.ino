#include <Servo.h>

int servoPin = 3;
Servo servo;


void setup() {
  servo.attach(servoPin);

}

void loop() {
    servo.write(80);
    delay(1000);
    servo.write(60);
    delay(1000);
}
