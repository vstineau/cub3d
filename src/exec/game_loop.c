#include "../../includes/cub3d.h"

void cub_loop(t_vars *v)
{
	while (!v->end)
	{
		printf("okokkokk\n");
		clear_image(v, 0);
		color_ceiling(v, P_WHITE);
		color_floor(v, P_WHITE);
		mlx_loop(v->mlx);
		mlx_mouse_get_pos(v->mlx, v->win, &v->mouse_pos.x, &v->mouse_pos.y);
		if (v->mouse_pos.x != 480)
			mouse_in_the_midle(v);
		raycasting(v);
		mlx_put_image_to_window(v->mlx, v->win, v->data.img, 0, 0);
	}
}
