#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 240, 320);
    {
        lv_obj_t *parent_obj = obj;
        {
            // info_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.info_label = obj;
            lv_obj_set_pos(obj, 16, 29);
            lv_obj_set_size(obj, 209, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_roboto_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Defina a taxa de infusão:");
        }
        {
            lv_obj_t *obj = lv_slider_create(parent_obj);
            lv_obj_set_pos(obj, 16, 139);
            lv_obj_set_size(obj, 209, 13);
            lv_slider_set_value(obj, 25, LV_ANIM_OFF);
        }
        {
            // rate_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.rate_label = obj;
            lv_obj_set_pos(obj, 16, 169);
            lv_obj_set_size(obj, 209, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_roboto_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "5 ml/h");
        }
        {
            lv_obj_t *obj = lv_buttonmatrix_create(parent_obj);
            lv_obj_set_pos(obj, 16, 241);
            lv_obj_set_size(obj, 209, 66);
            static const char *map[3] = {
                "VOLTAR",
                "OK",
                NULL,
            };
            lv_buttonmatrix_set_map(obj, map);
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}

void create_screen_teste() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.teste = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 240, 320);
    
    tick_screen_teste();
}

void tick_screen_teste() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_teste,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_teste();
}
