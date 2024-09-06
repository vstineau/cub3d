#include "../../includes/cub3d.h"

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
void	free_parsing(t_parse *parse)
{
	if (parse->ea)
		free(parse->ea);
	if (parse->no)
		free(parse->no);
	if (parse->so)
		free(parse->so);
	if (parse->we)
		free(parse->we);
	if (parse->map)
		free(parse->map);
	if (parse->f_map && *parse->f_map)
		free_tab(parse->f_map);
}
