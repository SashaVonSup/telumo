/**
 * @file
 * @brief Linked list implementation
 *
 * This header file contains structures, types and function definitions that belong to implementation of linked list.
 * Here "list" is synonym of "linked list".
 */
#ifndef TELUMO_LINKED_LIST_H
#define TELUMO_LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

/// Node of list
typedef struct TLM_list_node {
    void *data;  ///< Pointer to the data to store
    /// Pointer to the next node in list
    /// @details (NULL if it is the last node)
    struct TLM_list_node* next;
} *TLM_list_node_t, **TLM_list_t;

/**
 * @brief Create new list
 * @return Pointer to the created list
 */
TLM_list_t TLM_list_new();

/**
 * @brief Delete list
 * @param head Pointer of the list to delete
 */
void TLM_list_free(TLM_list_t head);

/**
 * @brief Create new list_node
 * @param data Pointer to the data to store
 * @param data_size Size of the data
 * @return Pointer to the created list_node
 * @warning This function makes copy of the data, so you should free old memory and use data of the created node.
 */
TLM_list_node_t TLM_list_node_new(void *data, size_t data_size);

/**
 * @brief Delete list_node
 * @param node Pointer to the list_node to delete
 */
void TLM_list_node_free(TLM_list_node_t node);


/**
 * @brief Insert data at the beginning of list
 * @param head Pointer to the destination list
 * @param data Pointer to the data to store
 * @param data_size Size of the data
 * @warning This function makes copy of the data, so you should free old memory and use data of the created node.
 */
void TLM_list_push(TLM_list_t head, void *data, size_t data_size);

/**
 * @brief Remove list_node from the beginning of list
 * @param head Pointer to the list
 * @warning List must contain at least 1 element.
 * @warning Removed list_node is not deleted, so you should free it if you don't want to work with it anymore.
 */
void TLM_list_pop(TLM_list_t head);

/**
 * @brief Count the number of list_nodes in list
 * @param head Pointer to the list
 * @return Size of the list
 */
int TLM_list_size(TLM_list_t head);

/**
 * @brief Find list_node by index
 * @param head Pointer to the list
 * @param i Index of list_node to find (0 is the beginning)
 * @return Pointer to the i-th node of the list (NULL if the list's size == i)
 * @warning List must contain at least i elements.
 */
TLM_list_node_t TLM_list_at(TLM_list_t head, int i);

/**
 * @brief Insert data at the i-th place in list
 * @param head Pointer to the destination list
 * @param data Pointer to the data to store
 * @param data_size Size of the data
 * @param i Index where to insert (i elements will appear before the new one)
 * @warning This function makes copy of the data, so you should free old memory and use data of the created node.
 * @warning List must contain at least i elements.
 */
void TLM_list_insert(TLM_list_t head, void *data, size_t data_size, int i);

/**
 * @brief Remove list_node by index
 * @param head Pointer to the list
 * @param i Index of the list_node to remove
 * @warning List must contain at least (i + 1) elements.
 * @warning Removed list_node is not deleted, so you should free it if you don't want to work with it anymore.
 */
void TLM_list_delete(TLM_list_t head, int i);

#endif //TELUMO_LINKED_LIST_H
