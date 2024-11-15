#ifndef WIFI_H
#define WIFI_H

#include "esp_err.h"

esp_err_t wifi_init();
esp_err_t wifi_connect(const char *ssid, const char *password);
esp_err_t wifi_disconnect();

// Command handlers
void wifi_on_command(char *ssid, char *password);
void wifi_off_command();

#endif // WIFI_H
