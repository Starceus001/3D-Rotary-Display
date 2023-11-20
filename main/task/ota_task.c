// ------------------------------------------
// This file is property of:
// Brent Nieuwland - brent.nieuwland@student.nhlstenden.com
// Guido Annema - guido.annema@student.nhlstenden.com
// 
// Opdrachtgever - NHL Stenden Hogeschool, Leeuwarden
// ------------------------------------------
// OTA tasks
// ------------------------------------------

#include "task.h"

#define OTA_UPDATE_URL "https://your-server.com/path/to/firmware.bin"  // Replace with your firmware URL    // "TEST" TO DO
#define TAG "OTA"

esp_err_t ota_init(void *pvParameter) {
    // context
    ESP_LOGI("TAG", "Start init ota flashing");

    esp_http_client_config_t config = {
        .url = OTA_UPDATE_URL,
    };

    esp_https_ota_handle_t ota_handle;  // Declare the handle

    esp_https_ota_handle_t ota_handle = esp_https_ota_begin(&config, &ota_handle);

    if (ota_handle == NULL) {
        ESP_LOGE(TAG, "Failed to begin OTA");
        vTaskDelete(NULL);
    }

    esp_err_t err = esp_https_ota_perform(ota_handle);

    if (err == ESP_OK) {
        esp_https_ota_finish(ota_handle);
        ESP_LOGI(TAG, "OTA update succeeded");
    } else {
        esp_https_ota_abort(ota_handle);
        ESP_LOGE(TAG, "OTA update failed");
    }

    vTaskDelete(NULL);
}