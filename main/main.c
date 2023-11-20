// ------------------------------------------
// This file is property of:
// Brent Nieuwland - brent.nieuwland@student.nhlstenden.com
// Guido Annema - guido.annema@student.nhlstenden.com
// 
// Opdrachtgever - NHL Stenden Hogeschool, Leeuwarden
// ------------------------------------------
// Main
// ------------------------------------------

#include "main.h"
#include "task.h"

void app_main(void)
{
    // context
    ESP_LOGI("MAIN", "Start init main");

    // start wifi
    wifi_init();

    // start web-server
    http_init();
    
    // init ota flashing
    ota_init();

    // main code to run constantly
    while(1) {
        ESP_LOGI("TEST", "Printing in main loop!");
        vTaskDelay(100);

        // extend with further infinitely looped main functions...
    }
}