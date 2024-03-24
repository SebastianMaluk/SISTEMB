int servoPin = 9; // pin 9 is the servo pin

void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(1500);

  digitalWrite(servoPin, LOW);
  delayMicroseconds(18500);
}
