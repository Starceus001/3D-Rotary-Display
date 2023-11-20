// ------------------------------------------
// This file is property of:
// Brent Nieuwland - brent.nieuwland@student.nhlstenden.com
// Guido Annema - guido.annema@student.nhlstenden.com
// 
// Opdrachtgever - NHL Stenden Hogeschool, Leeuwarden
// ------------------------------------------
// Wifi tasks
// ------------------------------------------

#include "task.h"

void wifi_init(void) {
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    wifi_config_t wifi_config = {
        .sta = {
            .ssid = WIFI_SSID,
            .password = WIFI_PASSWORD,
        },
    };

    esp_wifi_init(&cfg);
    esp_wifi_set_storage(WIFI_STORAGE_RAM);
    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_set_config(WIFI_IF_STA, &wifi_config);
    esp_wifi_start();

    // Wait for Wi-Fi to connect
    while (!is_wifi_connected()) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

bool is_wifi_connected(void) {
    wifi_ap_record_t ap_info;
    esp_err_t ret = esp_wifi_sta_get_ap_info(&ap_info);

    return (ret == ESP_OK);
}

const char *get_ip_address(void) {
    tcpip_adapter_ip_info_t ip_info;
    tcpip_adapter_get_ip_info(TCPIP_ADAPTER_IF_STA, &ip_info);
    
    return ip4addr_ntoa(&ip_info.ip);
}