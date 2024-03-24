const int ledRed20Pin = A4;
const int ledGreenFullPin = A3;
const int ledReadyPin = A5;


void setup()
{
    // Status LEDs
    pinMode(ledRed20Pin, OUTPUT);
    digitalWrite(ledRed20Pin, LOW);

    pinMode(ledGreenFullPin, OUTPUT);
    digitalWrite(ledGreenFullPin, LOW);

    pinMode(ledReadyPin, OUTPUT);
    digitalWrite(ledReadyPin, LOW);
}

void loop()
{
    digitalWrite(ledRed20Pin, HIGH);
    digitalWrite(ledGreenFullPin, LOW);
    digitalWrite(ledReadyPin, LOW);
    delay(1000);
    digitalWrite(ledRed20Pin, LOW);
    digitalWrite(ledGreenFullPin, HIGH);
    digitalWrite(ledReadyPin, LOW);
    delay(1000);
    digitalWrite(ledRed20Pin, LOW);
    digitalWrite(ledGreenFullPin, LOW);
    digitalWrite(ledReadyPin, HIGH);
    delay(1000);
}