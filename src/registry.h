#ifndef REGISTRY_H
#define REGISTRY_H

// Struct to hold command/module information
typedef struct {
    char name[256];
    char path[256];
    int is_run;         // Is this a command to run?
    int is_module;      // Is this a module?
    int run_at_startup; // Should it run at startup?
} CommandEntry;

// Function to parse the CLI-REGISTRY.cfg file
void parse_cli_registry(const char *filename);

// Function to register commands and modules
void register_command_or_module(CommandEntry entry);

#endif // REGISTRY_H
