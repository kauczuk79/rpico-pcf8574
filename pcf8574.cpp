#include <pico/error.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "pico/stdlib.h"
#include "pcf8574.h"
#include <stddef.h>

PCF8574::PCF8574(i2c_inst_t *i2c_port, uint sda, uint scl, PCF8574_address address) {
    PCF8574::i2c_port = i2c_port;
    PCF8574::address = address;

    i2c_init(i2c_port, 100000);
    gpio_set_function(sda, GPIO_FUNC_I2C);
    gpio_set_function(scl, GPIO_FUNC_I2C);
    gpio_pull_up(sda);
    gpio_pull_up(scl);
}

void PCF8574::write8(const uint8_t value) {
    const uint8_t write_address = PCF8574::address;
    if(i2c_write_blocking(PCF8574::i2c_port, write_address, &value, 1, false) <= 0) {
        printf("FAILED TO WRITE TO I2C\n");
    }
}

uint8_t PCF8574::read8() {
    const uint8_t read_address = (PCF8574::address);
    uint8_t value[1];
    uint8_t write = 0x00;
    int wresult = i2c_write_blocking(PCF8574::i2c_port, (read_address << 1) + 1, &write, 1, true);
    if(wresult <= 0) {
        printf("FAILED TO WRITE TO I2C %d\n", wresult);
    }
    int result = i2c_read_blocking(PCF8574::i2c_port, read_address, value, 1, false);
    if(result <= 0) {
        printf("FAILED TO READ FROM I2C %d\n", result);
    }
    printf("%d %d\n", *value, value);
    return *value;
}

void PCF8574::write(const uint8_t pin, const uint8_t value) {
    uint8_t current_value = PCF8574::read8();
    if (value == 1) {
        current_value &= ~(1 << pin);
    } else if (value == 0) {
        current_value |= (1 << pin);
    }
    PCF8574::write8(current_value);
}

uint8_t PCF8574::read(const uint8_t pin) {
    const uint8_t current_value = PCF8574::read8();
    return (current_value & (1 << pin)) > 0;
}