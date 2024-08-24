/*
    * This example demonstrates how to write and read data into specified addresses of the EEPROM - K24C16.
    * The EEPROM has 256 pages, each page has 16 bytes.
    * The randomWrite() function writes data to a specified address of the EEPROM.
    * The randomRead() function reads data from a specified address of the EEPROM.
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
    // Write and read data to and from a random address
    unsigned char writeData = random(0, 256);
    randomWrite(25, writeData);

    unsigned char readData = randomRead(25);

    Serial.print("Write Data: ");
    Serial.println(writeData, HEX);
    Serial.print("Read Data: ");
    Serial.println(readData, HEX);
    Serial.println();

    delay(2000);
}