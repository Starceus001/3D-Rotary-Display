// ------------------------------------------
// This file is property of:
// Brent Nieuwland - brent.nieuwland@student.nhlstenden.com
// Guido Annema - guido.annema@student.nhlstenden.com
// 
// Opdrachtgever - NHL Stenden Hogeschool, Leeuwarden
// ------------------------------------------
// HTTP tasks
// ------------------------------------------

#include "task.h"

// init webserver...
void http_init(void) {
    // Start the HTTP server
    httpd_handle_t server = start_webserver();
    if (server == NULL) {
        ESP_LOGE("main", "Failed to start web server");
        // Handle error as needed
    }
}

esp_err_t upload_handler(httpd_req_t *req) {
    char buffer[1024];
    int remaining = req->content_len;

    while (remaining > 0) {
        int received = httpd_req_recv(req, buffer, sizeof(buffer));
        if (received <= 0) {
            if (received == HTTPD_SOCK_ERR_TIMEOUT) {
                httpd_resp_send_500(req);
            }
            return ESP_FAIL;
        }

        // Process received data (e.g., store it in a file)
        // TODO: Implement your file processing logic here      // "TEST" TO DO

        remaining -= received;
    }

    httpd_resp_send(req, "File uploaded successfully", HTTPD_RESP_USE_STRLEN);
    return ESP_OK;
}

httpd_uri_t upload = {
    .uri       = "/upload",
    .method    = HTTP_POST,
    .handler   = upload_handler,
    .user_ctx  = NULL
};

httpd_handle_t start_webserver(void) {
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();

    httpd_handle_t server;
    if (httpd_start(&server, &config) == ESP_OK) {
        httpd_register_uri_handler(server, &upload);
        return server;
    }

    return NULL;
}

void stop_webserver(httpd_handle_t server) {
    httpd_stop(server);
}