/*
    * This example demonstrates how to write a page and read a page from the EEPROM - K24C16.   
    * The EEPROM has 256 pages, each page has 16 bytes.
    * The writePage() function writes data to the EEPROM.
    * I2C address of the EEPROM is 0x50.
*/

#include <Wire.h>
#include <K24C16.h>

void setup() {
    // Initialize the I2C communication is must before using the EEPROM
    Wire.begin();
    Serial.begin(9600);
}

void loop() {
    // Create a data array to store the data to be written to the EEPROM
    unsigned char data[EEPROM_PAGE_SIZE] = {0};

    // Write data to EEPROM
    for (uint8_t i = 0; i < EEPROM_PAGE_SIZE; i++) {
      data[i] = random(0, 256);
    }
  
    writePage(0, data);
    // Print the data written to the EEPROM
    Serial.print("Write Data: ");
    for (uint8_t i = 0; i < EEPROM_PAGE_SIZE; i++) {
      Serial.print(data[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
    
    // Read data from EEPROM
    unsigned char *readData = readPage(0);
    Serial.print("Read Data: ");
    for (uint8_t i = 0; i < EEPROM_PAGE_SIZE; i++) {
      Serial.print(readData[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  
    delay(2000);
}