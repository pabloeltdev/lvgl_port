#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "lvgl_port.h"

void setup() {
    // Init all
    lvgl::port_setup();

    // Create tasks
    xTaskCreate(
        lvgl::vLVGLTimerHandlerTask,
        "LVGL Timer handler",
        2048,
        NULL,
        1,
        NULL
    );
}

void loop() {
}
