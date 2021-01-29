#include "../telumo.h"
#include <unistd.h>

int main() {
    uint scene_h, scene_w, n_frames, speed;
    printf("Scene height: ");
    scanf("%d", &scene_h);
    printf("Scene width: ");
    scanf("%d", &scene_w);
    printf("# of frames: ");
    scanf("%d", &n_frames);
    printf("Speed: ");
    scanf("%d", &speed);
    int velocity_x = speed, velocity_y = speed;

    TLM_scene_t scene = TLM_scene_new(scene_h, scene_w);
    TLM_char_map_t charMap = TLM_char_map_new(3, 3);
    char *s = "\0o\0/|\\/\0\\";
    charMap->ptr = TLM_string_to_chtype_table(s, 3, 3);
    free(s);
    TLM_entity_t entity = TLM_entity_new(0, 0, 1, charMap);
    TLM_scene_add_entity(scene, entity, false);
    TLM_entity_free(entity);
    entity = (*scene->entities)->data;

    initscr();
    move(0, 0);
    curs_set(0);

    for (uint frame = 0; frame < n_frames; ++frame) {
        entity->x += velocity_x;
        entity->y += velocity_y;

        if (entity->x <= 0 || entity->x + charMap->h >= scene_h)
            velocity_x = -velocity_x;
        if (entity->y <= 0 || entity->y + charMap->w >= scene_w)
            velocity_y = -velocity_y;

        TLM_scene_render(scene);
        TLM_scene_flush(stdscr, scene);
        sleep(1);
    }

    TLM_char_map_free(entity->charMap);
    TLM_scene_free(scene);
    endwin();
    return 0;
}
