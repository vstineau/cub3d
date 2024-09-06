#include "../../includes/cub3d.h"

//read the map and store it in a char*
int	read_map(char *argv, t_parse *parse)
{
	const int		fd = open(argv, O_RDONLY);
	int				rd;
	char			buffer[4097];

	rd = 4096;
	if (fd == -1)
		return (1);
	parse->map = ft_calloc(1, 1);
	if (!parse->map)
		return (close(fd), 1);
	while (rd >= 4096)
	{
		rd = read(fd, buffer, 4096);
		if (rd == -1)
		{
			free(parse->map);
			return (close(fd), 1);
		}
		buffer[rd] = '\0';
		parse->map = join_free(parse->map, buffer);
	}
	return (close(fd), 0);
}

//skip white space before and after the argument and check errors
char	*isolate_element(char *line, char *key)
{
	int	i;
	int	end;
	int	check;

	i = 0;
	line = ft_strnstr(line, key, ft_strlen(line));
	while (line[i] && !ft_isspace(line[i]))
		i++;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == '\0')
		return (NULL);
	end = i;
	while (line[end] && !ft_isspace(line[end]))
		end++;
	check = end;
	while (line[check] && ft_isspace(line[check]))
		check++;
	if (line[check] != 0)
		return (NULL);
	return (ft_substr(line, i, end - i));
}

// check if map config is valid
int	check_config_error(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] && skip_cmp(map[i], "NO", 0) && skip_cmp(map[i], "SO", 0)
			&& skip_cmp(map[i], "WE", 0) && skip_cmp(map[i], "EA", 0)
			&& skip_cmp(map[i], "F", 0) && skip_cmp(map[i], "C", 0)
			&& skip_cmp(map[i], "1", 1))
			return (ft_err(map[i], "Invalid format"), 1);
		i++;
	}
	return (0);
}

//browse map to find key
char	*find_in_map(char **map, char *key)
{
	int		i;
	char	*res;
	bool	found;

	res = NULL;
	found = false;
	i = 0;
	while (map[i])
	{
		if (map[i] && ft_strnstr(map[i], key, ft_strlen(map[i])))
		{
			if (found == true)
				return (free(res), NULL);
			found = true;
			res = isolate_element(map[i], key);
		}
		i++;
	}
	return (res);
}
