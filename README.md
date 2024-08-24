# K24C16 EEPROM Library 

        --------------------
        |  *                |
  A0  - | 1    K24C16     8 | - VCC
  A1  - | 2               7 | - WP (GND)
  A2  - | 3               6 | - SCL
  GND - | 4               5 | - SDA
        |                   | 
        ---------------------

- This is a library for the K24C16 EEPROM. 
- It has 256 pages of 16 bytes each.
- It is communicating over I2C. 

## Dependencies
- [Wire](https://www.arduino.cc/en/Reference/Wire) - Arduino's standard I2C communication library
- [K24C16 DATASHEET](https://www.alldatasheet.com/datasheet-pdf/pdf/1131962/ETC1/K24C16.html) - The datasheet for the K24C16 EEPROM