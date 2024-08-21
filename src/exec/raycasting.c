#include "../../includes/cub3d.h"

void	vert_line(int x, int draw_start, t_vars *v, int color)
{
	while (draw_start < v->player.draw_end)
		my_mlx_pixel_put(&v->data, x, draw_start++, color);
}

void	raycasting(t_vars *v)
{
	int maptest[24][24] =
	{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	int	x;
	int	mapx;
	int	mapy;
	int color;

	v->player.pos.x = 6;
	v->player.pos.y = 6;
	v->player.dir.x = -1.0;
	v->player.dir.y = 0.0;
	v->player.plane.x = 0.0;
	v->player.plane.y = 0.66;
	mapx = (int)v->player.pos.x;
	mapy = (int)v->player.pos.y;
	x = 0;
	while (x < WIN_WIDTH)
	{
		v->player.camera_x = 2 * x / (WIN_WIDTH - 1);
		v->player.ray_dir.x = v->player.dir.x + v->player.plane.x * v->player.camera_x;
		v->player.ray_dir.y = v->player.dir.y + v->player.plane.y * v->player.camera_x;
		if (v->player.ray_dir.x == 0)
			v->player.ray_dir.x = 1e30;
		if (v->player.ray_dir.y == 0)
			v->player.ray_dir.y = 1e30;
		v->player.delta_dist.x = fabs(1 / v->player.ray_dir.x);
		v->player.delta_dist.y = fabs(1 / v->player.ray_dir.y);
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
			v->player.side_dist.y = (mapx + 1.0 - v->player.pos.y) * v->player.delta_dist.y;
		}
		while (v->player.hit == 0)
		{
			if (v->player.side_dist.x < v->player.side_dist.y)
			{
				v->player.side_dist.x += v->player.delta_dist.x;
				mapx += v->player.step.x;
				v->player.side = 0;
			}
			else
			{
				v->player.side_dist.x += v->player.delta_dist.x;
				mapx += v->player.step.x;
				v->player.side = 0;
			}
			if (maptest[mapx][mapy] > 0)
				v->player.hit = 1;
		}
		if (v->player.side == 0)
			v->player.perpwalldist = (v->player.side_dist.x - v->player.delta_dist.x);
		else
			v->player.perpwalldist = (v->player.side_dist.y - v->player.delta_dist.y);
		v->player.line_heigt = (int)(WIN_HEIGHT / v->player.perpwalldist);
		v->player.draw_start = -v->player.line_heigt / 2 + WIN_HEIGHT / 2;
		if (v->player.draw_start < 0)
			v->player.draw_start = 0;
		v->player.draw_end = v->player.line_heigt / 2 + WIN_HEIGHT / 2;
		if (v->player.draw_end < 0)
			v->player.draw_end = WIN_HEIGHT - 1;
		if (maptest[mapx][mapy] == 1)
			 color = P_RED;
		vert_line(x, v->player.draw_start, v, color);
		x++;
	}
}
