#include "../../includes/cub3d.h"

int	check_pos(char **map, int x, int y, t_parse *parse)
{
	if (y - 1 < 0 || x - 1 < 0)
		return (1);
	if (x + 1 >= map_length(parse) || y + 1 >= map_height(parse))
		return (1);
	if (check_char(map[y - 1][x]))
		return (1);
	else if (check_char(map[y + 1][x]))
		return (1);
	else if (check_char(map[y][x - 1]))
		return (1);
	else if (check_char(map[y][x + 1]))
		return (1);
	else
		return (0);
}

void	print_err_map(char **map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == y && j == x)
				print_color_error(BG_GREEN, B_RED, map[i][j]);
			else
				print_color_error(BG_GREEN, BHI_WHITE, map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	check_surrounded(t_parse *parse)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (parse->f_map[y])
	{
		x = 0;
		while (parse->f_map[y][x])
		{
			if (parse->f_map[y][x] == '0' || parse->f_map[y][x] == '3'
				|| parse->f_map[y][x] == 'N' || parse->f_map[y][x] == 'W'
					|| parse->f_map[y][x] == 'E' || parse->f_map[y][x] == 'S')
			{
				if (check_pos(parse->f_map, x, y, parse))
					return (ft_err(NULL, "map not surrounded"),
						print_err_map(parse->f_map, x, y), 1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_player_nb(char **map, t_parse *parse)
{
	int		i;
	int		j;
	bool	player;

	player = false;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == 'S') && player == true)
				return (ft_err(NULL, "multiple player found"),
					print_err_map(parse->f_map, j, i), 1);
			if ((map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == 'S') && player == false)
					player = true;
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_format(char **map, t_parse *parse)
{
	int	x;
	int	y;

	if (check_player_nb(map, parse))
		return (1);
	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != '3'
				&& map[y][x] != 'N' && map[y][x] != 'S' && map[y][x] != 'E'
					&& map[y][x] != 'W' && !ft_isspace(map[y][x]))
				return (ft_err(&map[y][x], "Wrong map input"),
					print_err_map(parse->f_map, x, y), 1);
			x++;
		}
		y++;
	}
	return (check_surrounded(parse));
}
