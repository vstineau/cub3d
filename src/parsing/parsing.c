#include "parsing.h"
#include <stdio.h>

void    ft_err(char *arg, char *err)
{
    ft_putstr_fd("Error: ", 2);
    if(arg)
        ft_putstr_fd(arg, 2);
    ft_putendl_fd(err, 2);
}
char	*join_free(char *line, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(line, buffer);
	if (!temp)
		return (NULL);
	if (line)
		free(line);
	return (temp);
}

int    check_file(char *argv)
{
    size_t    lenght;

    lenght = ft_strlen(argv);
    if (lenght < 5)
    {
        ft_err(argv, ": invalid file format");
        return (1);
    }
    if (ft_strcmp(&argv[lenght - 4], ".cub")
        || !ft_strcmp(&argv[lenght - 5], "/.cub"))
    {
		ft_err(argv, ": invalid file format");
        return (1);
    }
    else
        return (0);
}

//read the map and store it in a char*
int read_map(char *argv, t_parse *parse)
{
    const int		fd = open(argv, O_RDONLY);
    int				rd;
    char			buffer[4097];

    rd = 4096;
	if(fd == -1)
		return (1);
    parse->map = ft_calloc(1, 1);
    if (!parse->map)
        return(close(fd), 1);
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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

//free pre_parsing struct
void    free_parsing(t_parse *parse)
{
	if(parse->east)
		free(parse->east);
	if(parse->north)
		free(parse->north);
	if(parse->south)
		free(parse->south);
	if(parse->west)
		free(parse->west);
	if(parse->map)
		free(parse->map);
	if(parse->f_map)
		free_tab(parse->f_map);
}


//do i really need to explain what this does?
int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

//skip white space before and after the argument and check errors
char    *isolate_element(char *line, char * key)
{
    int	i;
	int	end;
	int	check;

    i = 0;
    line = ft_strnstr(line, key, ft_strlen(line));
    while(line[i] && !ft_isspace(line[i]))
		i++;
    while(line[i] && ft_isspace(line[i]))
		i++;
	if(line[i] == '\0')
		return (NULL);
	end = i;
	while(line[end] && !ft_isspace(line[end]))
		end++;
	check = end;
	while(line[check] && ft_isspace(line[check]))
		check++;
	if(line[check] != 0)
		return (NULL);
    return(ft_substr(line, i, end - i));
}


//skip white space and cmp
int skip_cmp(char *line, char *cmp)
{
    int i;

    i = 0;
	while(line[i] && ft_isspace(line[i]))
		i++;
	if(line[i] == '\0')
		return (1);
    return(ft_strncmp(line + i, cmp, ft_strlen(cmp)));
}

// check if map config is valid
int check_config_error(char **map)
{
    int i;

    i = 0;
    while(map[i])
    {
        if(map[i] && skip_cmp(map[i], "NO") && skip_cmp(map[i], "SO")
            && skip_cmp(map[i], "WE") && skip_cmp(map[i], "EA")
                && skip_cmp(map[i], "F") && skip_cmp(map[i], "C")
                    && skip_cmp(map[i], "1"))
                        return (printf("'%s'", map[i]), 1);
        i++;
    }
    return (0);
}

//browse map to find key
char *find_in_map(char **map, char *key)
{
    int i;
    char *res;
    bool found;

    res = NULL;
    found = false;
    i = 0;
    while(map[i])
    {
        if(map[i] && ft_strnstr(map[i], key, ft_strlen(map[i])))
        {
            if(found == true)
                return(free(res),
                    ft_err(key, " found multiple times"), NULL);
            found = true;
            res = isolate_element(map[i], key);
        }
        i++;
    }
    return (res);
}

int tab_len(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}

bool	only_digit_string(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (true);
	}
	return (false);
}

bool	overflow(char *s)
{
	int			i;
	int			sign;
	int			nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (only_digit_string(s + i))
		return (true);
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = (nbr * 10 + s[i++] - '0');
		if (nbr * sign > 255 || nbr * sign < 0)
			return (true);
	}
	return (false);
}

