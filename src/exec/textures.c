#include "../../includes/cub3d.h"

static int	minimap(t_vars *v, t_vecti dim)
{
	v->mini.floor = mlx_xpm_file_to_image(v->mlx, \
		"textures/minifloor.xpm", &dim.y, &dim.x);
	if (!v->mini.floor)
		return (1);
	v->mini.wall = mlx_xpm_file_to_image(v->mlx, \
		"textures/miniwall.xpm", &dim.y, &dim.x);
	if (!v->mini.wall)
		return (1);
	v->mini.player = mlx_xpm_file_to_image(v->mlx, \
		"textures/miniplayer.xpm", &dim.y, &dim.x);
	if (!v->mini.player)
		return (1);
	v->mini.door = mlx_xpm_file_to_image(v->mlx, \
		"textures/minidoor.xpm", &dim.y, &dim.x);
	if (!v->mini.door)
		return (1);
	v->mini.nothing = mlx_xpm_file_to_image(v->mlx, \
		"textures/minivoid.xpm", &dim.y, &dim.x);
	if (!v->mini.nothing)
		return (1);
	return (0);
}

static int	animated_door(t_vars *v, t_vecti dim)
{
	v->text.door = mlx_xpm_file_to_image(v->mlx, \
		"textures/anim.xpm", &dim.y, &dim.x);
	if (!v->text.door)
		return (1);
	v->text.door_a = mlx_xpm_file_to_image(v->mlx, \
		"textures/anim1.xpm", &dim.y, &dim.x);
	if (!v->text.door_a)
		return (1);
	v->text.door_b = mlx_xpm_file_to_image(v->mlx, \
		"textures/anim2.xpm", &dim.y, &dim.x);
	if (!v->text.door_b)
		return (1);
	v->text.door_c = mlx_xpm_file_to_image(v->mlx, \
		"textures/anim3.xpm", &dim.y, &dim.x);
	if (!v->text.door_c)
		return (1);
	return (0);
}

//contvert all the .xpm file in struct t_img
int	load_textures(t_vars *v, t_parse *p)
{
	t_vecti	dim;

	dim.x = 10000;
	dim.y = 10000;
	v->text.east = mlx_xpm_file_to_image(v->mlx, p->ea, &dim.y, &dim.x);
	if (!v->text.east)
		return (ft_err(NULL, "east texture load failed"), 1);
	v->text.west = mlx_xpm_file_to_image(v->mlx, p->we, &dim.y, &dim.x);
	if (!v->text.west)
		return (ft_err(NULL, "west texture load failed"), 1);
	v->text.south = mlx_xpm_file_to_image(v->mlx, p->so, &dim.y, &dim.x);
	if (!v->text.south)
		return (ft_err(NULL, "south texture load failed"), 1);
	v->text.north = mlx_xpm_file_to_image(v->mlx, p->no, &dim.y, &dim.x);
	if (!v->text.north)
		return (ft_err(NULL, "north texture load failed"), 1);
	if (animated_door(v, dim))
		return (ft_err(NULL, "door textures load failed"), 1);
	if (minimap(v, dim))
		return (ft_err(NULL, "minimap texture load failed"), 1);
	return (0);
}
