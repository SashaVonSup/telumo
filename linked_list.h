#ifndef TELUMO_LINKED_LIST_H
#define TELUMO_LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

typedef struct TLM_list_node {
    void *data;
    struct TLM_list_node* next;
} *TLM_list_node_t, **TLM_list_t;

TLM_list_node_t TLM_list_node_new(void *data, size_t data_size);
void TLM_list_push(TLM_list_t head, void *data, size_t data_size);
void TLM_list_pop(TLM_list_t head);
int TLM_list_size(TLM_list_t head);
TLM_list_node_t TLM_list_at(TLM_list_t head, int i);
void TLM_list_insert(TLM_list_t head, void *data, size_t data_size, int i);
void TLM_list_delete(TLM_list_t head, int i);

#endif //TELUMO_LINKED_LIST_H
