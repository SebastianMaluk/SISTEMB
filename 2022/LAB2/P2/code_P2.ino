const int ledPin = 10;
const int buttonPin = 4;

int ledState = LOW;
int buttonState = 0;

unsigned long timePassed = 0;
unsigned long timePressed = 0;
unsigned long timeWhenPressed = 0;
unsigned long timeWhenReleased = 0;


void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
}

void loop() {

    // read amount of seconds button is pressed maximum 9 seconds
    // pulse the led for 100ms for every second pressed

    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
        timePressed = 0;
        timeWhenPressed = millis();
        while (buttonState == HIGH) {
            timePassed = millis() - timeWhenPressed;
            if (timePassed > 9000) {
                buttonState = LOW;
                digitalWrite(LED_BUILTIN, HIGH);
                delay(100);
                digitalWrite(LED_BUILTIN, LOW);
            }
            buttonState = digitalRead(buttonPin);
        }
        timeWhenReleased = millis();
        timePassed = timeWhenReleased - timeWhenPressed;
        for (int i = 0; i < timePassed/1000; i++) {
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
            delay(100);
        }
    }
    else {
        timePressed = 0;
    }
}