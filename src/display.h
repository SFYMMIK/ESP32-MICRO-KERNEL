#ifndef DISPLAY_H
#define DISPLAY_H

#include "esp_err.h"

// Function prototypes
esp_err_t display_init();
void display_print(const char *text);

#endif // DISPLAY_H
