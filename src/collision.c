# include "collision.h"

int check_collision(Rectangle r1, Rectangle r2)
{
    if (r1.x < r2.x + r2.width &&
        r1.x + r1.width > r2.x &&
        r1.y < r2.y + r2.height &&
        r1.y + r1.height > r2.y)
    {
        return 1;
    }
    return 0;
}