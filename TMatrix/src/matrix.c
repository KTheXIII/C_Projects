#include "matrix.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "ui.h"

#define NUM_DRIPS 250
#define PROB_DRIP_SPAWN 0.85
#define PROB_DIM 0.05
#define PROB_CHANGE 0.98
#define RANDOM_PRINTABLE_CHARACTER (33 + (rand() % 80))

typedef struct {
    int row, col;
    bool alive;
    bool bright;
} drip;

cell matrix[MAX_ROW][MAX_COL];
drip drips[NUM_DRIPS];

double rand01() { return (double)rand() / (double)RAND_MAX; }

void init_drips() {
    for (int i = 0; i < NUM_DRIPS; i++) {
        drips[i].alive = false;
    }
}

void matrix_init() {
    // Set the matrix all to black
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            matrix[i][j].value = 0;
            matrix[i][j].intensity = 0;
        }
    }

    // Init drips
    init_drips();
}

void fade_n_change_matrix() {
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            // randomly change characters -- even invisuble ones.
            if (rand01() < PROB_CHANGE || matrix[i][j].value == 0) {
                matrix[i][j].value = RANDOM_PRINTABLE_CHARACTER;
            }

            // randomly dim the cells
            if (rand01() < PROB_DIM) {
                if (matrix[i][j].intensity > 0) matrix[i][j].intensity = 0;
            }
        }
    }
}

void try_add_drips() {
    for (int i = 0; i < NUM_DRIPS; i++) {
        if (drips[i].alive == false) {
            drips[i].alive = true;
            drips[i].col = rand() % MAX_COL;
            drips[i].row = 0;
            drips[i].bright = rand() % 2;
            return;
        }
    }
}

void update_drips() {
    for (int i = 0; i < NUM_DRIPS; i++) {
        if (drips[i].alive) {
            if (drips[i].bright) {
                matrix[drips[i].row][drips[i].col].intensity = MAX_INTENSITY;
            } else {
                matrix[drips[i].row][drips[i].col].intensity = MIN_INTENSITY;
            }
            // drips die when they leave the screen
            if (++drips[i].row >= MAX_ROW - 1) {
                drips[i].alive = false;
            }
        }
    }
}

void matrix_update() {
    if (rand01() < PROB_DRIP_SPAWN) {
        try_add_drips();
    }

    update_drips();

    fade_n_change_matrix();
}