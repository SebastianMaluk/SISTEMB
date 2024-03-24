// constants won't change. Used here to set a pin number:
const int ledPin_BUILTIN =  LED_BUILTIN;// the number of the LED pin
const int ledPin_YELLOW = 10;
const int buttonPin = 4;

// Variables will change:
int ledState_BUILTIN = LOW;             // ledState used to set the LED
int ledState_YELLOW = LOW;
int buttonState = 0;                    // variable for reading the pushbutton status


unsigned long previousMillis_BUILTIN = 0;  // will store last time BUILTIN_LED was updated
unsigned long previousMillis_YELLOW = 0;   // will store last time YELLOW_LED was updated

// intervalS at which to blink (milliseconds)
const long interval_BUILTIN = 500;
const long interval_YELLOW = 100;

void setup() {
    // set the digital pin as output:
    pinMode(ledPin_BUILTIN, OUTPUT);
    pinMode(ledPin_YELLOW, OUTPUT);
	pinMode(buttonPin, INPUT);
}

void loop() {
    unsigned long currentMillis = millis();
	buttonState = digitalRead(buttonPin);

	if (buttonState == HIGH) {
		if (currentMillis - previousMillis_BUILTIN >= interval_BUILTIN) {
			// save the last time the LED blinked
			previousMillis_BUILTIN = currentMillis;

			// if the LED is off turn it on and vice-versa:
			if (ledState_BUILTIN == LOW) {
				ledState_BUILTIN = HIGH;
			} else {
				ledState_BUILTIN = LOW;
			}

			// set the LED with the ledState of the variable:
			digitalWrite(ledPin_BUILTIN, ledState_BUILTIN);
		}

		if (currentMillis - previousMillis_YELLOW >= interval_YELLOW) {
			previousMillis_YELLOW = currentMillis;

			// if the LED is off turn it on and vice-versa:
			if (ledState_YELLOW == LOW) {
				ledState_YELLOW = HIGH;
			} else {
				ledState_YELLOW = LOW;
			}

			// set the LED with the ledState of the variable:
			digitalWrite(ledPin_YELLOW, ledState_YELLOW);
		}
	} else {
		digitalWrite(ledPin_BUILTIN, LOW);
		digitalWrite(ledPin_YELLOW, LOW);
	}
}
