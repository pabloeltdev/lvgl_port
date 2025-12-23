#include "lvgl_port.hpp"

#include "lv_port_indev.h"

#define TFT_COLOR_BYTES (LV_COLOR_DEPTH / 8)
#define LVGL_BUF_SIZE TFT_WIDTH * TFT_HEIGHT / 10 * TFT_COLOR_BYTES

uint8_t buf[LVGL_BUF_SIZE];

namespace lvgl
{

    uint32_t tick_get_cb(void)
    {
        return millis();
    }

    void indev_read_cb(lv_indev_t * indev, lv_indev_data_t * data) {

    }

    void port_setup()
    {
        lv_init();
        lv_tick_set_cb(tick_get_cb);
        lv_display_t *display = lv_tft_espi_create(TFT_WIDTH, TFT_HEIGHT, buf, LVGL_BUF_SIZE);
        lv_disp_set_rotation(display, LV_DISP_ROTATION_180);
        lv_indev_t * indev = lv_indev_create();
        lv_indev_set_type(indev, LV_INDEV_TYPE_BUTTON);
        lv_indev_set_read_cb(indev, indev_read_cb);
        lv_port_indev_init();
    }
}