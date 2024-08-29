#include "../../includes/cub3d.h"

int    load_sprites(t_vars *v)
{
	int	height;
	int	width;

	height = 10000;
	width = 10000;
	v->text.east = mlx_xpm_file_to_image(v->mlx, \
		"textures/up.xpm", &width, &height);
	if (!v->text.east)
		return (1);
	v->text.west = mlx_xpm_file_to_image(v->mlx, \
		"textures/up.xpm", &width, &height);
	if (!v->text.west)
		return (1);
	v->text.south = mlx_xpm_file_to_image(v->mlx, \
		"textures/up.xpm", &width, &height);
	if (!v->text.south)
		return (1);
	v->text.north = mlx_xpm_file_to_image(v->mlx, \
		"textures/up.xpm", &width, &height);
	if (!v->text.north)
		return (1);
	return (0);
}
