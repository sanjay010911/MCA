#ifndef CELL_H
#define CELL_H

typedef struct cellstruct {
    bool bottom_wall : 1;
    bool right_wall : 1;
    bool visited : 1;
    bool path : 1;
} cell;

#endif  // CELL_H