bool     check_format(char **rgb)
{
    int i;

    i = -1;
    if(tab_len(rgb) != 3)
	{
		ft_putendl_fd("you need 3 RGB code separated by comma", 2);
        return (true);
	}
    while(rgb[++i])
    {
        if(overflow(rgb[i]))
		{
			ft_err(rgb[i], ": invalid number, the range is between 0 to 255");
            return (true);
		}
    }
    return (false);
}

bool	check_comma(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(line[i])
	{
		if(line[i] == ',')
			count += 1;
		i++;
	}
	if(count != 2)
		return (true);
	return (false);
}

char    **check_color(char **split, char *ceiling_or_floor)
{
    const char *line = find_in_map((char **)split, ceiling_or_floor);
    char        **rgb;
    int         i;

    i = 0;
    if(!line)
		return (ft_putendl_fd("No color detected", 2), NULL);
	if(check_comma((char *)line))
		return (ft_putendl_fd("bad color format", 2), free((char *)line), NULL);
    rgb = ft_split(line, ',');
    free((char *)line);
    if(!rgb)
        return (NULL);
    if(check_format(rgb))
        return (free_tab((char **)rgb), NULL);
    return ((char **)rgb);
}

unsigned int    get_color(int red, int green, int blue)
{
    unsigned int    color;

    color = 0;
	color = (color << 8) | red;
	color = (color << 8) | green;
	color = (color << 8) | blue;
    return (color);
}

void	atribute_color(char **c, char **f, t_parse *parse)
{
	parse->c_color = get_color(ft_atoi(c[0]), ft_atoi(c[1]), ft_atoi(c[2]));
	free_tab(c);
	parse->f_color = get_color(ft_atoi(f[0]), ft_atoi(f[1]), ft_atoi(f[2]));
	free_tab(f);
}

void print_map(char **map)
{
	printf("           ---map---         \n");
	for(int i = 0; map[i]; i++)
		printf("|%s|\n", map[i]);
	printf("           ---map---         \n");
}

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
	if(!parse->f_map[i])
			return (close(fd), free_tab(parse->f_map), 1);
	while (parse->f_map[i])
	{
		if(!parse->f_map[i])
			return (close(fd), 1);
		parse->f_map[++i] = get_next_line(fd);
	}
	return (close(fd), 0);
}

// get the texture path of each wall sides
int find_map_config(t_parse *parse)
{
    const char  **split = (const char **)ft_split(parse->map, '\n');
    char        **f_color;
    char        **c_color;
    int i;

    i = 0;
    if(!split)
        return (1);
    if(check_config_error((char **)split))
        return (ft_err(NULL, "invalid map"), free_tab((char **)split), 1);
    parse->north = find_in_map((char **)split, "NO");
    parse->south = find_in_map((char **)split, "SO");
    parse->east = find_in_map((char **)split, "EA");
    parse->west = find_in_map((char **)split, "WE");
    f_color = check_color((char **)split, "F");
    if(!f_color || !*f_color)
		return (free_tab((char **)split), 1);
    c_color = check_color((char **)split, "C");
    if(!c_color || !*c_color)
		return (free_tab(f_color), free_tab((char **)split), 1);
	atribute_color(c_color, f_color, parse);
    free_tab((char **)split);
    return (0);
}

int check_map_format(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(map[y][x] != '1' && map[y][x] != '0' && map[y][x] != '3'
				&& map[y][x] != 'N' && map[y][x] != 'S' && map[y][x] != 'E'
					&& map[y][x] != 'W' && !ft_isspace(map[y][x]))
						return (ft_err(map[y], "Bad map format"), 1);
			x++;
		}
		y++;
	}
	return (0);
}


int	isolate_map(t_parse *parse)
{
	int		i;
	int		j;
	char	**newmap;

	i = 0;
	j = 0;
	while(parse->f_map[i] && skip_cmp(parse->f_map[i], "1"))
		i++;
	if(parse->f_map[i] == NULL)
		return (ft_err(NULL, "no map detected"), 1);
	while(parse->f_map[i])
	{
		i++;
		j++;
	}
	newmap = ft_calloc(j + 1, sizeof(char *));
	if(!newmap)
		return (1);
	j = i - j;
	i = 0;
	while(parse->f_map[j])
		newmap[i++] = ft_strdup(parse->f_map[j++]);
	free_tab(parse->f_map);
	parse->f_map = newmap;
	return (check_map_format(parse->f_map));
}
int	map_lenth(t_parse *parse)
{
	int		i;
	size_t	longest;

	i = 0;
	longest = 0;
	while(parse->f_map[i])
	{
		if(ft_strlen(parse->f_map[i]) > longest)
			longest = ft_strlen(parse->f_map[i]);
		i++;
	}
	return (longest);
}

