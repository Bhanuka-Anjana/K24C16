/*
    * K24C16.h
    * This is a library for the K24C16 I2C EEPROM.
    *  Created on: 2019. 6. 25.
*/

#ifndef K24C16_H
#define K24C16_H

#include <Arduino.h>
#include <Wire.h>

#define EEPROM_ADDR 0x50
#define EEPROM_PAGE_SIZE 16
#define EEPROM_SIZE 256

void writePage(uint8_t page, unsigned char *data);
unsigned char *readPage(uint8_t page);
void randomWrite(uint8_t addr, unsigned char data);
unsigned char randomRead(uint8_t addr);

#endif // K24C16_H