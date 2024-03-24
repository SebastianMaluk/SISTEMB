#include <EEPROM.h>


typedef struct Data {
  int num1;
  int num2;
  char word[10];

} Data;

bool flag = false;
char c;

Data dataIn;
Data dataOut;

String plain_text;


void setup() {
    Serial.begin(9600);
    delay(200);


    
    // write user input into struct num1
    Serial.println("Enter a number: ");
    while (Serial.available() == 0) {
      // wait for user input
    }
    dataIn.num1 = Serial.parseInt();
    delay(500);
    
    // write user input into struct num2
    Serial.println("Enter another number: ");
    while (Serial.available() == 0) {
      // wait for user input
    }
    dataIn.num2 = Serial.parseInt();
    delay(500);

    // write user input into struct word
    Serial.println("Enter a word: ");
    while (Serial.available() == 0) {
      // wait for user input
    }
    plain_text = Serial.readString();
    plain_text.trim();
    for (int i = 0; i < plain_text.length(); i++) {
      dataIn.word[i] = plain_text[i];
    }


    EEPROM.put(0, dataIn);


    EEPROM.get(0, dataOut);
    show_data(dataOut);
}

void loop() {
    while (!flag) {
        flag = true;
        Serial.println("P4 Done");
    }
}


void show_data(Data data) {
    Serial.print("num1 = ");
    Serial.println(data.num1);

    Serial.print("num2 = ");
    Serial.println(data.num2);

    Serial.print("word = ");
    for (int i = 0; i < 10; i++) {
        if (data.word[i] == '\0') {
            break;
        }
        Serial.print(data.word[i]);
    }
    Serial.print("\n");
}
