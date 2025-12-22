#include <Arduino.h>

#include "lvgl.h"
#include "lvgl_port.hpp"
#include "assets/splash.h"
#include "ui/ui.h"

static lv_obj_t * slider_label;
// LV_FONT_DECLARE(&roboto_32);

static void slider_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target_obj(e);
    char buf[8];
    lv_snprintf(buf, sizeof(buf), "%.2f ml/h", 1 + 4*lv_slider_get_value(slider)/100);
    lv_label_set_text(slider_label, buf);
    lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
}

void setup() {
    lvgl::port_setup();
    // ui_init();
    ///* //    ---> Splash Screen
    lv_obj_t * img1 = lv_image_create(lv_screen_active());
    lv_image_set_src(img1, &img_splash_screen);
    lv_obj_t * spinner = lv_spinner_create(lv_screen_active());
    lv_obj_set_size(spinner, 50, 50);
    lv_obj_align(spinner, LV_ALIGN_BOTTOM_MID, 0, -30);
    lv_spinner_set_anim_params(spinner, 10000, 200);
    /* //    ---> Rate control Screen
    static lv_obj_t * info_label = lv_label_create(lv_screen_active());
    lv_label_set_text(info_label, "Defina a taxa de infusão çç");
    lv_obj_set_style_text_font(info_label, &roboto_32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_t * slider = lv_slider_create(lv_screen_active());
    lv_obj_set_width(slider, 200);
    lv_obj_center(slider);
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_set_style_anim_duration(slider, 2000, 0);
    slider_label = lv_label_create(lv_screen_active());
    lv_label_set_text(slider_label, "1 ml/h");
    lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    //*/
  
}

void loop() {
  lv_task_handler();
  // ui_tick();
  delay(3);
}
