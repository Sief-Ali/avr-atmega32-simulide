add_library(btn_driver STATIC
    btn_driver.c
    include/btn_driver.h
)

target_include_directories(btn_driver
    PUBLIC
        include
)

target_link_libraries(btn_driver
    PUBLIC
        avr_options
        gpio_driver
)
