#include "../../includes/cub3d.h"

// get the texture path of each wall sides
int	find_map_config(t_parse *p)
{
	const char	**split = (const char **)ft_split(p->map, '\n');
	char		**f_color;
	char		**c_color;

	if (!split)
		return (1);
	if (check_config_error((char **)split))
		return (free_tab((char **)split), 1);
	p->no = find_in_map((char **)split, "NO");
	p->so = find_in_map((char **)split, "SO");
	p->ea = find_in_map((char **)split, "EA");
	p->we = find_in_map((char **)split, "WE");
	if (!p->no || !p->so || !p->ea || !p->we)
		return (ft_err(NULL, "Invalid texture"), free_tab((char **)split), 1);
	f_color = check_color((char **)split, "F");
	if (!f_color || !*f_color)
		return (free_tab((char **)split), 1);
	c_color = check_color((char **)split, "C");
	if (!c_color || !*c_color)
		return (free_tab(f_color), free_tab((char **)split), 1);
	atribute_color(c_color, f_color, p);
	free_tab((char **)split);
	return (0);
}

int	fill_struc(t_parse *parse, t_vars *vars)
{
	const int	height = map_height(parse);
	const int	length = map_length(parse);
	int			i;

	i = 0;
	vars->map = ft_calloc(height, sizeof(t_point *));
	if (!vars->map)
		return (1);
	while (i < height)
	{
		vars->map[i] = ft_calloc(length + 1, sizeof(t_point));
		if (!vars->map[i])
			return (1);
		vars->map[i]->map_height = height;
		vars->map[i]->map_length = length;
		fill_tiles(parse, vars, i);
		i++;
	}
	return (0);
}

void	destroy_map(t_vars *v)
{
	int	i;
	int	length;

	i = 0;
	length = v->map[i]->map_height;
	while (i < length)
	{
		if (v->map[i])
		{
			free(v->map[i]);
			v->map[i] = NULL;
		}
		i++;
	}
	if (v->map)
	{
		free(v->map);
		v->map = NULL;
	}
}

void	destroy_mlx(t_vars *v)
{
	if (v->text.door)
		mlx_destroy_image(v->mlx, v->text.door);
	if (v->text.door_a)
		mlx_destroy_image(v->mlx, v->text.door_a);
	if (v->text.door_b)
		mlx_destroy_image(v->mlx, v->text.door_b);
	if (v->text.door_c)
		mlx_destroy_image(v->mlx, v->text.door_c);
	if (v->text.north)
		mlx_destroy_image(v->mlx, v->text.north);
	if (v->text.south)
		mlx_destroy_image(v->mlx, v->text.south);
	if (v->text.west)
		mlx_destroy_image(v->mlx, v->text.west);
	if (v->text.east)
		mlx_destroy_image(v->mlx, v->text.east);
	free_minimap(v);
	mlx_destroy_window(v->mlx, v->win);
	mlx_destroy_display(v->mlx);
	free(v->mlx);
}

int	parsing(t_parse *parse, t_vars *v, char *map)
{
	read_map(map, parse);
	if (all_map(map, parse))
		return (free_tab(parse->f_map), free(parse->map), destroy_mlx(v), 1);
	if (find_map_config(parse) || isolate_map(parse))
		return (destroy_mlx(v), free_parsing(parse), 1);
	if (load_textures(v, parse))
		return (destroy_mlx(v), free_parsing(parse), 1);
	if (fill_struc(parse, v))
		return (destroy_map(v), destroy_mlx(v), free_parsing(parse), 1);
	v->color_c = parse->c_color;
	v->color_f = parse->f_color;
	free_parsing(parse);
	return (0);
}
