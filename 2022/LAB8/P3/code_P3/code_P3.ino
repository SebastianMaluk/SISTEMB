// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int seconds;
const int potentiometerPin = A0;
int potentiometerValue = 0;

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    Serial.begin(9600);
    pinMode(A0, INPUT);
}

void loop() {
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    seconds = millis() / 1000;
    lcd.print(seconds);
    
    // set cursor to right side
    lcd.setCursor(12, 1);
    // print the value of the potentiometer
    potentiometerValue = analogRead(potentiometerPin);
    lcd.print(potentiometerValue);

    delay(1000);
    lcd.clear();
}
