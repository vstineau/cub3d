#include "../../includes/cub3d.h"

/*rotate the camera depending on the mouse position the putback the mouse
int the midle of the screen*/
int	mouse_in_the_midle(t_vars *v)
{
	mlx_mouse_get_pos(v->mlx, v->win, &v->mouse_pos.x, &v->mouse_pos.y);
	if (v->mouse_pos.x >= WIN_WIDTH || v->mouse_pos.y >= WIN_HEIGHT
		|| v->mouse_pos.x < 0 || v->mouse_pos.y < 0)
		return (0);
	if (v->mouse_pos.x > 480)
		v->f[XK_Right](v);
	else if(v->mouse_pos.x < 480)
		v->f[XK_Left](v);
	raycasting(v);
	mlx_mouse_get_pos(v->mlx, v->win, &v->mouse_pos.x, &v->mouse_pos.y);
	mlx_mouse_move(v->mlx, v->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}

//lock or unlock the mouse in the middle of the screen
void	lock_unlock_mouse(t_vars *v)
{
	v->mouse_unlock ^= 1;
}
