add_library(led_driver led_driver.c)

target_include_directories(led_driver PUBLIC include)
target_link_libraries(led_driver PUBLIC gpio_driver)
target_compile_options(led_driver PRIVATE
    -mmcu=${MCU}
    -Wall
    -Wextra
    -Wpedantic
    -Os
)
