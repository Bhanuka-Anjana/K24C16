/*
    * K24C16.cpp
    * This is a library for the K24C16 I2C EEPROM.
    * Created on: 2019. 6. 25.
*/

#include <K24C16.h>

void writePage(uint8_t page, unsigned char *data) {
  Wire.beginTransmission(EEPROM_ADDR);
  Wire.write(page);
  Wire.write(data, EEPROM_PAGE_SIZE);
  Wire.endTransmission();
  delay(50);
}

unsigned char *readPage(uint8_t page) {
  static unsigned char data[EEPROM_PAGE_SIZE] = {0};
  Wire.beginTransmission(EEPROM_ADDR);
  Wire.write(page);
  Wire.endTransmission();

  Wire.requestFrom(EEPROM_ADDR, EEPROM_PAGE_SIZE);
  uint8_t i = 0;

  // wait until data is available
  while(Wire.available()) {
    data[i] = Wire.read();
    i++;

    // break if all data is read / page completed
    if (i == EEPROM_PAGE_SIZE) {
      break;
    }
  }

  return data;
}

void randomWrite(uint8_t addr, unsigned char data) {
  Wire.beginTransmission(EEPROM_ADDR);
  Wire.write(addr);
  Wire.write(data);
  Wire.endTransmission();
  delay(10);
}

unsigned char randomRead(uint8_t addr){
  Wire.beginTransmission(EEPROM_ADDR);
  Wire.write(addr);
  Wire.endTransmission();

  Wire.requestFrom(EEPROM_ADDR, 1);
  while(Wire.available()) {
    return Wire.read();
  }
  return 0;
}

