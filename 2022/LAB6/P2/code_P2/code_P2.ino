const int potentiometerPin = A0;
const int photoresistorPin = A1;


void setup() {
    Serial.begin(9600);
}


void loop() {
    int potentiometerValue = analogRead(potentiometerPin);
    int photoresistorValue = analogRead(photoresistorPin);

    Serial.print(potentiometerValue);
    Serial.print(',');
    Serial.println(photoresistorValue);

    delay(1);
}
