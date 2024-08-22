#include "../../includes/cub3d.h"

void	vert_line(int x, int draw_start, t_vars *v, int color)
{
	printf(BHI_RED"draw_start = %d\n"RESET, draw_start);
	printf(BHI_WHITE"draw_end = %d\n"RESET, v->player.draw_end);
	if (draw_start > v->player.draw_end)
	{
		while (draw_start > v->player.draw_end)
		{
			my_mlx_pixel_put(&v->data, x, draw_start--, color);
		}
	}
	else
	{
		while (draw_start < v->player.draw_end)
		{
			my_mlx_pixel_put(&v->data, x, draw_start++, color);
		}
	}
}

void	raycasting(t_vars *v)
{
	int	x;
	int	mapx;
	int	mapy;
	int color = P_RED;

	x = 0;
	while (x < WIN_WIDTH)
	{
		printf(B_RED"player posy = %f\n"RESET, v->player.pos.y);
		printf(B_MAGENTA"player posx = %f\n"RESET, v->player.pos.x);
		v->player.camera_x = 2 * x / (float)(WIN_WIDTH) - 1;
		v->player.ray_dir.x = v->player.dir.x + v->player.plane.x * v->player.camera_x;
		v->player.ray_dir.y = v->player.dir.y + v->player.plane.y * v->player.camera_x;
		printf(B_YELLOW" raydirx = %f\n"RESET, v->player.ray_dir.x);
		printf(B_YELLOW" raydiry = %f\n"RESET, v->player.ray_dir.y);
		mapx = (int)v->player.pos.x;
		mapy = (int)v->player.pos.y;
		v->player.delta_dist.x = fabs(1 / v->player.ray_dir.x);
		v->player.delta_dist.y = fabs(1 / v->player.ray_dir.y);
		printf(BHI_BLUE" deltadistx = %f\n"RESET, v->player.delta_dist.x);
		printf(BHI_BLUE" deltadisty = %f\n"RESET, v->player.delta_dist.y);
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
		printf(BHI_YELLOW" sidedistx = %f\n"RESET, v->player.side_dist.x);
		printf(BHI_GREEN" sidedisty = %f\n"RESET, v->player.side_dist.y);
		while (v->player.hit == 0)
		{
		//	printf(BHI_YELLOW" stepx = %f\n"RESET, v->player.step.x);
		//	printf(BHI_YELLOW" sidedistx = %f\n"RESET, v->player.side_dist.x);
		//	printf(BHI_GREEN" sidedisty = %f\n"RESET, v->player.side_dist.y);
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
			//printf(B_GREEN"mapx = %d\n"RESET, mapx);
			//printf(B_GREEN"mapy = %d\n"RESET, mapy);
			if (mapx >=0 && mapy >= 0 && v->map[mapx][mapy].tile == WALL)
				v->player.hit = 1;
		}
		if (v->player.side == 0)
			v->player.perpwalldist = (v->player.side_dist.x - v->player.delta_dist.x);
		else
		{
			v->player.perpwalldist = (v->player.side_dist.y - v->player.delta_dist.y);
		}
		printf(BHI_MAGENTA" perpwalldist = %f\n"RESET, v->player.perpwalldist);
		v->player.line_height = (int)(WIN_HEIGHT / v->player.perpwalldist);
		printf(BHI_CYAN"line_height = %d\n"RESET, v->player.line_height);
		v->player.draw_start = -v->player.line_height / 2 + WIN_HEIGHT / 2;
		if (v->player.draw_start < 0)
			v->player.draw_start = 0;
		v->player.draw_end = v->player.line_height / 2 + WIN_HEIGHT / 2;
		if (v->player.draw_end >= WIN_HEIGHT)
			v->player.draw_end = WIN_HEIGHT - 1;
		vert_line(x, v->player.draw_start, v, color);
		x++;
	}
}
