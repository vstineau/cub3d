#include "../../includes/cub3d.h"

static void	raycast_five(t_vars *v, t_img *texture, t_dir d)
{
	v->text.x = (int)(v->text.wallx * (double)texture->width);
	if (d == NORTH && v->player.ray_dir.y > 0)
		v->text.x = texture->width - v->text.x - 1;
	else if (d == EAST)
		v->text.x = texture->width - v->text.x - 1;
	else if (d == WEST && v->player.ray_dir.x < 0)
		v->text.x = texture->width - v->text.x - 1;
	else if (d == DOOR)
		v->text.x = texture->width - v->text.x - 1;
	v->text.step = 1.0 * texture->height / v->player.line_height;
}

static void	raycast_four(t_vars *v, t_vecti map, t_dir *d)
{
	if (v->map[map.x][map.y].tile == DOOR_C)
		*d = DOOR;
	else if (v->player.side == 0 && v->player.ray_dir.x > 0)
		*d = WEST;
	else if (v->player.side == 0 && v->player.ray_dir.x <= 0)
		*d = EAST;
	else if (v->player.side == 1 && v->player.ray_dir.y > 0)
		*d = NORTH;
	else if (v->player.side == 1 && v->player.ray_dir.y <= 0)
		*d = SOUTH;
	if (*d == DOOR)
		raycast_five(v, v->text.door, *d);
	else if (*d == NORTH)
		raycast_five(v, v->text.north, *d);
	else if (*d == SOUTH)
		raycast_five(v, v->text.south, *d);
	else if (*d == EAST)
		raycast_five(v, v->text.east, *d);
	else if (*d == WEST)
		raycast_five(v, v->text.west, *d);
	if (v->text.x < 0)
			v->text.x = 0;
	v->text.pos = ((double)v->player.draw_start
			- (double)WIN_HEIGHT / 2
			+ (double)v->player.line_height / 2) * v->text.step;
}

static void	raycast_three(t_vars *v, t_vecti map, t_dir *d)
{
	if (v->player.side == 0)
		v->player.perpwalldist
			= (v->player.side_dist.x - v->player.delta_dist.x);
	else
		v->player.perpwalldist
			= (v->player.side_dist.y - v->player.delta_dist.y);
	v->player.line_height = (int)(WIN_HEIGHT / v->player.perpwalldist);
	v->player.draw_start = -v->player.line_height / 2 + WIN_HEIGHT / 2;
	if (v->player.draw_start < 0)
		v->player.draw_start = 0;
	v->player.draw_end = v->player.line_height / 2 + WIN_HEIGHT / 2;
	if (v->player.draw_end >= WIN_HEIGHT)
		v->player.draw_end = WIN_HEIGHT - 1;
	if (v->player.side == 0)
		v->text.wallx = v->player.pos.y
			+ v->player.perpwalldist * v->player.ray_dir.y;
	else
		v->text.wallx = v->player.pos.x
			+ v->player.perpwalldist * v->player.ray_dir.x;
	v->text.wallx = fmod(v->text.wallx, 1);
	raycast_four(v, map, d);
}

static void	raycast_two(t_vars *v, t_vecti map, t_dir *d)
{
	while (v->player.hit == 0)
	{
		if (map.x < 0 || map.x >= WIN_WIDTH
			|| map.y < 0 || map.y >= WIN_HEIGHT)
			break ;
		if (v->player.side_dist.x < v->player.side_dist.y)
		{
			v->player.side_dist.x += v->player.delta_dist.x;
			map.x += (int)v->player.step.x;
			v->player.side = 0;
		}
		else
		{
			v->player.side_dist.y += v->player.delta_dist.y;
			map.y += (int)v->player.step.y;
			v->player.side = 1;
		}
		if (v->map[map.x][map.y].tile == WALL
			|| v->map[map.x][map.y].tile == DOOR_C)
			v->player.hit = 1;
	}
	raycast_three(v, map, d);
}

void	raycast_one(t_vars *v, t_vecti map, t_dir *d)
{
	if (v->player.ray_dir.x < 0)
	{
		v->player.step.x = -1;
		v->player.side_dist.x = (v->player.pos.x - map.x)
			* v->player.delta_dist.x;
	}
	else
	{
		v->player.step.x = 1;
		v->player.side_dist.x = (map.x + 1.0 - v->player.pos.x)
			* v->player.delta_dist.x;
	}
	if (v->player.ray_dir.y < 0)
	{
		v->player.step.y = -1;
		v->player.side_dist.y = (v->player.pos.y - map.y)
			* v->player.delta_dist.y;
	}
	else
	{
		v->player.step.y = 1;
		v->player.side_dist.y = (map.y + 1.0 - v->player.pos.y)
			* v->player.delta_dist.y;
	}
	raycast_two(v, map, d);
}
