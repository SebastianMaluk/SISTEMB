char* morse_dict[] = {
    // The letters A-Z in Morse code
    ".-\0",   // A
    "-...\0", // B
    "-.-.\0", // C
    "-..\0",  // D
    ".\0",    // E
    "..-.\0", // F
    "--.\0",  // G
    "....\0", // H
    "..\0",   // I
    ".---\0", // J 
    "-.-\0",  // K
    ".-..\0", // L
    "--\0",   // M
    "-.\0",   // N
    "---\0",  // O
    ".--.\0", // P
    "--.-\0", // Q
    ".-.\0",  // R
    "...\0",  // S
    "-\0",    // T
    "..-\0",  // U
    "...-\0", // V
    ".--\0",  // W
    "-..-\0", // X
    "-.--\0", // Y
    "--..\0", // Z
    "\0"
};

const int ledPin =  10;

char* plain_text = "El veloz murcielago hindu comia feliz cardillo y kiwi. La ciguena tocaba el saxofon detras del palenque de paja\0";

char* morse_array[120] = {};
char morse_string[400];

bool done = false;

const int time_unit = 200;
const int dot = time_unit;
const int dash = 3 * time_unit;
const int symbol_space= time_unit;
const int letter_space = 3 * time_unit - symbol_space;
const int word_space = 7 * time_unit - letter_space;

void setup() {
    pinMode(ledPin, OUTPUT);
    plain_text_to_morse_array(plain_text, morse_dict, morse_array);
    morse_code_array_to_string(morse_array, morse_string);

}


void loop() {
    if (!done) {
        play_morse_code(morse_string);
        done = true;
    }
}


void plain_text_to_upper(char* plain_text) {
    for (int i = 0; i < strlen(plain_text); i++) {
        plain_text[i] = toupper(plain_text[i]);
    }
}

void plain_text_to_morse_array(char* plain_text, char* morse_dict[], char* morse_array[120]) {
    plain_text_to_upper(plain_text);

    char ch;
    for (int i = 0; i < strlen(plain_text); i++) {
        ch = plain_text[i];
        if (ch == ' ') {
            morse_array[i] = "/\0";
        } else if (ch == '.') {
            morse_array[i] = ".-.-.-\0";
        } else if (ch >= 'A' && ch <= 'Z') {
            morse_array[i] = morse_dict[ch - 'A'];
        }
    }
    morse_array[strlen(plain_text)] = '\0';
}

void morse_code_array_to_string(char* morse_code[], char morse_code_string[400]) {
    int i = 0;
    while (i != 115) {
        strcat(morse_code_string, morse_code[i]);
        strcat(morse_code_string, " ");
        i++;
    }
}


void play_morse_code(char* morse_code) {
    int i = 0;
    while (morse_code[i] != '\0') {
        if (morse_code[i] == '.') {
            flash_dot();
        } else if (morse_code[i] == '-') {
            flash_dash();
        } else if (morse_code[i] == '/') {
            flash_slash();
        } else if (morse_code[i] == ' ') {
            flash_space();
        }
        i++;
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

