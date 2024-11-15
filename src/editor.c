#include "editor.h"
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LEN 256

void write_to_file(const char *filename, const char *text) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return;
    }
    fputs(text, file);
    fclose(file);
}

void open_file_and_edit(const char *filename) {
    char input[MAX_INPUT_LEN];
    printf("Editing %s (type 'save' to save and 'exit' to quit):\n", filename);

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "save", 4) == 0) {
            write_to_file(filename, input);
            printf("File saved.\n");
        } else if (strncmp(input, "exit", 4) == 0) {
            break;
        } else {
            write_to_file(filename, input);
        }
    }
}
