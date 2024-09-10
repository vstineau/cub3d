#include "../../includes/cub3d.h"

int	all_map(char *av, t_parse *parse)
{
	const int	fd = open(av, O_RDONLY);
	int			count;
	int			i;

	if (fd == -1)
		return (1);
	i = -1;
	count = 1;
	while (parse->map[++i])
		if (parse->map[i] == '\n')
			count++;
	parse->f_map = ft_calloc(count + 1, sizeof(char *));
	if (!parse->f_map)
		return (close(fd), 1);
	i = 0;
	parse->f_map[i] = get_next_line(fd);
	if (!parse->f_map[i])
		return (get_next_line(-42), 1);
	while (parse->f_map[i])
	{
		if (!parse->f_map[i])
			return (get_next_line(-42), close(fd), 1);
		parse->f_map[++i] = get_next_line(fd);
	}
	return (close(fd), 0);
}

int	isolate_map(t_parse *parse)
{
	int		i;
	int		j;
	char	**newmap;

	i = 0;
	j = 0;
	while (parse->f_map[i] && skip_cmp(parse->f_map[i], "1", 1))
		i++;
	if (parse->f_map[i] == NULL)
		return (ft_err(NULL, "no map detected"), 1);
	while (parse->f_map[i])
	{
		i++;
		j++;
	}
	newmap = ft_calloc(j + 1, sizeof(char *));
	if (!newmap)
		return (1);
	j = i - j;
	i = 0;
	while (parse->f_map[j])
		newmap[i++] = cpy_and_fill(parse->f_map[j++], parse->map_length);
	free_tab(parse->f_map);
	parse->f_map = newmap;
	return (check_map_format(parse->f_map, parse));
}
