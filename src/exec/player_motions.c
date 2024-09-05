#include "../../includes/cub3d.h"

void	move_forward(t_vars *v)
{
	if (v->map[(int)(v->player.pos.x + v->player.dir.x
			* v->player.movespeed)][(int)v->player.pos.y].tile == FLOOR
			|| v->map[(int)(v->player.pos.x + v->player.dir.x
			* v->player.movespeed)][(int)v->player.pos.y].tile == DOOR_O)
	{
		v->player.pos.x += v->player.dir.x * v->player.movespeed;
	}
	if (v->map[(int)(v->player.pos.x)][(int)(v->player.pos.y
		+ v->player.dir.y * v->player.movespeed)].tile == FLOOR
		|| v->map[(int)(v->player.pos.x)][(int)(v->player.pos.y
		+ v->player.dir.y * v->player.movespeed)].tile == DOOR_O)
	{
		v->player.pos.y += v->player.dir.y * v->player.movespeed;
	}
}

void	move_backward(t_vars *v)
{
	if (v->map[(int)(v->player.pos.x - v->player.dir.x
			* v->player.movespeed)][(int)v->player.pos.y].tile == FLOOR
			|| v->map[(int)(v->player.pos.x - v->player.dir.x
			* v->player.movespeed)][(int)v->player.pos.y].tile == DOOR_O)
	{
		v->player.pos.x -= v->player.dir.x * v->player.movespeed;
	}
	if (v->map[(int)(v->player.pos.x)][(int)(v->player.pos.y
		- v->player.dir.y * v->player.movespeed)].tile == FLOOR
		|| v->map[(int)(v->player.pos.x)][(int)(v->player.pos.y
		- v->player.dir.y * v->player.movespeed)].tile == DOOR_O)
	{
		v->player.pos.y -= v->player.dir.y * v->player.movespeed;
	}
}

void	rotate_right(t_vars *v)
{
	v->player.old_dir_x = v->player.dir.x;
	v->player.dir.x = v->player.dir.x * cos(-v->player.rotspeed)
		- v->player.dir.y * sin(-v->player.rotspeed);
	v->player.dir.y = v->player.old_dir_x * sin(-v->player.rotspeed)
		+ v->player.dir.y * cos(-v->player.rotspeed);
	v->player.old_plane_x = v->player.plane.x;
	v->player.plane.x = v->player.plane.x * cos(-v->player.rotspeed)
		- v->player.plane.y * sin(-v->player.rotspeed);
	v->player.plane.y = v->player.old_plane_x * sin(-v->player.rotspeed)
		+ v->player.plane.y * cos(-v->player.rotspeed);
}

void	rotate_left(t_vars *v)
{
	v->player.old_dir_x = v->player.dir.x;
	v->player.dir.x = v->player.dir.x * cos(v->player.rotspeed)
		- v->player.dir.y * sin(v->player.rotspeed);
	v->player.dir.y = v->player.old_dir_x * sin(v->player.rotspeed)
		+ v->player.dir.y * cos(v->player.rotspeed);
	v->player.old_plane_x = v->player.plane.x;
	v->player.plane.x = v->player.plane.x * cos(v->player.rotspeed)
		- v->player.plane.y * sin(v->player.rotspeed);
	v->player.plane.y = v->player.old_plane_x * sin(v->player.rotspeed)
		+ v->player.plane.y * cos(v->player.rotspeed);
}
