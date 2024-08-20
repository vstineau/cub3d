#include "parsing.h"

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

char    *read_map(char *argv)
{
    const int		fd = open(argv, O_RDONLY);
    int				rd;
    char			*map;
    char			buffer[4097];

    rd = 4096;
    map = ft_calloc(1, 1);
    if (!map)
        return(close(fd), NULL);
    while (rd >= 4096)
    {
        rd = read(fd, buffer, 4096);
        if (rd == -1)
        {
            free(map);
            return (close(fd), NULL);
        }
        buffer[rd] = '\0';
        map = join_free(map, buffer);
    }
    return (close(fd), map);
}
int main(int ac, char **av)
{
	if(ac != 2)
		return (1);
	char *map = read_map(av[1]);
	printf("%s", map);
	return (0);
}