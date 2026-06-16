add_library(gpio_driver STATIC
    gpio_driver.c
    include/gpio_driver.h
)

target_include_directories(gpio_driver
    PUBLIC
        include
)

target_link_libraries(gpio_driver
    PUBLIC
        avr_options
)
