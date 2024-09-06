#include "../../includes/cub3d.h"


// void	ft_draw_sprite(t_vars *v, t_img *img, int x, int y)
// {
// 	int				i;
// 	int				j;
// 	unsigned int	color;

// 	if (!img)
// 		return ;
// 	i = 0;
// 	while (i < img->width)
// 	{
// 		j = -1;
// 		while (++j < img->height)
// 		{
// 			if (j + y < 0 || j + y >= params->map_height * TILE_SIZE
// 				|| i + x < 0 || i + x >= params->map_width * TILE_SIZE)
// 				continue ;
// 			color = ((int *)img->data)[(int)(j) *img->width + (int)(i)];
// 			if (color == 0xFF000000)
// 				continue ;
// 			((int *)v->canvas->data)[(y + j) * params->canvas->width
// 				+ (x + i)] = color;
// 		}
// 		i++;
// 	}
// }



void	draw_minimap(t_vars *v)
{
	const int	x = v->player.pos.x - 4;
	const int	y = v->player.pos.y + 4;
}