# Waveshare ESP32-S3 AMOLED 1.43"

Project using the Waveshare round AMOLED 1.43” display.

- Product information: https://www.waveshare.com/esp32-s3-touch-amoled-1.43.htm
- Waveshare wiki: https://www.waveshare.com/wiki/ESP32-S3-Touch-AMOLED-1.43

## LVGL example code

I haven't used LVGL before so I'm collecting a list of pages with examples to work through to see what works for me!

- Waveshare examples using LVGL: https://github.com/waveshareteam/ESP32-S3-Touch-AMOLED-1.43C
- LVGL/Platformio Documentation: https://registry.platformio.org/libraries/lvgl/lvgl
- https://github.com/waveshareteam/ESP32-S3-Touch-AMOLED-1.43C/tree/main/02_Example/arduino_v3.3.0/06_LVGL_V9_Test
- Audio test, might be able to use boot button as a button??  https://github.com/waveshareteam/ESP32-S3-Touch-AMOLED-1.43C/tree/main/02_Example/arduino_v3.3.0/04_Audio_Test
- https://github.com/beniseman/PIO-Waveshare-ESP32-S3-1.43-Amoled-Touch
- https://github.com/market-viewer/firmware
- https://www.instructables.com/Design-Watch-Face-With-LVGL/
- https://github.com/fbiego/esp32-c3-mini

## Project Goals

This project will use **PlatformIO** toolset for development and **LVGL** for the graphics.

The goal of this repository is to demonstrate features or applications:
- Bring the board up cleanly in **PlatformIO**
- Initialize the AMOLED display (SH8601 / CO5300)
- Enable **LVGL (v9.x)** rendering
- Enable **FT3168 capacitive touch**
- Enable **buttons** for user actions
- Serve as a stable foundation for future projects

Display ideas:
- Aircraft tracker/radar
- Home solar information
- ISS location
- Home Bindicator information
- Local/Other Weather
- Planet locations (space)
- Nice clock
- Customisation (brightness, colours etc.)



## Hardware

- **Board:** Waveshare ESP32-S3 Touch AMOLED 1.43"
- **Display:** AMOLED (SH8601 / CO5300)
- **Touch Controller:** FT3168
- **Interface:** QSPI (display), I²C (touch)



## Software Stack

- **PlatformIO**
- **Arduino framework (ESP32-S3)**
- **LVGL 9.x**
- **Waveshare-provided BSP + drivers**

