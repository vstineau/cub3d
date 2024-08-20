#include "../../includes/cub3d.h"

//LISTE DES KEYCODES : https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h

static void	f_init(t_vars *vars)
{
	ft_memset(vars->f, 0, 0xFFF);
	vars->f[XK_Escape] = (void *)close_windows;
	vars->f[XK_Left] = (void *)move_left;
	vars->f[XK_Right] = (void *)move_right;
	vars->f[XK_Up] = (void *)move_forward;
	vars->f[XK_Down] = (void *)move_backward;
}

int	window_action(int keycode, t_vars *vars)
{
	f_init(vars);
	clear_image(vars, 0);
	if (!vars->f[keycode])
		return (0);
	else
		vars->f[keycode](vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}

int	close_windows(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}
