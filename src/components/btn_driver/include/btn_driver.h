#ifndef BTN_DRIVER_H
#define BTN_DRIVER_H

#include "gpio_driver.h"

typedef gpio_pin_t btn_pin_t;
typedef gpio_level_t btn_state_t;
typedef enum {
    BTN_PULLUP_STATE_OFF = 0U,
    BTN_PULLUP_STATE_ON = 1U
} btn_pullup_state_t;

#define BTN_STATE_OFF GPIO_LEVEL_LOW
#define BTN_STATE_ON GPIO_LEVEL_HIGH

void btn_init(btn_pin_t pin, btn_pullup_state_t pullup_state);
btn_state_t btn_read(btn_pin_t pin);

#endif
