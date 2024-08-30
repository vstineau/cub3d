#include "../../includes/cub3d.h"

void	move_right(t_vars *v)
{
	if (v->map[(int)(v->player.pos.x + v->player.plane.x * v->player.movespeed)]
		[(int)v->player.pos.y].tile == FLOOR
		|| v->map[(int)(v->player.pos.x
		+ v->player.plane.x * v->player.movespeed)]
		[(int)v->player.pos.y].tile == DOOR_O)
	{
		v->player.pos.x += v->player.plane.x * v->player.movespeed;
	}
	if (v->map[(int)(v->player.pos.x)]
		[(int)(v->player.pos.y + v->player.plane.y
		* v->player.movespeed)].tile == FLOOR
		|| v->map[(int)(v->player.pos.x)]
		[(int)(v->player.pos.y + v->player.plane.y
		* v->player.movespeed)].tile == DOOR_O)
	{
		v->player.pos.y += v->player.plane.y * v->player.movespeed;
	}
}

void	move_left(t_vars *v)
{
	if (v->map[(int)(v->player.pos.x - v->player.plane.x * v->player.movespeed)]
		[(int)v->player.pos.y].tile == FLOOR
		|| v->map[(int)(v->player.pos.x
		- v->player.plane.x * v->player.movespeed)]
		[(int)v->player.pos.y].tile == DOOR_O)
	{
		v->player.pos.x -= v->player.plane.x * v->player.movespeed;
	}
	if (v->map[(int)(v->player.pos.x)]
		[(int)(v->player.pos.y - v->player.plane.y
		* v->player.movespeed)].tile == FLOOR
		|| v->map[(int)(v->player.pos.x)]
		[(int)(v->player.pos.y - v->player.plane.y
		* v->player.movespeed)].tile == DOOR_O)
	{
		v->player.pos.y -= v->player.plane.y * v->player.movespeed;
	}
}

void	handle_door(t_vars *v)
{
	if (v->map[(int)(v->player.pos.x + v->player.dir.x
			* (v->player.movespeed + 1))][(int)v->player.pos.y].tile == DOOR_O
			|| v->map[(int)(v->player.pos.x + v->player.dir.x
			* (v->player.movespeed + 1))][(int)v->player.pos.y].tile == DOOR_C)
	{
		v->map[(int)(v->player.pos.x + v->player.dir.x
				* (v->player.movespeed + 1))][(int)v->player.pos.y].tile ^= 1;
	}
	if (v->map[(int)(v->player.pos.x)][(int)(v->player.pos.y
		+ v->player.dir.y * (v->player.movespeed + 1))].tile == DOOR_O
		|| v->map[(int)(v->player.pos.x)][(int)(v->player.pos.y
		+ v->player.dir.y * (v->player.movespeed + 1))].tile == DOOR_C)
	{
		v->map[(int)(v->player.pos.x)][(int)(v->player.pos.y
				+ v->player.dir.y * (v->player.movespeed + 1))].tile ^= 1;
	}
}
