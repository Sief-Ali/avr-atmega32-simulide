add_library(led_driver STATIC
    led_driver.c
    include/led_driver.h
)

target_include_directories(led_driver
    PUBLIC
        include
)

target_link_libraries(led_driver
    PUBLIC
        avr_options
        gpio_driver
)
