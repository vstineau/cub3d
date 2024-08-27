#include "../../includes/cub3d.h"
//https://lodev.org/cgtutor/raycasting.html

static void	draw_window(t_vars *v)
{
	int i;
	int j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			if (v->buffer[i][j] == 0)
			{
				j++;
				break;
			}
			my_mlx_pixel_put(&v->data, j, i, v->buffer[i][j]);
			v->buffer[i][j] = 0;
			j++;
		}
		i++;
	}
}

static void	vert_line(int x, int draw_start, t_vars *v, t_dir d)
{
	while (draw_start < v->player.draw_end)
	{
		v->text.y = (int)v->text.pos & (T_HEIGHT - 1);
		//printf("testy = %d\n", v->text.y);
		//printf("testx = %d\n", v->text.x);
		v->text.pos += v->text.step;
		if (d == NORTH)
			v->buffer[draw_start++][x] = (int)v->text.north->data[T_HEIGHT * v->text.y + v->text.x];
		if (d == SOUTH)
			v->buffer[draw_start++][x] = (int)v->text.south->data[T_HEIGHT * v->text.y + v->text.x];
		if (d == EAST)
			v->buffer[draw_start++][x] = (int)v->text.east->data[T_HEIGHT * v->text.y + v->text.x];
		if (d == WEST)
			v->buffer[draw_start++][x] = (int)v->text.west->data[T_HEIGHT * v->text.y + v->text.x];
	}
}

void	raycasting(t_vars *v)
{
	int						x;
	t_vecti				map;
	t_dir					d;

	x = 0;
	while (x < WIN_WIDTH)
	{
		v->player.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		v->player.ray_dir.x = v->player.dir.x + v->player.plane.x * v->player.camera_x;
		v->player.ray_dir.y = v->player.dir.y + v->player.plane.y * v->player.camera_x;
		map.x = (int)v->player.pos.x;
		map.y = (int)v->player.pos.y;
		v->player.delta_dist.x = fabs(1 / v->player.ray_dir.x);
		v->player.delta_dist.y = fabs(1 / v->player.ray_dir.y);
		v->player.hit = 0;
		if (v->player.ray_dir.x < 0)
		{
			v->player.step.x = -1;
			v->player.side_dist.x = (v->player.pos.x - map.x) * v->player.delta_dist.x;
		}
		else
		{
			v->player.step.x = 1;
			v->player.side_dist.x = (map.x + 1.0 - v->player.pos.x) * v->player.delta_dist.x;
		}
		if (v->player.ray_dir.y < 0)
		{
			v->player.step.y = -1;
			v->player.side_dist.y = (v->player.pos.y - map.y) * v->player.delta_dist.y;
		}
		else
		{
			v->player.step.y = 1;
			v->player.side_dist.y = (map.y + 1.0 - v->player.pos.y) * v->player.delta_dist.y;
		}
		int i = 0;
		while (v->player.hit == 0 && i < 5000)
		{
			if(map.x < 0 || map.x >= WIN_WIDTH || map.y < 0 || map.y >= WIN_HEIGHT)
				break ;
			if (v->player.side_dist.x < v->player.side_dist.y)
			{
				v->player.side_dist.x += v->player.delta_dist.x;
				map.x += (int)v->player.step.x;
				v->player.side = 0;
			}
			else
			{
				v->player.side_dist.y += v->player.delta_dist.y;
				map.y += (int)v->player.step.y;
				v->player.side = 1;
			}
			if (v->map[map.x][map.y].tile == WALL)
				v->player.hit = 1;
			i++;
		}
		if (v->player.side == 0)
		{
			v->player.perpwalldist = (v->player.side_dist.x - v->player.delta_dist.x);
			v->text.wallx = (int)(v->player.pos.y + v->player.perpwalldist * v->player.ray_dir.y);
		}
		else
		{
			v->player.perpwalldist = (v->player.side_dist.y - v->player.delta_dist.y);
			v->text.wallx =(int)(v->player.pos.x + v->player.perpwalldist * v->player.ray_dir.x);
		}
		v->player.line_height = (int)(WIN_HEIGHT / v->player.perpwalldist);
		v->player.draw_start = -v->player.line_height / 2 + WIN_HEIGHT / 2;
		if (v->player.draw_start < 0)
			v->player.draw_start = 0;
		v->player.draw_end = v->player.line_height / 2 + WIN_HEIGHT / 2;
		if (v->player.draw_end >= WIN_HEIGHT)
			v->player.draw_end = WIN_HEIGHT - 1;
		if (v->player.side == 0 && v->player.ray_dir.x > 0)
			d = NORTH;
		if (v->player.side == 0 && v->player.ray_dir.x <= 0)
			d = SOUTH;
		if (v->player.side == 1 && v->player.ray_dir.y > 0)
			d = EAST;
		if (v->player.side == 1 && v->player.ray_dir.y <= 0)
			d = WEST;
		v->text.x = (int)v->text.wallx * (double)T_WIDTH;
		if (v->player.side == 0 && v->player.ray_dir.x > 0)
			v->text.x = T_WIDTH - v->text.x - 1;
		if (v->player.side == 1 && v->player.ray_dir.x < 0)
			v->text.x = T_WIDTH - v->text.x - 1;
		if (v->text.x < 0)
			v->text.x = 0;
		v->text.step = 1.0 * T_HEIGHT / v->player.line_height;
		v->text.pos = (v->player.draw_start - (double)WIN_HEIGHT / 2 + (double)v->player.line_height / 2) * v->text.step;
		vert_line(x++, v->player.draw_start, v, d);
	}
	draw_window(v);
//	printf("\n");
}
