#ifndef TELUMO_H
#define TELUMO_H

#include <stdlib.h>

#include "linked_list.h"

typedef struct TLM_char_map {
    int h;
    int w;
    char **ptr;
} *TLM_char_map_t;

typedef struct TLM_entity {
    int x;
    int y;
    TLM_char_map_t charMap;
} *TLM_entity_t;

TLM_char_map_t TLM_char_map_new(int h, int w);
TLM_entity_t TLM_entity_new(int x, int y, TLM_char_map_t charMap);

#endif //TELUMO_H
