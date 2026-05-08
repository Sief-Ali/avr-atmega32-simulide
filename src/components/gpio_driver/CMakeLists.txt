add_library(gpio_driver gpio_driver.c)

target_include_directories(gpio_driver PUBLIC include)
target_compile_options(gpio_driver PRIVATE
    -mmcu=${MCU}
    -Wall
    -Wextra
    -Wpedantic
    -Os
)
