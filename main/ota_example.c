// ------------------------------------------
// This file is property of:
// Brent Nieuwland - brent.nieuwland@student.nhlstenden.com
// Guido Annema - guido.annema@student.nhlstenden.com
// 
// Opdrachtgever - NHL Stenden Hogeschool, Leeuwarden
// ------------------------------------------
// OTA flashing example code
// ------------------------------------------

#include "esp_ota_ops.h"
#include "esp_partition.h"

// <<<<<<<<<<<<<<<<<<<<<<<< function not working, look into finding different code for ota flashing!!
void ota_task(void *pvParameters) {
    // Define variables for OTA
    char TAG = "TEST";
    const esp_partition_t *ota_partition = esp_ota_get_next_update_partition(NULL);
    esp_ota_handle_t ota_handle;
    esp_err_t ota_result = esp_ota_begin(ota_partition, OTA_SIZE_UNKNOWN, &ota_handle);

    // Check for OTA start error
    if (ota_result != ESP_OK) {
        ESP_LOGE(TAG, "OTA begin failed (%s)", esp_err_to_name(ota_result));
        vTaskDelete(NULL);
    }

    // Receive OTA data and write to OTA partition
    while (1) {
        size_t data_len = 0;
        ota_result = esp_ota_write(ota_handle, (const void *)ota_data, data_len);

        if (ota_result != ESP_OK) {
            ESP_LOGE(TAG, "OTA write failed (%s)", esp_err_to_name(ota_result));
            vTaskDelete(NULL);
        }

        // You can add more logic to handle data reception here

        if (data_len == 0) {
            break;  // OTA update complete
        }
    }

    // Finalize the OTA update
    if (esp_ota_end(ota_handle) == ESP_OK) {
        // Set boot partition to the new OTA partition
        ota_result = esp_ota_set_boot_partition(ota_partition);
    }

    if (ota_result != ESP_OK) {
        ESP_LOGE(TAG, "OTA end failed (%s)", esp_err_to_name(ota_result));
    }

    vTaskDelete(NULL);
}