int	map_height(t_parse *parse)
{
	int	height;

	height = 0;
	while(parse->f_map[height])
		height++;
	return (height);
}

char	*cpy_and_fill(char *src, int len)
{
	int		i;
	char	*dest;

	i = 0;
	dest = ft_calloc(len + 1, sizeof(char));
	ft_memset(dest, ' ', len - 1);
	if (!src)
		return (NULL);
	while(src[i])
	{
		if (src[i] && src[i] == '\n')
			i++;
		else
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}


int check_char(char c)
{
	// printf("%c", c);
	if(c == '1' || c == '0' || c == '3'
		|| c == 'N' || c == 'S' || c == 'W' || c == 'E')
			return (0);
	else
		return (1);
}

int	check_pos(char **map, int x, int y, t_parse *parse)
{
	(void)parse;
	if (y - 1 < 0 || x - 1 < 0)
		return (printf("1 %s\n", map[y]), 1);
	if (x + 1 >= map_lenth(parse) || y + 1 >= map_height(parse))
		return (printf("2 %s\n", map[y]), 1);
	if (check_char(map[y - 1][x]))
		return (printf("3 %s\n", map[y]), 1);
	else if(check_char(map[y + 1][x]))
		return (printf("3 %s\n", map[y]), 1);
	else if(check_char(map[y][x - 1]))
		return (printf("3 %s\n", map[y]), 1);
	else if(check_char(map[y][x + 1]))
		return (printf("3 %s\n", map[y]), 1);
	else
		return (0);
}



int check_surrounded(t_parse *parse)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(parse->f_map[y])
	{
		x = 0;
		while(parse->f_map[y][x])
		{
			if(parse->f_map[y][x] == '0' || parse->f_map[y][x] == '3'
				|| parse->f_map[y][x] == 'N' || parse->f_map[y][x] == 'W'
					|| parse->f_map[y][x] == 'E' || parse->f_map[y][x] == 'S')
			{
				if (check_pos(parse->f_map, x, y, parse))
					return (ft_err(NULL, "map not surrounded"), 1);
			}
			x++;
		}
		// printf("\n");
		y++;
	}
	return (0);
}

int	resize_map(t_parse *parse)
{
	const int	len = map_lenth(parse);
	printf("len = %d\n", len);
	printf("height = %d\n", map_height(parse));
	const char	**resized = ft_calloc(map_height(parse) + 1, sizeof(char *));
	int			i;

	i = 0;
	if(!resized)
		return (1);
	while(parse->f_map[i])
	{
		resized[i] = cpy_and_fill(parse->f_map[i], len);
		if(!resized[i])
			return(free_tab((char **)resized), 1);
		i++;
	}
	free_tab(parse->f_map);
	parse->f_map = (char **)resized;
	return (check_surrounded(parse));
}

int main(int ac, char **av)
{
    t_parse parse;

	ft_memset(&parse, 0, sizeof(t_parse));
	if(ac != 2 || check_file(av[1]))
		return (1);
	read_map(av[1], &parse);
    if(all_map(av[1], &parse) || find_map_config(&parse) || isolate_map(&parse))
		return (free_parsing(&parse), 1);
	if(resize_map(&parse))
		return (free_parsing(&parse), 1);
    // ft_printf("'%s'\n", parse.map);
	printf("----------------[P A R S E D]-----------------\n");
	printf("NO = '%s'\n", parse.north);
	printf("SO = '%s'\n", parse.south);
	printf("EA = '%s'\n", parse.east);
	printf("WE = '%s'\n", parse.west);
	printf("f_color = '%d'\n", parse.f_color);
	printf("c_color = '%d'\n", parse.c_color);
    print_map(parse.f_map);
	printf("-----------------[P A R S E D]-----------------\n");
    free_parsing(&parse);
	return (0);
}
