/**
 * @file
 * @brief Auxiliary utility functions
 *
 * This header file contains auxiliary utility functions, useful for TeLuMo or its users.
 */
#ifndef TELUMO_UTILS_H
#define TELUMO_UTILS_H

#include <stdlib.h>
#include <ncurses.h>

/**
 * @brief Transform string with serial rows to chtype table with those rows
 * @param s Pointer to the source string to transform
 * @param h Number of rows, i.e. height of the table
 * @param w Length of each row, i.e. width of the table
 * @return Pointer to new 2d array
 * @warning Length of the source string must be h*m
 */
chtype **TLM_string_to_chtype_table(char *s, uint h, uint w);

#endif //TELUMO_UTILS_H
