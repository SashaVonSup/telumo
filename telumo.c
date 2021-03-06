#include "telumo.h"

TLM_char_map_t TLM_char_map_new(uint h, uint w) {
    TLM_char_map_t this = malloc(sizeof(struct TLM_char_map));
    this->h = h;
    this->w = w;
    this->ptr = calloc(h, sizeof(chtype *));
    for (int i = 0; i < h; ++i)
        this->ptr[i] = calloc(w, sizeof(chtype));
    return this;
}

void TLM_char_map_free(TLM_char_map_t charMap) {
    for (int i = 0; i < charMap->h; ++i)
        free(charMap->ptr[i]);
    free(charMap->ptr);
    free(charMap);
}

TLM_entity_t TLM_entity_new(int x, int y, uint layer, TLM_char_map_t charMap) {
    TLM_entity_t this = malloc(sizeof(struct TLM_entity));
    this->x = x;
    this->y = y;
    this->layer = layer;
    this->charMap = charMap;
    return this;
}

void TLM_entity_free(TLM_entity_t entity) {
    free(entity);
}

TLM_layer_map_t TLM_layer_map_new(uint h, uint w) {
    TLM_layer_map_t this = malloc(sizeof(struct TLM_char_map));
    this->h = h;
    this->w = w;
    this->ptr = calloc(h, sizeof(uint *));
    for (int i = 0; i < h; ++i) {
        this->ptr[i] = calloc(w, sizeof(uint));
        // memset(this->ptr[i], 0, w * sizeof(uint));
    }
    return this;
}

void TLM_layer_map_free(TLM_layer_map_t layerMap) {
    for (int i = 0; i < layerMap->h; ++i)
        free(layerMap->ptr[i]);
    free(layerMap->ptr);
    free(layerMap);
}

TLM_scene_t TLM_scene_new(uint h, uint w) {
    TLM_scene_t this = malloc(sizeof(struct TLM_scene));
    this->h = h;
    this->w = w;
    this->entities = TLM_list_new();
    this->charMap = TLM_char_map_new(h, w);
    this->layerMap = TLM_layer_map_new(h, w);
    return this;
}

void TLM_scene_free(TLM_scene_t scene) {
    TLM_list_free(scene->entities);
    TLM_char_map_free(scene->charMap);
    TLM_layer_map_free(scene->layerMap);
    free(scene);
}

void TLM_render_entity(TLM_char_map_t charMap, TLM_layer_map_t layerMap, TLM_entity_t entity) {
    uint entity_h = entity->charMap->h, entity_w = entity->charMap->w;
    chtype **scene_charMap = charMap->ptr, **entity_charMap = entity->charMap->ptr, ch;
    uint **scene_layerMap = layerMap->ptr;
    int x = entity->x > 0 ? entity->x : 0, y;
    for (uint i = x - entity->x; i < entity_h && x < charMap->h; ++i, ++x) {
        y = entity->y > 0 ? entity->y : 0;
        for (int j = y - entity->y; j < entity_w && y < charMap->w; ++j, ++y)
            if (scene_layerMap[x][y] < entity->layer) {
                ch = entity_charMap[i][j];
                if(ch) {
                    scene_charMap[x][y] = ch;
                    scene_layerMap[x][y] = entity->layer;
                }
            }
    }
}

void TLM_scene_add_entity(TLM_scene_t scene, TLM_entity_t entity, bool render) {
    TLM_list_push(scene->entities, entity, sizeof(struct TLM_entity));
    if (render)
        TLM_render_entity(scene->charMap, scene->layerMap, entity);
}

void TLM_scene_render(TLM_scene_t scene) {
    TLM_char_map_free(scene->charMap);
    TLM_char_map_t charMap = TLM_char_map_new(scene->h, scene->w);
    scene->charMap = charMap;
    TLM_layer_map_free(scene->layerMap);
    TLM_layer_map_t layerMap = TLM_layer_map_new(scene->h, scene->w);
    scene->layerMap = layerMap;
    for (TLM_list_node_t node = *scene->entities; node != NULL; node = node->next) {
        TLM_render_entity(charMap, layerMap, node->data);
    }
}

void TLM_scene_flush(WINDOW *window, TLM_scene_t scene) {
    chtype *row;
    for (int i = 0; i < scene->h; ++i) {
        wmove(window, i, 0);
        row = scene->charMap->ptr[i];
        for (int j = 0; j < scene->w; ++j)
            waddch(window, row[j] ? row[j] : ' ');
    }
    wmove(window, 0, 0);
    wrefresh(window);
}
