#include "telumo.h"

TLM_char_map_t TLM_char_map_new(int h, int w) {
    TLM_char_map_t this = malloc(sizeof(struct TLM_char_map));
    this->h = h;
    this->w = w;
    this->ptr = calloc(h, sizeof(char*));
    for (int i = 0; i < h; ++i) {
        this->ptr[i] = calloc(w, sizeof(char));
    }
    return this;
}

TLM_entity_t TLM_entity_new(int x, int y, TLM_char_map_t charMap) {
    TLM_entity_t this = malloc(sizeof(struct TLM_entity));
    this->x = x;
    this->y = y;
    this->charMap = charMap;
    return this;
}
