#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	x += data->offset_x;
	y += data->offset_y;
	if (x >= WIN_WIDTH || y >= WIN_HEIGHT || x < 0 || y < 0)
		return ;
	dest = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void	start_image(t_vars *v)
{
	v->data.img = mlx_new_image(v->mlx, WIN_WIDTH, WIN_HEIGHT);
	v->data.addr = mlx_get_data_addr(v->data.img, &v->data.bit_per_pixel,
			&v->data.line_length, &v->data.endian);
}

void	clear_image(t_vars *v, int color)
{

	int		y;
	int		x;
	char	*pixel;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel = v->data.addr + (y * v->data.line_length
					+ x * (v->data.bit_per_pixel / 8));
			*(unsigned int *)pixel = color;
			x++;
		}
		y++;
	}
}

void	color_ceiling(t_vars *v, int color)
{
	int		y;
	int		x;
	char	*pixel;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel = v->data.addr + (y * v->data.line_length
					+ x * (v->data.bit_per_pixel / 8));
			*(unsigned int *)pixel = color;
			x++;
		}
		y++;
	}
}

void	color_floor(t_vars *v, int color)
{
	int		y;
	int		x;
	char	*pixel;

	y = WIN_HEIGHT;
	while (y >= WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel = v->data.addr + (y * v->data.line_length
					+ x * (v->data.bit_per_pixel / 8));
			*(unsigned int *)pixel = color;
			x++;
		}
		y--;
	}
}
