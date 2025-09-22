#include "render.h"

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

int **hard_coded_2dmap(t_player_infos *infos)
{
    int **res;

    infos->map_infos->x = 8;
    infos->map_infos->y = 8;
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
    // res[2][1] = 1;
    // res[4][1] = 1;
    // res[4][3] = 1;
    // res[4][4] = 1;
    // res[4][5] = 1;
    return res;
}

