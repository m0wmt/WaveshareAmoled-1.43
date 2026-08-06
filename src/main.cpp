#include <Arduino.h>
#include "esp32_s3_touch_amoled_1.43c.h"
#include <lvgl.h>
#include <demos/lv_demos.h>

#define BACKLIGHT_EN 1

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.printf("lvgl-example run\n");
  bsp_broolesia_display_init();
  if (bsp_display_lock(-1) == ESP_OK) {
    //lv_demo_widgets();

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

    // static long last_time = millis();

    // if (millis() - last_time > 5) {
    //     last_time = millis();
    //     lv_timer_handler(); // Call lvgl's timer handler
    //     lv_tick_inc(5);     // Update lvgl's tick
    // }
}