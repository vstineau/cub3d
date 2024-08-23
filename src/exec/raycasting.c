#include "../../includes/cub3d.h"
//https://lodev.org/cgtutor/raycasting.html

void	vert_line(int x, int draw_start, t_vars *v, int color)
{
	if (v->player.draw_start < v->player.draw_end)
	{
		while (v->player.draw_start < v->player.draw_end)
		{
			my_mlx_pixel_put(&v->data, x, v->player.draw_start++, color);
		}
	}
	else
	{
		while (draw_start > v->player.draw_end)
		{
			my_mlx_pixel_put(&v->data, x, draw_start--, color);
		}
	}
}

void	raycasting(t_vars *v)
{
	int	x;
	int	mapx;
	int	mapy;
	int	color;

	x = 0;
	while (x < WIN_WIDTH)
	{
		v->player.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		v->player.ray_dir.x = v->player.dir.x + v->player.plane.x * v->player.camera_x;
		v->player.ray_dir.y = v->player.dir.y + v->player.plane.y * v->player.camera_x;
		mapx = (int)v->player.pos.x;
		mapy = (int)v->player.pos.y;
		v->player.delta_dist.x = fabs(1 / v->player.ray_dir.x);
		v->player.delta_dist.y = fabs(1 / v->player.ray_dir.y);
		printf("%d ", (int)v->player.delta_dist.x);
		v->player.hit = 0;
		if (v->player.ray_dir.x < 0)
		{
			v->player.step.x = -1;
			v->player.side_dist.x = (v->player.pos.x - mapx) * v->player.delta_dist.x;
		}
		else
		{
			v->player.step.x = 1;
			v->player.side_dist.x = (mapx + 1.0 - v->player.pos.x) * v->player.delta_dist.x;
		}
		if (v->player.ray_dir.y < 0)
		{
			v->player.step.y = -1;
			v->player.side_dist.y = (v->player.pos.y - mapy) * v->player.delta_dist.y;
		}
		else
		{
			v->player.step.y = 1;
			v->player.side_dist.y = (mapy + 1.0 - v->player.pos.y) * v->player.delta_dist.y;
		}
		int i = 0;
		while (v->player.hit == 0 && i < 5000)
		{
			if(mapx < 0 || mapx >= WIN_WIDTH || mapy < 0 || mapy >= WIN_HEIGHT)
				break ;
			if (v->player.side_dist.x < v->player.side_dist.y)
			{
				v->player.side_dist.x += v->player.delta_dist.x;
				mapx += (int)v->player.step.x;
				v->player.side = 0;
			}
			else
			{
				v->player.side_dist.y += v->player.delta_dist.y;
				mapy += (int)v->player.step.y;
				v->player.side = 1;
			}
			if (v->map[mapx][mapy].tile == WALL)
				v->player.hit = 1;
			i++;
		}
		if (v->player.side == 0)
			v->player.perpwalldist = (v->player.side_dist.x - v->player.delta_dist.x);
		else
		{
			v->player.perpwalldist = (v->player.side_dist.y - v->player.delta_dist.y);
		}
		v->player.line_height = (int)(WIN_HEIGHT / v->player.perpwalldist);
		v->player.draw_start = -v->player.line_height / 2 + WIN_HEIGHT / 2;
		if (v->player.draw_start < 0)
			v->player.draw_start = 0;
		v->player.draw_end = v->player.line_height / 2 + WIN_HEIGHT / 2;
		if (v->player.draw_end >= WIN_HEIGHT)
			v->player.draw_end = WIN_HEIGHT - 1;
		if (v->player.side == 0 && v->player.ray_dir.x > 0)
			color = P_RED;
		if (v->player.side == 0 && v->player.ray_dir.x <= 0)
			color = P_WHITE;
		if (v->player.side == 1 && v->player.ray_dir.y > 0)
			color = P_GREEN;
		if (v->player.side == 1 && v->player.ray_dir.y <= 0)
			color = P_BLUE;
		vert_line(x++, v->player.draw_start, v, color);
	}
	printf("\n");
}
