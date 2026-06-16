#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>

typedef enum {
    GPIO_PORT_A = 0U,
    GPIO_PORT_B = 1U
} gpio_port_t;

typedef struct {
    gpio_port_t port;
    uint8_t bit;
} gpio_pin_t;

typedef bool gpio_level_t;

#define GPIO_LEVEL_LOW  ((gpio_level_t)false)
#define GPIO_LEVEL_HIGH ((gpio_level_t)true)

#define GPIO_PIN_A0 ((gpio_pin_t){GPIO_PORT_A, PA0})
#define GPIO_PIN_A1 ((gpio_pin_t){GPIO_PORT_A, PA1})
#define GPIO_PIN_A2 ((gpio_pin_t){GPIO_PORT_A, PA2})
#define GPIO_PIN_A3 ((gpio_pin_t){GPIO_PORT_A, PA3})
#define GPIO_PIN_A4 ((gpio_pin_t){GPIO_PORT_A, PA4})
#define GPIO_PIN_A5 ((gpio_pin_t){GPIO_PORT_A, PA5})
#define GPIO_PIN_A6 ((gpio_pin_t){GPIO_PORT_A, PA6})
#define GPIO_PIN_A7 ((gpio_pin_t){GPIO_PORT_A, PA7})

#define GPIO_PIN_B0 ((gpio_pin_t){GPIO_PORT_B, PB0})
#define GPIO_PIN_B1 ((gpio_pin_t){GPIO_PORT_B, PB1})
#define GPIO_PIN_B2 ((gpio_pin_t){GPIO_PORT_B, PB2})
#define GPIO_PIN_B3 ((gpio_pin_t){GPIO_PORT_B, PB3})
#define GPIO_PIN_B4 ((gpio_pin_t){GPIO_PORT_B, PB4})
#define GPIO_PIN_B5 ((gpio_pin_t){GPIO_PORT_B, PB5})
#define GPIO_PIN_B6 ((gpio_pin_t){GPIO_PORT_B, PB6})
#define GPIO_PIN_B7 ((gpio_pin_t){GPIO_PORT_B, PB7})

void gpio_driver_set_output(gpio_pin_t pin);
void gpio_driver_set_input(gpio_pin_t pin);
void gpio_driver_set_input_pullup(gpio_pin_t pin);
void gpio_driver_write(gpio_pin_t pin, gpio_level_t level);
void gpio_driver_toggle(gpio_pin_t pin);
gpio_level_t gpio_driver_read(gpio_pin_t pin);

#endif
