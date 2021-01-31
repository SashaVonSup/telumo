/**
 * @file
 * @brief Definitions of TeLuMo's structures and types and declarations of its functions
 *
 * This header file contains structures, types and function definitions that directly belong to the game engine.
 */
#ifndef TELUMO_H
#define TELUMO_H

#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

#include "linked_list.h"
#include "utils.h"

/// Table of characters (ncurses' chtype)
typedef struct TLM_char_map {
    uint h;  ///< Height of the char_map
    uint w;  ///< Width of the char_map
    chtype **ptr;  ///< Pointer to 2d array of chtype
} *TLM_char_map_t;

/**
 * @brief Create new char_map
 * @param h Height of the map
 * @param w Width of the map
 * @return Pointer to the created char_map
 */
TLM_char_map_t TLM_char_map_new(uint h, uint w);

/**
 * @brief Delete char_map
 * @param charMap Pointer to the char_map to delete
 */
void TLM_char_map_free(TLM_char_map_t charMap);

/// Entity (aka sprite) acting at scene
typedef struct TLM_entity {
    int x;  ///< X coordinate of the entity's position
    int y; ///< Y coordinate of the entity's position
    uint layer;  ///< Layer where the entity is located
    TLM_char_map_t charMap;  ///< Pointer to the char_map with the entity's image
} *TLM_entity_t;

/**
 * @brief Create new entity
 * @param x X coordinate of the entity's position
 * @param y Y coordinate of the entity's position
 * @param layer Layer of the entity
 * @param charMap Pointer to the entity's char_map
 * @return Pointer to the created entity
 */
TLM_entity_t TLM_entity_new(int x, int y, uint layer, TLM_char_map_t charMap);

/**
 * @brief Delete entity
 * @param entity Pointer to the entity to delete
 */
void TLM_entity_free(TLM_entity_t entity);

/**
 * @brief Table of numbers of the top layer at each position
 *
 * Entities of higher layer are in front of entities of lower one.
 * layer=0 to hide sprite
 */
typedef struct TLM_layer_map {
    uint h;  ///< Height of the layer_map
    uint w;  ///< Width of the layer_map
    uint **ptr;  ///< Pointer to 2d array of layer numbers
} *TLM_layer_map_t;

/**
 * @brief Create new layer_map
 * @param h Height of the layer_map
 * @param w Width of the layer_map
 * @return Pointer to the created layer_map
 */
TLM_layer_map_t TLM_layer_map_new(uint h, uint w);

/**
 * @brief Delete layer_map
 * @param layerMap Pointer to the layer_map to delete
 */
void TLM_layer_map_free(TLM_layer_map_t layerMap);

/**
 * @brief Scene where entities, etc. are located
 *
 * charMap and layerMap must be h * w size
 */
typedef struct TLM_scene {
    uint h;  ///< Height of the scene
    uint w;  ///< Width of the scene
    TLM_list_t entities;  ///< Pointer to linked_list of all entities at the scene
    TLM_char_map_t charMap;  ///< Pointer to the char_map with the scene's image
    TLM_layer_map_t layerMap;  ///< Pointer to the layer_map of the scene
} *TLM_scene_t;

/**
 * @brief Create new scene
 * @param h Height of the scene
 * @param w Width of the scene
 * @return Pointer to the created scene
 */
TLM_scene_t TLM_scene_new(uint h, uint w);

/**
 * @brief Delete scene
 * @param scene Pointer to the scene to delete
 */
void TLM_scene_free(TLM_scene_t scene);

/**
 * @brief Render entity to char_map and layer_map
 * @param charMap Destination char_map
 * @param layerMap Destination layer_map
 * @param entity Entity to render
 */
void TLM_render_entity(TLM_char_map_t charMap, TLM_layer_map_t layerMap, TLM_entity_t entity);

/**
 * @brief Add entity to scene
 * @param scene Pointer to the destination scene
 * @param entity Pointer to the entity to add
 * @param render Render the added entity or not
 */
void TLM_scene_add_entity(TLM_scene_t scene, TLM_entity_t entity, bool render);

/**
 * @brief Render entire scene
 * @param scene Pointer to the scene to render
 */
void TLM_scene_render(TLM_scene_t scene);

/**
 * @brief Draw scene at the screen (to ncurses' window)
 * @param window Destination window
 * @param scene Scene to draw
 */
void TLM_scene_flush(WINDOW *window, TLM_scene_t scene);

#endif //TELUMO_H
