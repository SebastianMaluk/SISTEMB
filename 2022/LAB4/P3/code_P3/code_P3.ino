// Se necesita 2 bytes = 16 bits para almacenar el numero 47523 sin utilizar put
// Se necesita 2 bytes = 16 bits para almacenar el numero 47523 utilizando put

#include <EEPROM.h>


unsigned int num;
unsigned int numOut;
bool flag;
unsigned int resp;
int dir = 0;


void setup() {
    Serial.begin(9600);

    num = 47523;

    write_without_put(num, 0);
    resp = read_without_put(0);
    Serial.print("Written without put: ");
    Serial.println(resp, DEC);

    EEPROM.put(2, num);
    EEPROM.get(2, numOut);
    Serial.print("Written with put: ");
    Serial.println(numOut, DEC);
}

void loop() {
    while (!flag) {
        flag = true;
        Serial.println("P3 Done");
    }
}


void write_without_put(unsigned int num, int dir) {
    byte byte1 = num >> 8;
    byte byte2 = num & 0xFF;

    EEPROM.update(dir, byte1);
    EEPROM.update(dir+1, byte2);
}

unsigned int read_without_put(int dir) {
    byte byte1 = EEPROM.read(dir);
    byte byte2 = EEPROM.read(dir + 1);
    unsigned int num = (byte1 << 8) | byte2;

    return num;
}
