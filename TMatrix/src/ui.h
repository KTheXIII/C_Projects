#ifndef __UI_H_
#define __UI_H_

#include <stdbool.h>

#define MAX_ROW 24
#define MAX_COL 80

#define MAX_INTENSITY 13
#define MIN_INTENSITY 2

typedef struct {
    char value;
    int intensity;
} cell;

// defined in matrix.c
extern cell matrix[MAX_ROW][MAX_COL];

// prototypes
bool init_ui();
void cleanup_ui();
void show_matrix();

#endif