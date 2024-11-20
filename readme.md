# little readme update
i dont have a ESP32 micro controller to tedt this on so if anyone can pls test this and submit issues


# ESP32 Micro-Kernel Project

This is a simple micro-kernel for the ESP32 that includes basic Wi-Fi functionality, display handling, and a CLI-based interface for managing commands like connecting to Wi-Fi and displaying text on a screen.

## Features

- **Wi-Fi Management**: You can connect to Wi-Fi and disconnect it using CLI commands.
- **Display Handling**: Prints messages on the display (customizable for different displays).
- **CLI Commands**:
  - **`wifi-on`**: Connect to Wi-Fi with an SSID and optional password.
  - **`wifi-off`**: Disconnect from the Wi-Fi network.

## How to Use

1. **Connect to Wi-Fi**:
   - Use the command: `wifi-on "SSID" "Password"`
   - If no password is required, simply omit the password: `wifi-on "SSID"`

2. **Disconnect from Wi-Fi**:
   - Use the command: `wifi-off`

3. **Build the project**:
   - Run `make` to compile the kernel and all modules.

4. **Upload the compiled binary and SPIFFS to your ESP32**:
   - Use the appropriate tool (e.g., `esptool.py` or PlatformIO) to upload the compiled files to the ESP32.

5. **Run the kernel**:
   - Once flashed, you can interact with the kernel through a serial terminal.

## Dependencies

- **ESP-IDF**: ESP32 development framework.
- **PlatformIO**: Optional for easier flashing and project management.

## License

This project is licensed under the BSD-3 License.
