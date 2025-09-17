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

int **hard_coded_2dmap(void)
{
    int **res;

    res = malloc(4 * sizeof(int *));
    if (!res)
        display_error();

    res[0] = malloc(4 * sizeof(int));
    res[1] = malloc(4 * sizeof(int));
    res[2] = malloc(4 * sizeof(int));
    res[3] = malloc(4 * sizeof(int));
    if (!res[0] || !res[1] || !res[2] || !res[3])
        display_error();

    res[0][0] = 1; res[0][1] = 1; res[0][2] = 1; res[0][3] = 1;
    res[1][0] = 1; res[1][1] = 0; res[1][2] = 0; res[1][3] = 1;
    res[2][0] = 1; res[2][1] = 0; res[2][2] = 0; res[2][3] = 1;
    res[3][0] = 1; res[3][1] = 1; res[3][2] = 1; res[3][3] = 1;

    return (res);
}
