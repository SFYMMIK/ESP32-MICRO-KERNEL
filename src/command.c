#include "command.h"
#include <stdio.h>
#include <stdlib.h>

void execute_command(const char *command_name) {
    char command[256];
    snprintf(command, sizeof(command), "/bin/%s", command_name);
    system(command);  // Execute the command
}
