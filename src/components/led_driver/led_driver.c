#include "led_driver.h"

void led_driver_init(led_pin_t pin)
{
    gpio_driver_set_output(pin);
    gpio_driver_write(pin, LED_STATE_OFF);
}

void led_driver_set(led_pin_t pin, led_state_t state)
{
    gpio_driver_write(pin, state);
}

void led_driver_toggle(led_pin_t pin)
{
    gpio_driver_toggle(pin);
}
