#include "../../includes/cub3d.h"


void	mouse_in_the_midle(t_vars *v)
{
	mlx_mouse_get_pos(v->mlx, v->win, &v->mouse_pos.x, &v->mouse_pos.y);
	while (v->mouse_pos.x != WIN_WIDTH / 2)
	{
		printf("mousex = %d\n", v->mouse_pos.x);
		printf("mousey = %d\n", v->mouse_pos.y);
		if (v->mouse_pos.x >= WIN_WIDTH || v->mouse_pos.y >= WIN_HEIGHT
			|| v->mouse_pos.x < 0 || v->mouse_pos.y < 0)
			return ;
		if (v->mouse_pos.x < 480)
			v->f[XK_Right](v);
		else
			v->f[XK_Left](v);
		mlx_mouse_get_pos(v->mlx, v->win, &v->mouse_pos.x, &v->mouse_pos.y);
	}
}
