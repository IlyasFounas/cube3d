#include "render.h"

double check_walls_distance(int **map, double px, double py)
{
    double distance;
    double step;
    double dx;
    // double dy;

    distance = 0.0;
    step = 0.01;
    dx = -1.0;
    // dy = 0.0;
    while (px >= 0)
    {
        px += dx * step;
        distance += step;
        if (map[(int)px][(int)py] == 1)
            return (distance);
    }
    return (distance);
}

int main(void)
{
    int **map;
    double px;
    double py;

    px = 1.0;
    py = 1.0;
    map = hard_coded_2dmap();
    create_window();
    printf("%f\n", check_walls_distance(map, px, py));
    free_map(map);
    return (0);
}

// Map representation
// 1 1 1 1
// 1 p 0 1
// 1 0 0 1
// 1 1 1 1