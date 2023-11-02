cmake_minimum_required(VERSION 3.16)

include(../pico_sdk_import.cmake)

project(picoDOSKernel)

pico_sdk_init()

add_executable(picoDOSKernel
    src/main.c
)

target_link_libraries(picoDOSKernel PRIVATE pico_stdlib)

pico_set_linker_script(picoDOSKernel "${CMAKE_CURRENT_LIST_DIR}/memmap_kernel.ld")

pico_enable_stdio_usb(picoDOSKernel 1)
pico_enable_stdio_uart(picoDOSKernel 0)

pico_add_extra_outputs(picoDOSKernel)
