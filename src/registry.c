#include "registry.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void parse_cli_registry(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        // Skip empty lines or lines that start with a comment ('#')
        if (line[0] == '\0' || line[0] == '#') {
            continue;
        }

        // Parse the command in the format:
        // "name of command"==/path/to/command --run --startup
        CommandEntry entry = {0};
        char *delim_pos = strstr(line, "==");
        if (delim_pos != NULL) {
            *delim_pos = '\0';
            strncpy(entry.name, line, sizeof(entry.name));
            strncpy(entry.path, delim_pos + 2, sizeof(entry.path));
        }

        if (strstr(line, "--module")) {
            entry.is_module = 1;
        }
        if (strstr(line, "--startup")) {
            entry.run_at_startup = 1;
        }
        if (strstr(line, "--run")) {
            entry.is_run = 1;
        }

        register_command_or_module(entry);
    }

    fclose(file);
}

void register_command_or_module(CommandEntry entry) {
    if (entry.is_module && entry.run_at_startup) {
        printf("Found module to run at startup: %s\n", entry.name);
        if (strcmp(entry.name, "wifi") == 0) {
            start_wifi_module();
        }
    } else if (!entry.is_module) {
        printf("Found command: %s\n", entry.name);
    }
}
