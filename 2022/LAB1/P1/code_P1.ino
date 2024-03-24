// constants won't change. Used here to set a pin number:
const int ledPin_BUILTIN =  LED_BUILTIN;// the number of the LED pin
const int ledPin_YELLOW = 10;

// Variables will change:
int ledState_BUILTIN = LOW;             // ledState used to set the LED
int ledState_YELLOW = LOW;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis_BUILTIN = 0;        // will store last time LED was updated
unsigned long previousMillis_YELLOW = 0;        // will store last time LED was updated

// constants won't change:
const long interval_BUILTIN = 500;           // interval at which to blink (milliseconds)
const long interval_YELLOW = 100;

void setup() {
    // set the digital pin as output:
    pinMode(ledPin_BUILTIN, OUTPUT);
    pinMode(ledPin_YELLOW, OUTPUT);
}

void loop() {
    // here is where you'd put code that needs to be running all the time.

    // check to see if it's time to blink the LED; that is, if the difference
    // between the current time and last time you blinked the LED is bigger than
    // the interval at which you want to blink the LED.
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis_BUILTIN >= interval_BUILTIN) {
        // save the last time you blinked the LED
        previousMillis_BUILTIN = currentMillis;

        // if the LED is off turn it on and vice-versa:
        if (ledState_BUILTIN == LOW) {
            ledState_BUILTIN = HIGH;
        } else if (ledState_BUILTIN == HIGH) {
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
        } else if (ledState_YELLOW == HIGH) {
            ledState_YELLOW = LOW;
        }

        // set the LED with the ledState of the variable:
        digitalWrite(ledPin_YELLOW, ledState_YELLOW);
    }
}
