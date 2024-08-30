#include "../../includes/cub3d.h"

int	load_textures(t_vars *v)
{
	t_vecti	dim;

	dim.x = 10000;
	dim.y = 10000;
	v->text.east = mlx_xpm_file_to_image(v->mlx, \
		"textures/east.xpm", &dim.y, &dim.x);
	if (!v->text.east)
		return (1);
	v->text.west = mlx_xpm_file_to_image(v->mlx, \
		"textures/west.xpm", &dim.y, &dim.x);
	if (!v->text.west)
		return (1);
	v->text.south = mlx_xpm_file_to_image(v->mlx, \
		"textures/south.xpm", &dim.y, &dim.x);
	if (!v->text.south)
		return (1);
	v->text.north = mlx_xpm_file_to_image(v->mlx, \
		"textures/north.xpm", &dim.y, &dim.x);
	if (!v->text.north)
		return (1);
	v->text.door = mlx_xpm_file_to_image(v->mlx, \
		"textures/door.xpm", &dim.y, &dim.x);
	if (!v->text.door)
		return (1);
	return (0);
}
