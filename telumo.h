#ifndef TELUMO_H
#define TELUMO_H

#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

#include "linked_list.h"
#include "utils.h"

typedef struct TLM_char_map {
    uint h;
    uint w;
    chtype **ptr;
} *TLM_char_map_t;

TLM_char_map_t TLM_char_map_new(uint h, uint w);
void TLM_char_map_free(TLM_char_map_t charMap);

typedef struct TLM_entity {
    int x;
    int y;
    uint layer;
    TLM_char_map_t charMap;
} *TLM_entity_t;

TLM_entity_t TLM_entity_new(int x, int y, uint layer, TLM_char_map_t charMap);
void TLM_entity_free(TLM_entity_t entity);

typedef struct TLM_layer_map {
    uint h;
    uint w;
    uint **ptr;
} *TLM_layer_map_t;

TLM_layer_map_t TLM_layer_map_new(uint h, uint w);
void TLM_layer_map_free(TLM_layer_map_t layerMap);

typedef struct TLM_scene {
    uint h;
    uint w;
    TLM_list_t entities;
    TLM_char_map_t charMap;
    TLM_layer_map_t layerMap;
} *TLM_scene_t;

TLM_scene_t TLM_scene_new(uint h, uint w);

void TLM_render_entity(TLM_char_map_t charMap, TLM_layer_map_t layerMap, TLM_entity_t entity);
void TLM_scene_add_entity(TLM_scene_t scene, TLM_entity_t entity, bool render);
void TLM_scene_render(TLM_scene_t scene);
void TLM_scene_flush(WINDOW *window, TLM_scene_t scene);

#endif //TELUMO_H
