add_subdirectory(components/gpio_driver)
add_subdirectory(components/led_driver)

file(GLOB COMPONENT_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/components/*/include")

add_executable(${PROJECT_NAME}.elf main.c)
target_include_directories(${PROJECT_NAME}.elf PRIVATE ${COMPONENT_INCLUDE_DIRS})

target_compile_definitions(${PROJECT_NAME}.elf PRIVATE F_CPU=${F_CPU})
target_compile_options(${PROJECT_NAME}.elf PRIVATE
    -mmcu=${MCU}
    -Wall
    -Wextra
    -Wpedantic
    -Os
    -ffunction-sections
    -fdata-sections
)
target_link_options(${PROJECT_NAME}.elf PRIVATE
    -mmcu=${MCU}
    -Wl,--gc-sections
)
target_link_libraries(${PROJECT_NAME}.elf PRIVATE led_driver gpio_driver)

add_custom_command(
    TARGET ${PROJECT_NAME}.elf
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex -R .eeprom ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
    COMMAND ${CMAKE_SIZE} --format=avr --mcu=${MCU} ${PROJECT_NAME}.elf
    COMMENT "Generating HEX and printing size"
)
