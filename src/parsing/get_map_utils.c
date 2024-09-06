#include "../../includes/cub3d.h"

//--------------------------GET_MAP_UTILS.C-----------------------1
int	map_length(t_parse *parse)
{
	int		i;
	size_t	longest;

	i = 0;
	longest = 0;
	while (parse->f_map[i])
	{
		if (ft_strlen(parse->f_map[i]) > longest)
			longest = ft_strlen(parse->f_map[i]);
		i++;
	}
	return (longest);
}

//--------------------------GET_MAP_UTILS.C-----------------------2
int	map_height(t_parse *parse)
{
	int	height;

	height = 0;
	while (parse->f_map[height])
		height++;
	return (height);
}

//--------------------------GET_MAP_UTILS.C-----------------------3
char *cpymap(char *s)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (dst == 0)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

//--------------------------GET_MAP_UTILS.C-----------------------4
char	*cpy_and_fill(char *src, int len)
{
	int		i;
	char	*dest;

	i = 0;
	dest = ft_calloc(len + 1, sizeof(char));
	ft_memset(dest, ' ', len - 1);
	if (!src)
		return (NULL);
	while (src[i])
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

//--------------------------PARSING_UTILS.C----------------------------1
int tab_len(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}