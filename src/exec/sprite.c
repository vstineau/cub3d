#include "../../includes/cub3d.h"

int    load_sprites(t_vars *v)
{
    int    height;
    int    width;

    height = T_HEIGHT;
    width = T_WIDTH;
    v->text.east = mlx_xpm_file_to_image(v->mlx, \
                                "textures/wall.xpm", &width, &height);
    v->text.west = mlx_xpm_file_to_image(v->mlx, \
                                "textures/floor.xpm", &width, &height);
    v->text.south = mlx_xpm_file_to_image(v->mlx, \
                                "textures/wall.xpm", &width, &height);
    v->text.north = mlx_xpm_file_to_image(v->mlx, \
                                "textures/floor.xpm", &width, &height);
    if (!v->text.east || !v->text.west || !v->text.south || !v->text.north)
        return (1);
    return (0);
}
