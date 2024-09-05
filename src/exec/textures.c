#include "../../includes/cub3d.h"

//contvert all the .xpm file in struct t_img
int	load_textures(t_vars *v, t_parse *p)
{
	t_vecti	dim;

	dim.x = 10000;
	dim.y = 10000;
	printf("%s\n", p->ea);
	v->text.east = mlx_xpm_file_to_image(v->mlx, p->ea, &dim.y, &dim.x);
	if (!v->text.east)
		return (1);
	v->text.west = mlx_xpm_file_to_image(v->mlx, p->we, &dim.y, &dim.x);
	if (!v->text.west)
		return (1);
	v->text.south = mlx_xpm_file_to_image(v->mlx, p->so, &dim.y, &dim.x);
	if (!v->text.south)
		return (1);
	v->text.north = mlx_xpm_file_to_image(v->mlx, p->no, &dim.y, &dim.x);
	if (!v->text.north)
		return (1);
	v->text.door = mlx_xpm_file_to_image(v->mlx, \
		"textures/door3.xpm", &dim.y, &dim.x);
	if (!v->text.door)
		return (1);
	return (0);
}
