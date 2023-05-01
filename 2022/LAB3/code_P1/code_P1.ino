char* morse_dict[] = {
    // The letters A-Z in Morse code
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J 
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--.."  // Z

};

char* mors_nums[] = {
    // The numbers 0-9 in Morse code
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----."  // 9
};


int ledPin = 10;
int buttonPin = 4;


String plain_text;

String morse_code;

const int time_unit = 200;
const int dot = time_unit;
const int dash = 3 * time_unit;
const int symbol_space = time_unit;
const int letter_space = 3 * time_unit - symbol_space;
const int word_space = 7 * time_unit - letter_space;

void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(buttonPin, INPUT);
}


void loop() {
    if (digitalRead(buttonPin) == HIGH) {
        Serial.println("Botón");
        while (digitalRead(buttonPin) == HIGH) {
        }
    }
    // if serial available read serial input whole line into plain_text
    if (Serial.available() > 0) { // while morse is playing BUILTIN_LED is on
        digitalWrite(LED_BUILTIN, HIGH);
        plain_text = Serial.readString();
        plain_text.trim();
        morse_code = plain_to_morse(plain_text);
        Serial.println(morse_code);
        play_morse(morse_code);
        digitalWrite(LED_BUILTIN, LOW);
    }
}


// plain text to morse code
String plain_to_morse(String plain_text) {
    plain_text.toUpperCase();
    String morse_code = "";
    for (int i = 0; i < plain_text.length(); i++) {
        char c = plain_text.charAt(i);
        if (c == ' ') {
            morse_code += '/';
            morse_code += ' ';
        } else if (65 <= c && c <= 90) {
            morse_code += morse_dict[c - 65];
            morse_code += ' ';
        } else if (48 <= c && c <= 57) {
            morse_code += mors_nums[c - 48];
            morse_code += ' ';
        } else {
            morse_code += '?';
        }
    }
    return morse_code;
}


void play_morse(String morse_code) {
    for (int i = 0; i < morse_code.length(); i++) {
        char c = morse_code.charAt(i);
        if (c == '/') {
            flash_slash();
        } else if (c == '.') {
            flash_dot();
        } else if (c == '-') {
            flash_dash();
        } else if (c == ' ') {
            flash_space();
        }
        delay(symbol_space);
    }
}



// the dot is the shortest unit of time
void flash_dot() {
    digitalWrite(ledPin, HIGH);
    delay(dot);
    digitalWrite(ledPin, LOW);
}

// the dash is 3 times the dot duration
void flash_dash() {
    digitalWrite(ledPin, HIGH);
    delay(dash);
    digitalWrite(ledPin, LOW);
}

// the space is 3 times the dot duration
void flash_space() {
    delay(letter_space);
}

// the slash is 7 times the dot duration
void flash_slash() {
    delay(word_space);
}
