
// Status LEDs
const int ledRed20Pin = A3;
const int ledGreenFullPin = A4;
const int ledReadyPin = A5;

// Status LEDs States
byte ledRed20State = LOW;
byte ledGreenFullState = LOW;
byte ledReadyState = LOW;

// Fruit buttons
const int buttonPeanutsPin = 10;
const int buttonNutsPin = 11;
const int buttonAlmondsPin = 12;

// Fruit Buttons States
byte buttonPeanutsState = LOW;
byte buttonNutsState = LOW;
byte buttonAlmondsState = LOW;


// // Tare button
// const int buttonTarePin = 9;


// int ledTareState;

void setup()
{
    pinMode(ledGreenFullPin, OUTPUT);
    digitalWrite(ledGreenFullPin, LOW);

    pinMode(ledRed20Pin, OUTPUT);
    digitalWrite(ledRed20Pin, LOW);

    pinMode(ledReadyPin, OUTPUT);
    digitalWrite(ledReadyPin, LOW);

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    

    pinMode(buttonPeanutsPin, INPUT);
    pinMode(buttonNutsPin, INPUT);
    pinMode(buttonAlmondsPin, INPUT);
    // pinMode(buttonTarePin, INPUT);
}
void loop()
{
    changeLedState(buttonPeanutsPin, buttonPeanutsState, ledRed20Pin, ledRed20State);
    changeLedState(buttonNutsPin, buttonNutsState, ledGreenFullPin, ledGreenFullState);
    changeLedState(buttonAlmondsPin, buttonAlmondsState, ledReadyPin, ledReadyState);
}

void changeLedState(const int &buttonPin, byte &lastButtonState, const int &ledPin, byte &ledState)
{
    byte buttonState = digitalRead(buttonPin);
    if (buttonState != lastButtonState) {
        lastButtonState = buttonState;
        if (buttonState == LOW) {
        ledState = (ledState == HIGH) ? LOW: HIGH;
        digitalWrite(ledPin, ledState);
        }
    }
}