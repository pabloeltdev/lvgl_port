#include "lvgl_port.h"

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#define TFT_CS 5
#define TFT_DC 19
#define TFT_RST 21
#define TFT_HOR_RES 240
#define TFT_VER_RES 320
#define TFT_COLOR_BYTES 2

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
static uint8_t buf1[TFT_HOR_RES * TFT_VER_RES / 10 * TFT_COLOR_BYTES];

namespace lvgl
{
    uint32_t tick_get_cb(void)
    {
        return millis();
    }

    void flush_cb(lv_display_t * display, const lv_area_t * area, uint8_t * px_map)
    {
        uint16_t * buf16 = (uint16_t *) px_map;
        uint16_t x = area->x1;
        uint16_t y = area->y1;
        uint16_t w = area->x2 - x + 1;
        uint16_t h = area->y2 - y + 1;
        tft.setAddrWindow(x, y, w, h);
        tft.writePixels(buf16, sizeof(buf16));
        lv_display_flush_ready(display);
    }

    void port_setup()
    {
        // Init display
        lv_init();
        tft.init(TFT_HOR_RES, TFT_VER_RES);
        lv_tick_set_cb(xTaskGetTickCount);
        lv_display_t * display1 = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
        lv_display_set_buffers(display1, buf1, NULL, sizeof(buf1), LV_DISPLAY_RENDER_MODE_PARTIAL);
        lv_display_set_flush_cb(display1, flush_cb);
    }

    void vLVGLTimerHandlerTask(void *pvParameters)
    {
        while (1) {
            uint32_t time_till_next = lv_timer_handler();
            if(time_till_next == LV_NO_TIMER_READY) time_till_next = LV_DEF_REFR_PERIOD;
            vTaskDelay(time_till_next / portTICK_PERIOD_MS);
        }
    }
}