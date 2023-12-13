# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
cmake_minimum_required(VERSION 3.5)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

project(3d-rotary-display)

idf_component_register(SRCS "main.c"
                            "ota_task.c"
                            "http_task.c"
                            "wifi_task.c"
                       INCLUDE_DIRS "include"
                       REQUIRES freertos soc esp_common esp_event esp_http_server esp_https_ota mbedtls
)

# Additional components for HTTPD
set(EXTRA_COMPONENT_DIRS $ENV{IDF_PATH}/components/esp_http_server)
set(CONFIG_HTTPD_MAX_URI_HANDLERS 8)

# Additional components for OTA
set(EXTRA_COMPONENT_DIRS $ENV{IDF_PATH}/components/esp_https_ota)

# Enable PSRAM support if needed
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-T\"$ENV{IDF_PATH}/components/esp8266/ld/eagle.app.v6.new.1024.app1.ld\"")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--print-memory-usage")