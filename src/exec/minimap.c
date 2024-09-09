#include "../../includes/cub3d.h"
#include <math.h>


void	ft_draw_sprite(t_vars *v, t_img *img, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	if (!img)
		return ;
	i = 0;
	while (i < img->width)
	{
		j = -1;
		while (++j < img->height)
		{
			if (j + y < 0 || j + y >= v->map[0]->map_height * 9
				|| i + x < 0 || i + x >= v->map[0]->map_length * 9)
				continue ;
			color = ((int *)img->data)[j * img->width + i];
			my_mlx_pixel_put(&v->data, x, y, color);
			x++;
		}
		y++;
		i++;
	}

}

void	draw_sprite(t_vars *v, int x, int y)
{
	// double	i;
	// double	j;

	// while(i < y)
	// 	i++;
	// while(j < x)
	// 	j++;

	if(v->map[y][x].tile == VOID)
		mlx_put_image_to_window(v->mlx, v->win, v->mini.floor, x * 8, y * 8);
	else if(v->map[y][x].tile == FLOOR || v->map[y][x].tile == DOOR_O)
		mlx_put_image_to_window(v->mlx, v->win, v->mini.nothing, x * 8, y * 8);
	else if(v->map[y][x].tile == WALL)
		mlx_put_image_to_window(v->mlx, v->win, v->mini.floor, x * 8, y * 8);
	else if(v->map[y][x].tile == DOOR_C)
		mlx_put_image_to_window(v->mlx, v->win, v->mini.door, x * 8, y * 8);
	// else
	// 	mlx_put_image_to_window(v->mlx, v->win, v->win, v->mini.nothing, x, y);
	mlx_put_image_to_window(v->mlx, v->win, v->mini.player, v->player.pos.y, v->player.pos.x);
}

void	skip_and_draw(t_vars *v)
{
	double	y;
	double	x;

	x = 0;
	y = 0;
	while(y < v->map[0]->map_height)
	{
		x = 0;
		while(x < v->map[0]->map_length)
		{
			draw_sprite(v, x, y);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_vars *v)
{
	// double	y;
	// double	x;

	// y = 0;
	// x = 0;
	skip_and_draw(v);
	//v->player.pos.y
}