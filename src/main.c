#include "lvgl/lvgl.h"
#include "ui/inTeRface.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

static void lv_linux_disp_init(void)
{
    const int width = atoi(getenv("LV_SDL_VIDEO_WIDTH") ? : "800");
    const int height = atoi(getenv("LV_SDL_VIDEO_HEIGHT") ? : "480");
    lv_sdl_window_create(width, height);
    lv_sdl_mouse_create();
}


int main(char* argc, char** argv){
   lv_init();

    /*Linux display device init*/
    lv_linux_disp_init();
    inTeRface_init();
    /*Handle LVGL tasks*/
    while(1) {
        lv_timer_handler();
        usleep(5000);
    }

return 0;
}
