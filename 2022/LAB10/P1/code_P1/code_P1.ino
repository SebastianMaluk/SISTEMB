#include "LowPower.h"

int LED_Pin = 9;
int wakeUpPin = 2;

int counter = 0;

void wakeUp() {}

void setup() {
    // put your setup code here, to run once:
    pinMode(LED_Pin, OUTPUT);
    pinMode(wakeUpPin, INPUT);
    attachInterrupt(0, wakeUp, HIGH);
    
}

void cycle_LED() {
    digitalWrite(LED_Pin, HIGH);
    delay(1000);
    digitalWrite(LED_Pin, LOW);
    delay(1000);
}

void loop() {
    // put your main code here, to run repeatedly:
    if (counter < 5) {
        cycle_LED();
        counter++;
    } else {
        LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
        for (int i = 0; i < 5; i++) {
            cycle_LED();
        }
        detachInterrupt(0);
    }


}