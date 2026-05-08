#include <util/delay.h>

#include "led_driver.h"

#define BLINK_DELAY_MS 1000

int main(void)
{
    led_driver_init(GPIO_PIN_B0);

    while (1) {
        led_driver_toggle();
        _delay_ms(BLINK_DELAY_MS);
    }
}