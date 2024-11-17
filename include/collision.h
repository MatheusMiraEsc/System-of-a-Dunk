#ifndef COLLISION_H
#define COLLISION_H

typedef struct {
    int x, y;
    int width, height;
} Rectangle;

int checkCollision(Rectangle r1, Rectangle r2);

#endif
