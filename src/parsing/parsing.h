#ifndef PARSING_H
# define PARSING_H

# include "../../includes/cub3d.h"


typedef struct s_map
{
	char 	*map;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ground;
}			t_map;

# endif