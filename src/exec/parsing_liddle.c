#include "../../includes/cub3d.h"

static void	set_line(char **line_split, int i, t_point *map)
{
	int	j;
	int	t;
	(void)i;

	j = 0;
	while (j < 24)
	{
		t = ft_atoi(line_split[j]);
		if (t == 1)
			map[j].tile = WALL;
		else if (t == 3)
			map[j].tile = DOOR_C;
		else
			map[j].tile = FLOOR;
		j++;
	}
}

static t_point	**ta_to_point(char **map)
{
	t_point		**int_map;
	char		**ls;
	int			i;

	i = 0;
	int_map = ft_calloc(sizeof(t_point *), 24);
	while (i < 24)
	{
		int_map[i] = ft_calloc(sizeof(t_point) * 24, 1);
		ls = ft_split(map[i], ' ');
		set_line(ls, i, int_map[i]);
		i++;
	}
	return (int_map);
}

static char	*ft_join_free(char *line, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(line, buffer);
	free(line);
	if (!temp)
		exit(1);
	return (temp);
}

char    *read_map(char *argv)
{
    int        fd;
    int        rd;
    char    *map;
    char    buffer[4097];

    fd = open(argv, O_RDONLY);
    rd = 4096;
    map = ft_calloc(1, 1);
    if (!map)
        exit(1);
    while (rd >= 4096)
    {
        rd = read(fd, buffer, 4096);
        if (rd == -1)
        {
            free(map);
            return (NULL);
        }
        buffer[rd] = '\0';
        map = ft_join_free(map, buffer);
    }
    close(fd);
    return (map);
}


void	parsing_liddle(char *argv, t_vars *v)
{
	char *line;
	char **temp;

	line = read_map(argv);
	temp = ft_split(line, '\n');
	v->map = ta_to_point(temp);
}

