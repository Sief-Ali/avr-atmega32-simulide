#include "btn_driver.h"
#include "gpio_driver.h"

void btn_init(btn_pin_t pin, btn_pullup_state_t pullup_state)
{
    if (pullup_state == BTN_PULLUP_STATE_ON) {
        gpio_driver_set_input_pullup(pin);
    } else {
        gpio_driver_set_input(pin);
    }
}

btn_state_t btn_read(btn_pin_t pin)
{
    return gpio_driver_read(pin);
}