#include <avr/io.h>
#include "gpio_driver.h"

static volatile uint8_t *gpio_ddr_register(gpio_pin_t pin)
{
    return (pin.port == GPIO_PORT_B) ? &DDRB : &DDRA;
}

static volatile uint8_t *gpio_port_register(gpio_pin_t pin)
{
    return (pin.port == GPIO_PORT_B) ? &PORTB : &PORTA;
}

static volatile uint8_t *gpio_pin_register(gpio_pin_t pin)
{
    return (pin.port == GPIO_PORT_B) ? &PINB : &PINA;
}

void gpio_driver_set_output(gpio_pin_t pin)
{
    *gpio_ddr_register(pin) |= (uint8_t)(1U << pin.bit);
}

void gpio_driver_set_input(gpio_pin_t pin)
{
    *gpio_ddr_register(pin) &= (uint8_t) ~(1U << pin.bit);
    *gpio_port_register(pin) &= (uint8_t) ~(1U << pin.bit);
}

void gpio_driver_set_input_pullup(gpio_pin_t pin)
{
    *gpio_ddr_register(pin) &= (uint8_t) ~(1U << pin.bit);
    *gpio_port_register(pin) |= (uint8_t)(1U << pin.bit);
}

void gpio_driver_write(gpio_pin_t pin, gpio_level_t level)
{
    if ((level && 1) == GPIO_LEVEL_HIGH) {
        *gpio_port_register(pin) |= (uint8_t)(1U << pin.bit);
    } else {
        *gpio_port_register(pin) &= (uint8_t) ~(1U << pin.bit);
    }
}

void gpio_driver_toggle(gpio_pin_t pin)
{
    *gpio_pin_register(pin) = (uint8_t)(1U << pin.bit);
}

gpio_level_t gpio_driver_read(gpio_pin_t pin)
{
  return (gpio_level_t)((*gpio_pin_register(pin) & (uint8_t)(1U << pin.bit)) != 0U);
}
