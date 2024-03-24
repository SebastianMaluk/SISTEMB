#include <Stepper.h>
#include <Servo.h>
#include <HX711.h>


const int machineWeight = 1000; // grams

// Stepper
const int stepsPerRevolution = 40;
Stepper myStepper(stepsPerRevolution, 7, 6, 5, 4);
int stepperSpeed = 550;
int direction = 1;

// Servo
const int servoPin = 3;
Servo servo;

// Status LEDs
const int ledGreenFullPin = A3;
const int ledRed20Pin = A4;
const int ledReadyPin = A5;

// Fruit buttons
const int buttonPeanutsPin = 11;
const int buttonNutsPin = 12;
const int buttonAlmondsPin = 13;

// Scale
const int scaleDout = 8;
const int scaleSck = 9;
const int scaleCalibrationFactor = 1; // reading / known weight
HX711 scale;

// Tare button
const int buttonTarePin = 10;


// Variables
int initialWeight = 0;
int dispense_weight = 0;


void setup()
{
    // Stepper
    myStepper.setSpeed(stepperSpeed);
    
    // Servo
    servo.attach(servoPin);
    servo.write(60); // ramp up

    // Status LEDs
    pinMode(ledGreenFullPin, OUTPUT);
    digitalWrite(ledGreenFullPin, LOW);

    pinMode(ledRed20Pin, OUTPUT);
    digitalWrite(ledRed20Pin, LOW);

    pinMode(ledReadyPin, OUTPUT);
    digitalWrite(ledReadyPin, LOW);

    // Fruit buttons
    pinMode(buttonPeanutsPin, INPUT_PULLUP);
    pinMode(buttonNutsPin, INPUT_PULLUP);
    pinMode(buttonAlmondsPin, INPUT_PULLUP);

    // Scale
    scale.begin(scaleDout, scaleSck);
    scale.set_scale(scaleCalibrationFactor);
    scale.set_offset(machineWeight);

    // Tare button
    pinMode(buttonTarePin, INPUT_PULLUP);


    // Initial weight

    digitalWrite(ledReadyPin, HIGH);

}


void loop()
{
    if (digitalRead(buttonPeanutsPin) == HIGH)
    {
        dispense_weight = 50;
        Serial.println("Peanuts");
        dispense(dispense_weight);
    }
    else if (digitalRead(buttonNutsPin) == HIGH)
    {
        dispense_weight = 80;
        Serial.println("Nuts");
        dispense(dispense_weight);
    }
    else if (digitalRead(buttonAlmondsPin) == HIGH)
    {
        dispense_weight = 100;
        Serial.println("Almonds");
        dispense(dispense_weight);
    }

    
}


void fullness()
{
    actualWeight = scale.get_units();
    if (actualWeight > (0.2 * fruitInitialWeight) + machineWeight)
    {
        digitalWrite(ledGreenFullPin, HIGH);
        digitalWrite(ledRedEmptyPin, LOW);
    }
    else
    {
        digitalWrite(ledGreenFullPin, LOW);
        digitalWrite(ledRedEmptyPin, HIGH);
    }
}


void dispense(int grams)
{
    int pre_dispense_weight = scale.get_units(); // 900
    servo.write(80); // ramp down

    while (pre_dispense_weight - scale.get_units() < grams) // 900 - 800 < 100
    {
        myStepper.step(stepsPerRevolution * direction);
        fullness();
    }

    servo.write(60); // ramp up
}