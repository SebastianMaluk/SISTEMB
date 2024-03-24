#include "LowPower.h"

int LED_Pin = 9;

void setup() {
    // put your setup code here, to run once:
    pinMode(LED_Pin, OUTPUT);    
}

void cycle_LED() {
    digitalWrite(LED_Pin, HIGH);
    LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
    digitalWrite(LED_Pin, LOW);
    LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
}

void loop() {
    // put your main code here, to run repeatedly:
    cycle_LED();
}