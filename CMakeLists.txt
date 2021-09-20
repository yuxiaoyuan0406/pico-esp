# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/dennis/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico-esp C CXX ASM)

set(PICO_CXX_ENABLE_EXCEPTIONS 1)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(pico-esp pico-esp.cpp esp8266.cpp)

include_directories(./)

pico_set_program_name(pico-esp "pico-esp")
pico_set_program_version(pico-esp "0.1")

pico_enable_stdio_uart(pico-esp 1)
pico_enable_stdio_usb(pico-esp 0)

# Add the standard library to the build
target_link_libraries(pico-esp pico_stdlib)

pico_add_extra_outputs(pico-esp)

