// stepper motor control

#include <Stepper.h>

// Stepper
int stepsPerRevolution = 40;
Stepper myStepper(stepsPerRevolution, 7, 6, 5, 4);
int stepperSpeed = 550;
int direction = 1;


void setup()
{
    // Stepper
    myStepper.setSpeed(stepperSpeed);
    
}

void loop()
{
    myStepper.step(stepsPerRevolution * direction);
}