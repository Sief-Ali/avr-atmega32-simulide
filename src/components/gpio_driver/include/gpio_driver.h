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

#define GPIO_PA0 ((gpio_pin_t){GPIO_PORT_A, PA0})
#define GPIO_PA1 ((gpio_pin_t){GPIO_PORT_A, PA1})
#define GPIO_PA2 ((gpio_pt){GPIO_PORT_A, PA2})
#define GPIO_PA3 ((gpio_pt){GPIO_PORT_A, PA3})
#define GPIO_PA4 ((gpio_pt){GPIO_PORT_A, PA4})
#define GPIO_PA5 ((gpio_pt){GPIO_PORT_A, PA5})
#define GPIO_PA6 ((gpio_pt){GPIO_PORT_A, PA6})
#define GPIO_PA7 ((gpio_pt){GPIO_PORT_A, PA7})

#define GPIO_PB0 ((gpio_pin_t){GPIO_PORT_B, PB0})
#define GPIO_PB1 ((gpio_pin_t){GPIO_PORT_B, PB1})
#define GPIO_PB2 ((gpio_pin_t){GPIO_PORT_B, PB2})
#define GPIO_PB3 ((gpio_pin_t){GPIO_PORT_B, PB3})
#define GPIO_PB4 ((gpio_pin_t){GPIO_PORT_B, PB4})
#define GPIO_PB5 ((gpio_pin_t){GPIO_PORT_B, PB5})
#define GPIO_PB6 ((gpio_pin_t){GPIO_PORT_B, PB6})
#define GPIO_PB7 ((gpio_pin_t){GPIO_PORT_B, PB7})

void gpio_driver_set_output(gpio_pin_t pin);
void gpio_driver_set_input(gpio_pin_t pin);
void gpio_driver_set_input_pullup(gpio_pin_t pin);
void gpio_driver_write(gpio_pin_t pin, gpio_level_t level);
void gpio_driver_toggle(gpio_pin_t pin);
gpio_level_t gpio_driver_read(gpio_pin_t pin);

#endif
