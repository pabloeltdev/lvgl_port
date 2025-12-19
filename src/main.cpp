#include <Arduino.h>

#include "lvgl.h"
#include "lvgl_port.h"

void setup() {
    lvgl::port_setup();
    lv_obj_set_size(lv_screen_active(), 240, 320);
    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x0000FF), LV_PART_MAIN); // Tela Azul
    lv_obj_t * label = lv_label_create(lv_screen_active());
    lv_label_set_text(label, "Hello LVGL!");
}

void loop() {
  lv_task_handler();
  delay(5);
}
