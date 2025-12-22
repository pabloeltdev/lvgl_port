#include "lvgl_port.hpp"
#include <SPI.h>

#define TFT_COLOR_BYTES (LV_COLOR_DEPTH / 8)
#define LVGL_BUF_SIZE TFT_WIDTH * TFT_HEIGHT / 10 * TFT_COLOR_BYTES

uint8_t buf[LVGL_BUF_SIZE];

namespace lvgl
{

    uint32_t tick_get_cb(void)
    {
        return millis();
    }

    void port_setup()
    {
        lv_init();
        lv_tick_set_cb(tick_get_cb);
        lv_display_t *display = lv_tft_espi_create(TFT_WIDTH, TFT_HEIGHT, buf, LVGL_BUF_SIZE);
        lv_disp_set_rotation(display, LV_DISP_ROTATION_180);
    }
}