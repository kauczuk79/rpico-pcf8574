#ifndef PCF8574_h
#define PCF8574_h

#include "hardware/i2c.h"
#include <stdint.h>
#include <stdlib.h>

#define PCF8574_ADDR_1 0x20
#define PCF8574_ADDR_2 0x21
#define PCF8574_ADDR_3 0x22
#define PCF8574_ADDR_4 0x23
#define PCF8574_ADDR_5 0x24
#define PCF8574_ADDR_6 0x25
#define PCF8574_ADDR_7 0x26
#define PCF8574_ADDR_8 0x27

#define PCF8574A_ADDR_1 0x38
#define PCF8574A_ADDR_2 0x39
#define PCF8574A_ADDR_3 0x3A
#define PCF8574A_ADDR_4 0x3B
#define PCF8574A_ADDR_5 0x3C
#define PCF8574A_ADDR_6 0x3D
#define PCF8574A_ADDR_7 0x3E
#define PCF8574A_ADDR_8 0x3F

typedef enum 
{
    Pcf8574Address1 = 0x20,
    Pcf8574Address2 = 0x21,
    Pcf8574Address3 = 0x22,
    Pcf8574Address4 = 0x23,
    Pcf8574Address5 = 0x24,
    Pcf8574Address6 = 0x25,
    Pcf8574Address7 = 0x26,
    Pcf8574Address8 = 0x27,

    Pcf8574AAddress1 = 0x38,
    Pcf8574AAddress2 = 0x39,
    Pcf8574AAddress3 = 0x3A,
    Pcf8574AAddress4 = 0x3B,
    Pcf8574AAddress5 = 0x3C,
    Pcf8574AAddress6 = 0x3D,
    Pcf8574AAddress7 = 0x3E,
    Pcf8574AAddress8 = 0x3F
} PCF8574_address;

class PCF8574 {
    public:
        PCF8574(i2c_inst_t *i2c_port, uint sda, uint scl, PCF8574_address address);
        /**
         * Write a byte value to the expander outputs.
         * @param value Byte to be written
         */
        void write8(const uint8_t value);
        uint8_t read8();
        void write(const uint8_t pin, const uint8_t value);
        uint8_t read(uint8_t pin);

    private:
        i2c_inst_t *i2c_port;
        PCF8574_address address;
};

#endif