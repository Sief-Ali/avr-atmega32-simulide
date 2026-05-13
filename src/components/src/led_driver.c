#include "led_driver.h"

// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
static led_pin_t s_led_pin;

void led_driver_init(led_pin_t pin)
{
    s_led_pin = pin;
    gpio_driver_set_output(s_led_pin);
    gpio_driver_write(s_led_pin, LED_STATE_OFF);
}

void led_driver_set(led_state_t state)
{
    gpio_driver_write(s_led_pin, state);
}

void led_driver_toggle(void)
{
    gpio_driver_toggle(s_led_pin);
}
