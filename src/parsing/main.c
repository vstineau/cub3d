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

int read_map(char *argv, t_parse *parse)
{
    const int		fd = open(argv, O_RDONLY);
    int				rd;
    char			buffer[4097];

    rd = 4096;
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
int main(int ac, char **av)
{
    t_parse parse;

	if(ac != 2)
		return (1);
	read_map(av[1], &parse);
	printf("%s", parse.map);
    free(parse.map);
	return (0);
}