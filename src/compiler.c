#include "compiler.h"
#include <stdio.h>
#include <stdlib.h>

int compile_module(const char *source_file, const char *output_file) {
    char command[512];
    snprintf(command, sizeof(command), "gcc -o %s %s", output_file, source_file);
    return system(command);  // Execute the system command to compile the module
}
