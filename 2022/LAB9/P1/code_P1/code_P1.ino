#include <IRremote.h>
#include <Stepper.h>

// IR
int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;
int signal = 0x00;

// LEDS
int redLEDPin = 2;
bool redLEDState = LOW;

int greenLEDPin = 3;
bool greenLEDState = LOW;

int yellowLEDPin = 4;
bool yellowLEDState = LOW;

// Stepper
int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 13, 11, 12, 10);
bool stepperMoving = false;
int stepperSpeed = 60;
int direction = 1;

void setup()
{
    Serial.begin(9600);

    // IR
    irrecv.enableIRIn(); // Enable IR Reception
    pinMode(6, OUTPUT);

    // LEDS
    pinMode(redLEDPin, OUTPUT);
    pinMode(greenLEDPin, OUTPUT);
    pinMode(yellowLEDPin, OUTPUT);

    // Stepper
    myStepper.setSpeed(stepperSpeed);
}

void toggle_LED(bool &colorLEDState)
{
    if (colorLEDState == LOW)
    {
        colorLEDState = HIGH;
    }
    else
    {
        colorLEDState = LOW;
    }
}

void loop()
{
    if (IrReceiver.decode())
    {                                              // If IR signal received
        signal = IrReceiver.decodedIRData.command; // Get the signal
        if (signal == 0xC)
        { // 1, Red LED toggle
            toggle_LED(redLEDState);
        }
        else if (signal == 0x18)
        { // 2, Green LED toggle
            toggle_LED(greenLEDState);
        }
        else if (signal == 0x5E)
        { // 3, Yellow LED toggle
            toggle_LED(yellowLEDState);
        }
        else if (signal == 0x16)
        { // 0, LEDs off if one or more are on, otherwise all LEDs on
            if (redLEDState == HIGH or greenLEDState == HIGH or yellowLEDState == HIGH)
            {
                redLEDState = LOW;
                greenLEDState = LOW;
                yellowLEDState = LOW;
            }
            else if (redLEDState == LOW and greenLEDState == LOW and yellowLEDState == LOW)
            {
                redLEDState = HIGH;
                greenLEDState = HIGH;
                yellowLEDState = HIGH;
            }
        }
        else if (signal == 0x43)
        { // PLAY/PAUSE, Stepper On
            if (!stepperMoving)
            {
                stepperMoving = true;
            }
        }
        else if (signal == 0x9)
        { // EQ, Stepper Off
            if (stepperMoving)
            {
                stepperMoving = false;
            }
        }
        else if (signal == 0x40)
        { // Fast Forward
            if (direction == 1)
            {                       // If direction is forward
                stepperSpeed += 60; // Increase speed
            }
            else if (direction == -1)
            {                       // If direction is backward
                stepperSpeed -= 60; // Decrease speed
            }
            if (stepperSpeed == 0)
            {                      // If speed is 0
                stepperSpeed = 60; // Set speed to 60
                direction = 1;     // Set direction to forward
            }
            if (stepperSpeed > 240)
            {                       // If speed is greater than 180
                stepperSpeed = 240; // Set speed to 180
            }
        }
        else if (signal == 0x44)
        { // Fast Backward
            if (direction == -1)
            {                       // If direction is backwards
                stepperSpeed += 60; // Increase speed
            }
            else if (direction == 1)
            {                       // If direction is forwards
                stepperSpeed -= 60; // Decrease speed
            }
            if (stepperSpeed == 0)
            {                      // If speed is 0
                stepperSpeed = 60; // Set speed to 60
                direction = -1;    // Set direction to backwards
            }
            if (stepperSpeed > 240)
            {                       // If speed is greater than 180
                stepperSpeed = 240; // Set speed to 180
            }
        }

        /*
         * !!!Important!!! Enable receiving of the next value,
         * since receiving has stopped after the end of the current received data packet.
         */
        IrReceiver.resume(); // Enable receiving of the next value
    }
    digitalWrite(redLEDPin, redLEDState);
    digitalWrite(greenLEDPin, greenLEDState);
    digitalWrite(yellowLEDPin, yellowLEDState);

    if (stepperMoving == true)
    {
        myStepper.step(stepsPerRevolution * direction);
    }
    else
    {
        delay(200);
    }
    myStepper.setSpeed(stepperSpeed);
}
