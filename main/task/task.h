// ------------------------------------------
// This file is property of:
// Brent Nieuwland - brent.nieuwland@student.nhlstenden.com
// Guido Annema - guido.annema@student.nhlstenden.com
// 
// Opdrachtgever - NHL Stenden Hogeschool, Leeuwarden
// ------------------------------------------
// Tasks header
// ------------------------------------------

#ifndef TASK_H
#define TASK_H

// #include <stdio.h>
#include <esp_event.h>
#include <esp_http_server.h>
#include <esp_https_ota.h>
#include <freertos/event_groups.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_err.h>
#include <esp_log.h>
#include <esp_wifi.h>           // "TEST" TO DO
#include <tcpip_adapter.h>      // "TEST" TO DO

extern esp_err_t ota_init(void *pvParameter);

extern void http_init(void);

extern void wifi_init(void);

extern bool is_wifi_connected(void);

extern const char *get_ip_address(void);

#endif  // TASK_H