#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *splash;
    lv_obj_t *first;
    lv_obj_t *infusion;
    lv_obj_t *loading_spinner;
    lv_obj_t *content;
    lv_obj_t *options;
    lv_obj_t *btn_rate;
    lv_obj_t *btn_volume;
    lv_obj_t *input_rate;
    lv_obj_t *input_volume_total_2;
    lv_obj_t *spin_volume_total_1;
    lv_obj_t *input_volume_total_3;
    lv_obj_t *spin_volume_time_2;
    lv_obj_t *spin_volume_time_3;
    lv_obj_t *input_volume;
    lv_obj_t *input_volume_total;
    lv_obj_t *spin_volume_total;
    lv_obj_t *input_volume_total_1;
    lv_obj_t *spin_volume_time;
    lv_obj_t *spin_volume_time_1;
    lv_obj_t *btn_ok;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_SPLASH = 1,
    SCREEN_ID_FIRST = 2,
    SCREEN_ID_INFUSION = 3,
};

void create_screen_splash();
void tick_screen_splash();

void create_screen_first();
void tick_screen_first();

void create_screen_infusion();
void tick_screen_infusion();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/