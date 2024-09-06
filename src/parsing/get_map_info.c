#include "../../includes/cub3d.h"

//--------------------------GET_MAP_INFO.C-----------------------1
void	player_orientation_x(t_parse *parse, t_vars *v, int i, int j)
{
	if (parse->f_map[i][j] == 'E')
	{
		v->map[i][j].tile = FLOOR;
		v->player.dir.y = 1;
		v->player.pos.x = i;
		v->player.pos.y = j;
		v->player.plane.x = 0.85;
	}
	if (parse->f_map[i][j] == 'W')
	{
		v->map[i][j].tile = FLOOR;
		v->player.dir.y = -1;
		v->player.pos.x = i;
		v->player.pos.y = j;
		v->player.plane.x = -0.8;
	}
}

//--------------------------GET_MAP_INFO.C-----------------------2
void	player_orientation(t_parse *parse, t_vars *v, int i, int j)
{
	if (parse->f_map[i][j] == 'N')
	{
		v->map[i][j].tile = FLOOR;
		v->player.dir.x = -1;
		v->player.pos.x = i;
		v->player.pos.y = j;
		v->player.plane.y = 0.66;
	}
	if (parse->f_map[i][j] == 'S')
	{
		v->map[i][j].tile = FLOOR;
		v->player.dir.x = 1;
		v->player.pos.x = i;
		v->player.pos.y = j;
		v->player.plane.y = -0.8;
	}
	player_orientation_x(parse, v, i, j);
}

//--------------------------GET_MAP_INFO.C-----------------------3
void	fill_tiles(t_parse *parse, t_vars *v, int i)
{
	int	j;

	j = 0;
	while (parse->f_map[i][j])
	{
		if (parse->f_map[i][j] == '1')
			v->map[i][j].tile = WALL;
		if (parse->f_map[i][j] == '0')
			v->map[i][j].tile = FLOOR;
		if (parse->f_map[i][j] == '3')
			v->map[i][j].tile = DOOR_C;
		if (ft_isspace(parse->f_map[i][j]))
			v->map[i][j].tile = VOID;
		player_orientation(parse, v, i, j);
		j++;
	}
}

