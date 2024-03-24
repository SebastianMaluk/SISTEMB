#include <EEPROM.h>


int len;
bool flag;
int resp;
int count;

void setup() {
    Serial.begin(9600);
    len = EEPROM.length();
    flag = 0;
    count = 0;
}

void loop() {
    while (!flag) {
      format();
      flag = true;
      Serial.println("P2 Done");
    }
}

void format() {
    for (int i = 0; i < len; i++) {
        if (EEPROM.read(i) != 0) {
            EEPROM.update(i, 0);
            count++;
        }
    }
    Serial.print("Erased ");
    Serial.println(count);
}