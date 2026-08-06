# Waveshare ESP32-S3 AMOLED 1.43" – PlatformIO

Project using the Waveshare round AMOLED 1.43” display

Product information: https://www.waveshare.com/esp32-s3-touch-amoled-1.43.htm

https://www.waveshare.com/wiki/ESP32-S3-Touch-AMOLED-1.43

Waveshare examples using LVGL: https://github.com/waveshareteam/ESP32-S3-Touch-AMOLED-1.43C

https://github.com/waveshareteam/ESP32-S3-Touch-AMOLED-1.43C/tree/main/02_Example/arduino_v3.3.0/06_LVGL_V9_Test

Audio test, might be able to use boot button as a button??  https://github.com/waveshareteam/ESP32-S3-Touch-AMOLED-1.43C/tree/main/02_Example/arduino_v3.3.0/04_Audio_Test

See: https://github.com/beniseman/PIO-Waveshare-ESP32-S3-1.43-Amoled-Touch

LVGL/Platformio Documentation: https://registry.platformio.org/libraries/lvgl/lvgl


This project provides a **minimal, working PlatformIO setup** for the **Waveshare ESP32-S3 1.43" AMOLED Touch Display**.

The goal of this repository is **not** to demonstrate features or applications, but simply to:

- Bring the board up cleanly in **PlatformIO**
- Initialize the AMOLED display (SH8601 / CO5300)
- Enable **LVGL (v9.x)** rendering
- Enable **FT3168 capacitive touch**
- Serve as a stable foundation for future projects

---

## Hardware

- **Board:** Waveshare ESP32-S3 Touch AMOLED 1.43"
- **Display:** AMOLED (SH8601 / CO5300)
- **Touch Controller:** FT3168
- **Interface:** QSPI (display), I²C (touch)

---

## Software Stack

- **PlatformIO**
- **Arduino framework (ESP32-S3)**
- **LVGL 9.x**
- **Waveshare-provided BSP + drivers**

This project intentionally uses the **Waveshare driver and LVGL files directly**, rather than relying on external LVGL display libraries, to avoid artifacts and timing issues.

---

