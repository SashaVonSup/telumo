#include "linked_list.h"

TLM_list_t TLM_list_new() {
    return NULL;
}

TLM_list_node_t TLM_list_node_new(void *data, size_t data_size) {
    TLM_list_node_t this = malloc(sizeof(struct TLM_list_node));
    this->data = malloc(data_size);
    memcpy(this->data, data, data_size);
    return this;
}

void TLM_list_push(TLM_list_t head, void *data, size_t data_size) {
    TLM_list_node_t node = TLM_list_node_new(data, data_size);
    node->next = *head;
    *head = node;
}

void TLM_list_pop(TLM_list_t head) {
    (*head) = (*head)->next;
}

int TLM_list_size(TLM_list_t head) {
    int size = 0;
    for (TLM_list_node_t current = *head; current != NULL; current = current->next)
        ++size;
    return size;
}

TLM_list_node_t TLM_list_at(TLM_list_t head, int i) {
    TLM_list_node_t current = *head;
    for (int index = 0; index < i; ++index)
        current = current->next;
    return current;
}

void TLM_list_insert(TLM_list_t head, void *data, size_t data_size, int i) {
    if (i == 0)
        return TLM_list_push(head, data, data_size);
    TLM_list_node_t node = TLM_list_node_new(data, data_size);
    TLM_list_node_t prev_node = TLM_list_at(head, i - 1);
    TLM_list_node_t next_node = prev_node->next;
    prev_node->next = node;
    node->next = next_node;
}

void TLM_list_delete(TLM_list_t head, int i) {
    if (i == 0)
        return TLM_list_pop(head);
    TLM_list_node_t prev_node = TLM_list_at(head, i - 1);
    prev_node->next = prev_node->next->next;
}
