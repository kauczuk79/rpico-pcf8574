# PCF8574 library for Raspberry Pi Pico

Library to control output/input pins of the PCF8574 I/O expander controlled throught the I2C bus.

## Changelog

### Version 0.0.1
- ability to put I2C address of the expander
- ability to operate over `i2c0` and `i2c1` buses
- configurable `SDA` and `SCL` pins
- `write8` function which writes full byte on the pins
- `read8` function which reads current state of the pins
- `write` and `read` functions for read and write value of single pin *(not tested)*