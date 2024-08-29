#include "../../includes/cub3d.h"

void	move_right(t_vars *v)
{
	if (v->map[(int)(v->player.pos.x + v->player.plane.x * v->player.movespeed)]
		[(int)v->player.pos.y].tile == FLOOR)
	{
		v->player.pos.x += v->player.plane.x * v->player.movespeed;
	}
	if (v->map[(int)(v->player.pos.x)]
		[(int)(v->player.pos.y + v->player.plane.y
		* v->player.movespeed)].tile == FLOOR)
	{
		v->player.pos.y += v->player.plane.y * v->player.movespeed;
	}
}

void	move_left(t_vars *v)
{
	if (v->map[(int)(v->player.pos.x - v->player.plane.x * v->player.movespeed)]
		[(int)v->player.pos.y].tile == FLOOR)
	{
		v->player.pos.x -= v->player.plane.x * v->player.movespeed;
	}
	if (v->map[(int)(v->player.pos.x)]
		[(int)(v->player.pos.y - v->player.plane.y
		* v->player.movespeed)].tile == FLOOR)
	{
		v->player.pos.y -= v->player.plane.y * v->player.movespeed;
	}
}
