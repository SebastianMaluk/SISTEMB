#include "LowPower.h"

int LED_Pin = 9;

int counter = 0;
bool ranOnce = false;

void setup() {
    // put your setup code here, to run once:
    pinMode(LED_Pin, OUTPUT);
}

void cycle_LED_Delay() {
    digitalWrite(LED_Pin, HIGH);
    delay(500);
    digitalWrite(LED_Pin, LOW);
    delay(500);
}

void cycle_LED_PowerDown() {
    digitalWrite(LED_Pin, HIGH);
    LowPower.powerDown(SLEEP_500MS, ADC_OFF, BOD_OFF);
    digitalWrite(LED_Pin, LOW);
    LowPower.powerDown(SLEEP_500MS, ADC_OFF, BOD_OFF);
}

void loop() {
    // put your main code here, to run repeatedly:
    if (counter < 5) {
        cycle_LED_Delay();
        counter++;
    } else if (!ranOnce) {
        LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
        for (int i = 0; i < 5; i++) {
            cycle_LED_PowerDown();
        }
        ranOnce = true;
    }


}