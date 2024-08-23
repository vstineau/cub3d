#include "../../includes/cub3d.h"

int    load_sprites(t_vars *v)
{
    int    height;
    int    width;

    height = T_HEIGHT;
    width = T_WIDTH;
    v->east = mlx_xpm_file_to_image(v->mlx, \
                                "textures/wall.xpm", &width, &height);
    v->west = mlx_xpm_file_to_image(v->mlx, \
                                "textures/floor.xpm", &width, &height);
    v->south = mlx_xpm_file_to_image(v->mlx, \
                                "textures/collectible.xpm", &width, &height);
    v->north = mlx_xpm_file_to_image(v->mlx, \
                                "textures/p.xpm", &width, &height);
    if (!v->east || !v->west || !v->south || !v->north)
        return (1);
    return (0);
}
