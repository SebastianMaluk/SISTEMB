#include <EEPROM.h>


int len;
bool flag;
int resp;

void setup() {
  Serial.begin(9600);
  len = EEPROM.length();
  flag = 0;
  resp;
  delay(500);
}


void loop() {
    while (!flag) {
      for (int i = 0; i < len; i++) {
        resp = EEPROM.read(i);
        Serial.println(resp);
      }
      flag = true;
      Serial.println("P1 Done");
    }
}
