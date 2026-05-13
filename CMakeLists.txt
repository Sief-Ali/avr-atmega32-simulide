cmake_minimum_required(VERSION 3.16)

# Configure CMake for bare-metal AVR cross-compilation.
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_OBJCOPY avr-objcopy)
set(CMAKE_SIZE avr-size)

project(avr-atmega32-simulide C)

set_property (GLOBAL PROPERTY USE_FOLDERS ON)

set(MCU atmega32 CACHE STRING "Target AVR MCU")
set(F_CPU 16000000UL CACHE STRING "CPU frequency in Hz")
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(libs)
add_subdirectory(src)

