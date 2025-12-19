#include "lvgl_port.h"

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS 5
#define TFT_DC 19
#define TFT_RST 21

#define TFT_HOR_RES 240
#define TFT_VER_RES 320
#define TFT_COLOR_BYTES (LV_COLOR_DEPTH / 8)
#define LVGL_BUF_SIZE TFT_HOR_RES * TFT_VER_RES / 10 * TFT_COLOR_BYTES

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
uint8_t buf[LVGL_BUF_SIZE];

namespace lvgl
{
    void driver_init()
    {
        SPI.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);
        tft.init(TFT_HOR_RES, TFT_VER_RES);
        tft.fillScreen(ST77XX_BLACK);
    }

    uint32_t tick_get_cb(void)
    {
        return millis();
    }

    void flush_cb(lv_display_t *display, const lv_area_t *area, uint8_t *px_map)
    {
        uint16_t *buf16 = (uint16_t *)px_map;
        uint16_t x = area->x1;
        uint16_t y = area->y1;
        uint16_t w = area->x2 - x + 1;
        uint16_t h = area->y2 - y + 1;
        tft.startWrite();
        tft.setAddrWindow(x, y, w, h);
        tft.writePixels(buf16, LVGL_BUF_SIZE / 2, true);
        lv_display_flush_ready(display);
        tft.endWrite();
    }

    void port_setup()
    {
        driver_init();
        lv_init();
        lv_tick_set_cb(tick_get_cb);
        lv_display_t *display = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
        lv_display_set_buffers(display, buf, NULL, LVGL_BUF_SIZE, LV_DISPLAY_RENDER_MODE_PARTIAL);
        lv_display_set_flush_cb(display, flush_cb);
    }
}