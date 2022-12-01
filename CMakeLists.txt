cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

set(project_name serialmic)
project(${project_name})

pico_sdk_init()

add_executable(${project_name}
	main.c
)

pico_enable_stdio_usb(${project_name} 1)
pico_enable_stdio_uart(${project_name} 0)

pico_add_extra_outputs(${project_name})

target_link_libraries(${project_name}
	pico_stdlib
	hardware_pio
	hardware_irq
	hardware_dma
)
