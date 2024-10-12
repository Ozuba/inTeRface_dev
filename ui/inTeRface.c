#include "inTeRface.h"


static void event_handler(lv_event_t * e) {
    lv_obj_t *btn = lv_event_get_target(e);
    lv_label_set_text(lv_obj_get_child(btn, 0), "Clicked!");
}


void inTeRface_init(){
 // Create a screen
    lv_obj_t *scr = lv_obj_create(NULL);
    lv_scr_load(scr);

    // Create a button
    lv_obj_t *btn = lv_btn_create(scr);
    lv_obj_set_pos(btn, 100, 100);
    lv_obj_set_size(btn, 120, 50);
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);

    // Create a label on the button
    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, "Click me!");
    lv_obj_center(label);

}
