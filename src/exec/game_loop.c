#include "../../includes/cub3d.h"

int cub_loop(t_vars *v)
{
		clear_image(v, 0);
		color_ceiling(v, v->color_f);
		color_floor(v, v->color_c);
		mlx_mouse_get_pos(v->mlx, v->win, &v->mouse_pos.x, &v->mouse_pos.y);
		 if (!v->mouse_unlock)
			mouse_in_the_midle(v);
		raycasting(v);
		mlx_put_image_to_window(v->mlx, v->win, v->data.img, 0, 0);
	return (0);
}
