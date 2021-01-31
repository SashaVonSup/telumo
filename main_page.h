/**
 * @file
 * @brief Main page of documentation
 */

/**
 @mainpage TeLuMo Main Page

 @section intro_sec Introduction

 TeLuMo (aka TLM, from Esperanto Teksta Luda Motoro — Text Game Engine) is a C library that can help to create text (console) games.

 @section start_sec Getting Started

 @subsection step1 Using ncurses

 TeLuMo uses ncurses library to draw scenes in console. So you should not forget to add `-lncurses` at compilation,
 to initialize ncurses at the beginning of your program (`initscr()`) and to do `endwin()` at the end.

 Because of using ncurses, you should pass pointer to the window to `TLM_scene_flush`.
 Default window is stdscr, but you can create others and use them.

 @subsection step2 Creating scene

 Scene is the place where everything appears. All the entities are there. So you should create a scene.

 To create a scene, use `TLM_scene_new`. Then you can add all entities you want with `TLM_scene_add_entity`.

 @warning `TLM_scene_add_entity` creates a copy of entity, so you should delete the old one and use the new one.

 @snippet samples/reflection.c example_add_entity
*/
