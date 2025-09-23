#include "cube3d_render.h"

void display_error(void)
{
    write(2, "malloc error\n", ft_strlen("malloc error\n"));
    exit(1);
}

void free_map(int **map)
{
    int i;

    i = -1;
    while (++i < 4)
        free(map[i]);
    free(map);
}

int **hard_coded_2dmap(void)
{
    int **res;

    res = malloc(8 * sizeof(int *));
    for (int i = 0; i < 8; i++) {
        res[i] = malloc(8 * sizeof(int));
        for (int j = 0; j < 8; j++) {
            res[i][j] = 0;
        }
    }
    for (int i = 0; i < 8; i++) {
        res[0][i] = 1;   // Mur Nord
        res[7][i] = 1;   // Mur Sud
        res[i][0] = 1;   // Mur Ouest
        res[i][7] = 1;   // Mur Est
    }
    res[1][3] = 1;
    // res[2][1] = 1;
    // res[2][2] = 1;
    // res[2][3] = 1;
    // res[2][4] = 1;
    // res[2][5] = 1;
    return res;
}

