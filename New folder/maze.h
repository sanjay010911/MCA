#ifndef MAZE_H
#define MAZE_H

#include "cell.h"
typedef struct mazestruct {
    size_t width;
    size_t height;
    cell* cells;
} Maze;

typedef enum {
    LEFT,
    RIGHT,
    TOP,
    BOTTOM
} direction;

extern cell* cell_at(Maze* maze, size_t x, size_t y);

extern bool is_visited(Maze* maze, size_t x, size_t y);


#endif  // MAZE_H
