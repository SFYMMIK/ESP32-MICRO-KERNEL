# Makefile for ESP32 Micro-Kernel Project

# Project settings
PROJECT_NAME := esp32-micro-kernel
SRC_DIR := src
OBJ_DIR := build
SPIFS_DIR := spiffs
INCLUDE_DIRS := $(SRC_DIR)

# Compiler settings
CC := xtensa-esp32-elf-gcc
CFLAGS := -I$(INCLUDE_DIRS) -nostdlib -Wall -Werror
LDFLAGS := -lm

# List of source files
SOURCES := $(SRC_DIR)/main.c $(SRC_DIR)/editor.c $(SRC_DIR)/registry.c \
           $(SRC_DIR)/command.c $(SRC_DIR)/startup.c $(SRC_DIR)/display.c \
           $(SRC_DIR)/wifi.c $(SRC_DIR)/compiler.c

# Object files
OBJ_FILES := $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target: build the project
all: $(OBJ_DIR)/$(PROJECT_NAME).elf

# Rule for compiling source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into an ELF binary
$(OBJ_DIR)/$(PROJECT_NAME).elf: $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(LDFLAGS) -o $@

# Upload the compiled files to the ESP32 SPIFFS filesystem (manually placed files)
upload_spiffs:
	# Upload files from the spiffs/ directory using esptool or platformio
	# Make sure your compiled modules (e.g., hello_world) are placed in the spiffs/ directory manually
	# Example: Using esptool to upload to SPIFFS
	# esptool.py --port /dev/ttyUSB0 write_flash 0x110000 spiffs/hello_world
	# Alternatively, use platformio or other ESP32 flashing tools

# Rule to clean the build directory and spiffs folder
clean:
	rm -rf $(OBJ_DIR) $(SPIFS_DIR)/*
