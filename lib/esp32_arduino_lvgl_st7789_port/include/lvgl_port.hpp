#if !defined(LVGL_PORT_H)
#define LVGL_PORT_H

#include <Arduino.h>
#include <lvgl.h>

namespace lvgl {
    void port_setup();
    void vLVGLTimerHandlerTask(void *pvParameters);
}


#endif // LVGL_PORT_H
