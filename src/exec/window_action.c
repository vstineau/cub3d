#include "../../includes/cub3d.h"

//LISTE DES KEYCODES : https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h

static void	f_init(t_vars *vars)
{
	ft_memset(vars->f, 0, 0xFFFF);
	vars->f[XK_Escape] = (void *)close_windows;
	vars->f[XK_Left] = (void *)rotate_left;
	vars->f[XK_a] = (void *)move_left;
	vars->f[XK_Right] = (void *)rotate_right;
	vars->f[XK_d] = (void *)move_right;
	vars->f[XK_Up] = (void *)move_forward;
	vars->f[XK_w] = (void *)move_forward;
	vars->f[XK_Down] = (void *)move_backward;
	vars->f[XK_s] = (void *)move_backward;
	vars->f[XK_f] = (void *)handle_door;
	vars->f[XK_m] = (void *)lock_unlock_mouse;
}

int	window_action(int keycode, t_vars *vars)
{
	f_init(vars);
	printf("%d\n", keycode);
	if (keycode >= 0xFFFF || !vars->f[keycode])
		return (0);
	else
		vars->f[keycode](vars);
	return (0);
}

int	close_windows(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}
