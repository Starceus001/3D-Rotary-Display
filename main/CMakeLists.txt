idf_component_register(SRCS "main.c"
                            "task/ota_task.c"
                            "task/http_task.c"
                            "task/wifi_task.c"
                       INCLUDE_DIRS "." "task"
                       REQUIRES freertos soc esp_common esp_event esp_http_server esp_https_ota mbedtls
)