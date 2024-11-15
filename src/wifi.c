#include <stdio.h>
#include <string.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "wifi.h"

#define WIFI_SSID_MAX_LEN 32
#define WIFI_PASS_MAX_LEN 64

static const char *TAG = "wifi";

// Function to initialize Wi-Fi
esp_err_t wifi_init() {
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    return ESP_OK;
}

// Function to connect to Wi-Fi
esp_err_t wifi_connect(const char *ssid, const char *password) {
    wifi_config_t wifi_config = {
        .sta = {
            .ssid = "",
            .password = ""
        },
    };

    strncpy((char*)wifi_config.sta.ssid, ssid, WIFI_SSID_MAX_LEN);
    if (password != NULL && strlen(password) > 0) {
        strncpy((char*)wifi_config.sta.password, password, WIFI_PASS_MAX_LEN);
    }

    ESP_LOGI(TAG, "Connecting to Wi-Fi network: %s", ssid);

    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());

    // Wait for connection to complete
    esp_wifi_connect();
    return ESP_OK;
}

// Function to disconnect Wi-Fi
esp_err_t wifi_disconnect() {
    ESP_LOGI(TAG, "Disconnecting from Wi-Fi");
    ESP_ERROR_CHECK(esp_wifi_stop());
    ESP_ERROR_CHECK(esp_wifi_deinit());
    return ESP_OK;
}

// Command handler for 'wifi-on' command
void wifi_on_command(char *ssid, char *password) {
    if (wifi_init() != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize Wi-Fi");
        return;
    }

    if (wifi_connect(ssid, password) == ESP_OK) {
        ESP_LOGI(TAG, "Connected to Wi-Fi network: %s", ssid);
    } else {
        ESP_LOGE(TAG, "Failed to connect to Wi-Fi network: %s", ssid);
    }
}

// Command handler for 'wifi-off' command
void wifi_off_command() {
    if (wifi_disconnect() == ESP_OK) {
        ESP_LOGI(TAG, "Wi-Fi disconnected successfully");
    } else {
        ESP_LOGE(TAG, "Failed to disconnect Wi-Fi");
    }
}
