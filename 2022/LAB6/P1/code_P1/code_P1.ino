const int potentiometerPin = A0;
const int photoresistorPin = A1;


void setup() {
    Serial.begin(9600);
}


void loop() {
    int potentiometerValue = analogRead(potentiometerPin);
    int photoresistorValue = analogRead(photoresistorPin);

    Serial.print("Potentiometer value A0: ");
    Serial.println(potentiometerValue);
    Serial.print("Photoresistor value A1: ");
    Serial.println(photoresistorValue);
    Serial.println();
    
    delay(500);
}
