// Waveshare ESP32-S3 1.43inch AMOLED Display Development Board, 466×466, QSPI


/*
Notes from nikthefix 

This build uses a lean SH8601 display driver rather than the Waveshare Espressif driver and support files.
The driver files are supplied in the sketch directory so no installation is required.
The touch driver is also included in the sketch directory so no installation is required.
I recommend a clean LVGL install via the Arduino library manager and perhaps a clean lv_conf.h with the following modifications:

Please set in lv_conf.h:  --->   #if 1                                  (line 15)
                          --->   #define LV_COLOR_16_SWAP 1             (line 30) _swap not available
                          --->   #define LV_MEM_CUSTOM 1                (line 49) not available
                          --->   #define LV_TICK_CUSTOM 1               (line 88) not available
                          --->   #define LV_FONT_MONTSERRAT_14 1        (line 367)

                          A copy of my lv_conf.h file is provided.

Set display brightness in setup() ---> lcd_brightness(200); // 0-255
Set display orientation in setup() ---> disp_drv.sw_rotate = 1;  disp_drv.rotated = LV_DISP_ROT_XXX; (Options: LV_DISP_ROT_90, LV_DISP_ROT_180, LV_DISP_ROT_270)

Build options:
    Select board ESP32S3 Dev Module
    Select USB CDC On Boot "Enabled"
    Select Flash Size 16M
    Select Partition Scheme "custom" - partitions.csv in sketch folder will be used
    Select PSRAM "OPI PSRAM"
*/


#include <Arduino.h>
#include "esp32_s3_touch_amoled_1.43c.h"
#include "lvgl.h"
#include "externLib/esp_lcd_sh8601.h"
#include "pins_config.h"

#define BACKLIGHT_EN 1

// My added code

#define ENABLE_RENDER_DIAGNOSTICS 0

#if ENABLE_RENDER_DIAGNOSTICS
void lvgl_log_print(const char *message)
{
    Serial.print("[lvgl] ");
    Serial.print(message);
}

uint32_t count_non_black_pixels(const lv_color_t *frame)
{
    if (frame == nullptr) return 0;

    const lv_color_t black = lv_color_black();
    uint32_t count = 0;
    for (uint32_t i = 0; i < LCD_WIDTH * LCD_HEIGHT; ++i) {
        if (frame[i].full != black.full) ++count;
    }
    return count;
}

void print_frame_diagnostics(const char *stage)
{
    Serial.printf(
        "[render] %s: static=%lu, composited=%lu, flushes=%lu, pixels=%lu, free_psram=%lu\n",
        stage,
        (unsigned long)count_non_black_pixels(static_frame),
        (unsigned long)count_non_black_pixels(composited_frame),
        (unsigned long)diagnostic_flush_count,
        (unsigned long)diagnostic_flush_pixels,
        (unsigned long)ESP.getFreePsram());
}
#endif


// End of my added code!



static void my_flush_cb(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map)
{
    /*Write px_map to the area->x1, area->x2, area->y1, area->y2 area of the
     *frame buffer or external display controller. */
}

void setup() {
    Serial.begin(115200);
    delay(2000);

    Serial.println("\n##################################");
    Serial.println(F("ESP32 Information:"));
    Serial.printf("Internal Total Heap %d, Internal Used Heap %d, Internal Free Heap %d\n", ESP.getHeapSize(),
    ESP.getHeapSize()-ESP.getFreeHeap(), ESP.getFreeHeap()); Serial.printf("Sketch Size %d, Free Sketch Space %d\n",
    ESP.getSketchSize(), ESP.getFreeSketchSpace()); Serial.printf("SPIRam Total heap %d, SPIRam Free Heap %d\n",
    ESP.getPsramSize(), ESP.getFreePsram()); Serial.printf("Chip Model %s, ChipRevision %d, Cpu Freq %d, SDK Version %s\n", ESP.getChipModel(), ESP.getChipRevision(), ESP.getCpuFreqMHz(), ESP.getSdkVersion()); 
    Serial.printf("Flash Size %d, Flash Speed %d\n", ESP.getFlashChipSize(), ESP.getFlashChipSpeed());
    Serial.println("##################################\n");

    /**
        esptool v5.3.0
        Connected to ESP32-S3 on /dev/ttyACM1:
        Chip type:          ESP32-S3 (QFN56) (revision v0.2)
        Features:           Wi-Fi, BT 5 (LE), Dual Core + LP Core, 240MHz, Embedded PSRAM 8MB (AP_3v3)
        Crystal frequency:  40MHz
        USB mode:           USB-Serial/JTAG
        MAC:                a4:cb:8f:d6:96:d8
    */


    Serial.printf("lvgl-example run\n");
    /*Initialize the display*/
    pinMode(LCD_VCI_EN, OUTPUT);
    digitalWrite(LCD_VCI_EN, HIGH);


     bsp_broolesia_display_init();

// #if ENABLE_RENDER_DIAGNOSTICS
//     lv_log_register_print_cb(lvgl_log_print);
// #endif  

    if (bsp_display_lock(-1) == ESP_OK) {
        //lv_demo_widgets();
        Serial.printf("Display init ok\n");

        lv_obj_t * screen = lv_screen_active();
        lv_obj_set_style_bg_color(screen, lv_color_hex(0x003a57), 0);
        lv_obj_set_style_text_color(screen, lv_color_hex(0xffffff), 0);

        lv_obj_t * label = lv_label_create(screen);
        lv_obj_set_align(label, LV_ALIGN_CENTER);
        lv_label_set_text(label, "Hello world");

        bsp_display_unlock();
    }

}

int8_t brightness = 100;

void loop() {
#if (BACKLIGHT_EN)
    if (brightness < 0) {
        brightness = 100;
    }

    if (bsp_display_lock(-1) == ESP_OK) {
        bsp_display_brightness_set(brightness);
        bsp_display_unlock();
    }

    vTaskDelay(pdMS_TO_TICKS(2000));
    brightness -= 25;
#endif

    static long last_time = millis();

    if (millis() - last_time > 5) {
        last_time = millis();
        lv_timer_handler(); // Call lvgl's timer handler
        lv_tick_inc(5);     // Update lvgl's tick
    }
}