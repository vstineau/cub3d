#include "../../includes/cub3d.h"

void	move_forward(t_vars *v)
{
	v->player.y--;
}

void	move_backward(t_vars *v)
{
	v->player.y++;
}

void	move_right(t_vars *v)
{
	v->player.x++;
}

void	move_left(t_vars *v)
{
	v->player.x--;
}

