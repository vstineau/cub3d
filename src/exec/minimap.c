#include "../../includes/cub3d.h"

void	ft_draw_sprite(t_vars *v, t_img *img, int x, int y)
{
	int				i;
	int				j;
	int				x2;
	unsigned int	color;

	if (!img)
		return ;
	i = 0;
	while (i < img->height)
	{
		j = -1;
		x2 = x;
		while (++j < img->width)
		{
			color = ((int *)img->data)[i * img->width + j];
			my_mlx_pixel_put(&v->data, x2, y, color);
			x2++;
		}
		y++;
		i++;
	}
}

void	draw_sprite(t_vars *v, int x, int y)
{
	if ((int)v->mini.y == (int)v->player.pos.x
		&& (int)v->mini.x == (int)v->player.pos.y)
		ft_draw_sprite(v, v->mini.player, x, y);
	else if (v->mini.y < 0 || v->mini.x < 0
		|| v->mini.y >= v->map[0]->map_height
		|| v->mini.x >= v->map[0]->map_length
		|| v->map[(int)v->mini.y][(int)v->mini.x].tile == VOID)
		ft_draw_sprite(v, v->mini.floor, x, y);
	else if (v->map[(int)v->mini.y][(int)v->mini.x].tile == FLOOR
			|| v->map[(int)v->mini.y][(int)v->mini.x].tile == DOOR_O)
		ft_draw_sprite(v, v->mini.nothing, x, y);
	else if (v->map[(int)v->mini.y][(int)v->mini.x].tile == WALL)
		ft_draw_sprite(v, v->mini.floor, x, y);
	else if (v->map[(int)v->mini.y][(int)v->mini.x].tile == DOOR_C)
		ft_draw_sprite(v, v->mini.door, x, y);
}

void	draw_minimap(t_vars *v)
{
	int	i;
	int	j;

	i = 0;
	v->mini.y = v->player.pos.x - 14;
	while (i < WIN_HEIGHT / 3)
	{
		j = 0;
		v->mini.x = v->player.pos.y - 14;
		while (j < WIN_WIDTH / 4)
		{
			draw_sprite(v, j, i);
			v->mini.x++;
			j += 8;
		}
		v->mini.y++;
		i += 8;
	}
}

