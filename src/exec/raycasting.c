#include "../../includes/cub3d.h"
//https://lodev.org/cgtutor/raycasting.html

static int	vert_line_utils(t_vars *v, t_img *texture, int *height, int *width)
{
	int	color;

	*height = texture->height;
	v->text.y = (int)v->text.pos % *height;
	*width = texture->width;
	color = ((int *)texture->data)[*width * v->text.y + v->text.x];
	return (color);
}

static void	vert_line(int x, int draw_start, t_vars *v, t_dir d)
{
	int	height;
	int	width;
	int	color;

	while (draw_start < v->player.draw_end)
	{
		v->text.pos += v->text.step;
		if (d == DOOR && v->text.text_door == 0)
			color = vert_line_utils(v, v->text.door, &height, &width);
		else if (d == DOOR && v->text.text_door == 1)
			color = vert_line_utils(v, v->text.door_a, &height, &width);
		else if (d == DOOR && v->text.text_door == 2)
			color = vert_line_utils(v, v->text.door_b, &height, &width);
		else if (d == DOOR && v->text.text_door == 3)
			color = vert_line_utils(v, v->text.door_c, &height, &width);
		else if (d == NORTH)
			color = vert_line_utils(v, v->text.north, &height, &width);
		else if (d == SOUTH)
			color = vert_line_utils(v, v->text.south, &height, &width);
		else if (d == EAST)
			color = vert_line_utils(v, v->text.east, &height, &width);
		else if (d == WEST)
			color = vert_line_utils(v, v->text.west, &height, &width);
		my_mlx_pixel_put(&v->data, x, draw_start++, color);
	}
}

void	init_raycasting(t_vars *v)
{
	v->player.movespeed = 0.2;
	v->player.rotspeed = 0.09;
	v->player.pos.x += 0.5;
	v->player.pos.y += 0.5;
	//v->player.plane.x = 0.85;
	//v->player.plane.y = 0.0;
}

void	raycasting(t_vars *v)
{
	int			x;
	t_vecti		map;
	t_dir		d;

	map = (t_vecti){0};
	d = (t_dir){0};
	x = 0;
	while (x < WIN_WIDTH)
	{
		v->player.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		v->player.ray_dir.x = v->player.dir.x
			+ v->player.plane.x * v->player.camera_x;
		v->player.ray_dir.y = v->player.dir.y
			+ v->player.plane.y * v->player.camera_x;
		map.x = (int)v->player.pos.x;
		map.y = (int)v->player.pos.y;
		v->player.delta_dist.x = d_abs(1 / v->player.ray_dir.x);
		v->player.delta_dist.y = d_abs(1 / v->player.ray_dir.y);
		v->player.hit = 0;
		raycast_one(v, map, &d);
		vert_line(x++, v->player.draw_start, v, d);
	}
}
