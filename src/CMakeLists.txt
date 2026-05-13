add_subdirectory(components)

# CMake build : main application

#configure variables

set (MAIN_NAME "${PROJECT_NAME}main")

#configure directories
set (MAIN_MODULE_PATH "${PROJECT_SOURCE_DIR}/src")
set (MAIN_SRC_PATH  "${MAIN_MODULE_PATH}/" )

include_directories (${LIBRARY_INCLUDE_PATH} ${COMPONENTS_INCLUDE_PATH})

file (GLOB MAIN_SOURCE_FILE "${MAIN_SRC_PATH}/main.c")

#set target executable
add_executable (${PROJECT_NAME}.elf ${MAIN_SOURCE_FILE})

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
target_link_libraries(${PROJECT_NAME}.elf ${LIB_NAME} ${COMP_NAME})

add_custom_command(
  TARGET ${PROJECT_NAME}.elf
  POST_BUILD
  COMMAND ${CMAKE_OBJCOPY} -O ihex -R .eeprom ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
  COMMAND ${CMAKE_SIZE} --format=avr --mcu=${MCU} ${PROJECT_NAME}.elf
  COMMENT "Generating HEX and printing size"
)
