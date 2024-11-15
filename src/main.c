#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_sleep.h"

void app_main() {
    printf("ESP32 Micro-Kernel started.\n");

    // Initialize system (e.g., CLI, etc.)

    // The "off" command will trigger deep sleep
    while (1) {
        char command[100];
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);

        // Check if the command is "off"
        if (strncmp(command, "off", 3) == 0) {
            printf("Shutting down the kernel and ESP32...\n");
            // Put the ESP32 into deep sleep for a long time (essentially "off")
            esp_sleep_enable_timer_wakeup(1000000);  // Sleep for 1 second before going to deep sleep
            esp_deep_sleep_start();  // Enter deep sleep
        }

        // Handle other commands as usual
    }
}
