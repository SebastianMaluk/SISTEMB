const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;


void setup() {
    // initialize LCD in 4-bit mode without liquid crystal library
    pinMode(rs, OUTPUT);
    pinMode(en, OUTPUT);
    pinMode(d4, OUTPUT);
    pinMode(d5, OUTPUT);
    pinMode(d6, OUTPUT);
    pinMode(d7, OUTPUT);

    // 2
    // initialize LCD in 4-bit mode
    digitalWrite(rs, LOW);
    digitalWrite(d7, LOW);
    digitalWrite(d6, LOW);
    digitalWrite(d5, HIGH);
    digitalWrite(d4, LOW);

    delay(100);

    // 3.1
    digitalWrite(rs, LOW);
    digitalWrite(d7, LOW);
    digitalWrite(d6, LOW);
    digitalWrite(d5, HIGH);
    digitalWrite(d4, LOW);

    delay(100);

    // 3.2
    digitalWrite(rs, LOW);
    digitalWrite(d7, LOW);
    digitalWrite(d6, LOW);
    digitalWrite(d5, HIGH);
    digitalWrite(d4, LOW);

    delay(100);

    // 4.1
    digitalWrite(rs, LOW);
    digitalWrite(d7, LOW);
    digitalWrite(d6, LOW);
    digitalWrite(d5, LOW);
    digitalWrite(d4, LOW);

    delay(100);

    // 4.2
    digitalWrite(rs, LOW);
    digitalWrite(d7, HIGH);
    digitalWrite(d6, HIGH);
    digitalWrite(d5, HIGH);
    digitalWrite(d4, LOW);

    delay(100);

    // 5.1
    digitalWrite(rs, LOW);
    digitalWrite(d7, LOW);
    digitalWrite(d6, LOW);
    digitalWrite(d5, LOW);
    digitalWrite(d4, LOW);

    delay(100);

    // 5.2
    digitalWrite(rs, LOW);
    digitalWrite(d7, LOW);
    digitalWrite(d6, HIGH);
    digitalWrite(d5, HIGH);
    digitalWrite(d4, LOW);

    delay(100);

    // 6.1 Write to DDRAM H
    digitalWrite(rs, HIGH);
    digitalWrite(d7, LOW);
    digitalWrite(d6, HIGH);
    digitalWrite(d5, LOW);
    digitalWrite(d4, LOW);

    delay(100);

    // 6.2 Move cursor
    digitalWrite(rs, HIGH);
    digitalWrite(d7, HIGH);
    digitalWrite(d6, LOW);
    digitalWrite(d5, LOW);
    digitalWrite(d4, LOW);
}



void loop() {

}
