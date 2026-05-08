#include <util/delay.h>

// Drivers
#include "gpio_driver.h"
#include "led_driver.h"

#define DELAY_TIME 1000
#define LED_PIN GPIO_PIN_B0
#define SWITCH_PIN GPIO_PIN_A1

void app_main(void)
{
    // Initialize the LED driver
    led_driver_init(LED_PIN);
    // Initialize the GPIO driver
    gpio_driver_set_input(SWITCH_PIN);

    // Main loop
    while (1) {
        // Read the switch level
        bool switch_level = gpio_driver_read(SWITCH_PIN);
        // Set the LED level
        led_driver_set(switch_level);
        // Delay for the specified time
        _delay_ms(DELAY_TIME);
    }
}
