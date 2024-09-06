#include "../../includes/cub3d.h"

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

int	check_file(char *argv)
{
	size_t	lenght;

	lenght = ft_strlen(argv);
	if (lenght < 5)
	{
		ft_err(argv, "invalid file format");
		return (1);
	}
	if (ft_strcmp(&argv[lenght - 4], ".cub")
		|| !ft_strcmp(&argv[lenght - 5], "/.cub"))
	{
		ft_err(argv, "invalid file format");
		return (1);
	}
	else
		return (0);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

//skip white space and cmp
int	skip_cmp(char *line, char *cmp, int map)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == '\0')
		return (1);
	if (ft_strncmp(line + i, cmp, ft_strlen(cmp)) != 0)
		return (1);
	if (map == 0)
	{
		i += ft_strlen(cmp);
		if (!ft_isspace(line[i]))
			return (1);
	}
	return (0);
}

int	check_char(char c)
{
	if (c == '1' || c == '0' || c == '3'
		|| c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0);
	else
		return (1);
}
