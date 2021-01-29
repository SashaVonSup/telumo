#include "utils.h"

chtype **TLM_string_to_chtype_table(char *s, uint h, uint w) {
    chtype **ptr = calloc(h, sizeof(chtype *));
    uint n = h * w;
    chtype *new_s = calloc(n, sizeof(chtype));
    for (int i = 0; i < n; ++i, ++s)
        new_s[i] = (chtype)*s;
    for (int i = 0; i < h; ++i, new_s += w)
        ptr[i] = new_s;
    return ptr;
}
