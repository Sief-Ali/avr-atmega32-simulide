#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include "gpio_driver.h"

typedef gpio_pin_t led_pin_t;
typedef gpio_level_t led_state_t;

#define LED_STATE_OFF GPIO_LEVEL_LOW
#define LED_STATE_ON GPIO_LEVEL_HIGH

void led_driver_init(led_pin_t pin);
void led_driver_set(led_state_t state);
void led_driver_toggle(void);

#endif
