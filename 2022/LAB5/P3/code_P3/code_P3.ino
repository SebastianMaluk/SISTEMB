#include <Stepper.h>


// driver pin connections
const int stepsPerRevolution = 2038;  // change this to fit the number of steps per revolution

// stepper motor object
Stepper myStepper(stepsPerRevolution, 11, 10, 9, 8);

int motorSpeed = 1;
int motorDirection = 0;


void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    myStepper.setSpeed(motorSpeed);

    Serial.println("Enter a speed for the stepper motor");
    while (Serial.available() == 0) {
    }
    int motorDirection = Serial.parseInt();
    Serial.print("Motor direction set to ");
    Serial.println(motorDirection);

    Serial.println("Enter a direction either 0 or 1");
    while (Serial.available() == 0) {
    }
    int motorSpeed = Serial.parseInt();

    
    myStepper.setSpeed(motorSpeed);
    Serial.print("Motor speed set to ");
    Serial.println(motorSpeed);
}

void loop() {
    // put your main code here, to run repeatedly:
    if (motorDirection == 1) {
        myStepper.step(stepsPerRevolution);
    }
    if (motorDirection == 0) {
        myStepper.step(-stepsPerRevolution);
    }
}
