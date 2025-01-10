#include "../../includes/cub3d.h"

bool	check_format(char **rgb)
{
	int	i;

	i = -1;
	if (tab_len(rgb) != 3)
	{
		ft_err(NULL, "you need 3 RGB code separated by comma");
		return (true);
	}
	while (rgb[++i])
	{
		if (overflow(rgb[i]))
		{
			ft_err(rgb[i], "invalid number, the range is between 0 to 255");
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
	while (line[i])
	{
		if (line[i] == ',')
			count += 1;
		i++;
	}
	if (count != 2)
		return (true);
	return (false);
}

char	**check_color(char **split, char *ceiling_or_floor)
{
	const char	*line = find_in_map((char **)split, ceiling_or_floor);
	char		**rgb;

	if (!line)
		return (ft_putendl_fd("Missing color", 2), NULL);
	if (check_comma((char *)line))
		return (ft_putendl_fd("bad color format", 2), free((char *)line), NULL);
	rgb = ft_split(line, ',');
	free((char *)line);
	if (!rgb)
		return (NULL);
	if (check_format(rgb))
		return (free_tab((char **)rgb), NULL);
	return ((char **)rgb);
}

//unsigned int	get_color(int red, int green, int blue)
//{
//	unsigned int	color;
//
//	color = 0;
//	color = (color << 8) | red;
//	color = (color << 8) | green;
//	color = (color << 8) | blue;
//	return (color);
//}

void	atribute_color(char **c, char **f, t_parse *parse)
{
	parse->c_color.trgb[0] = ft_atoi(c[2]);
	parse->c_color.trgb[1] = ft_atoi(c[1]);
	parse->c_color.trgb[2] = ft_atoi(c[0]);
	free_tab(c);
	parse->f_color.trgb[0] = ft_atoi(f[2]);
	parse->f_color.trgb[1] = ft_atoi(f[1]);
	parse->f_color.trgb[2] = ft_atoi(f[0]);
	free_tab(f);
}
