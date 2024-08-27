#ifndef CUB3D_H
# define CUB3D_H

//FUNCTIONS AUTHORIZED
//open, close, read, write,
//printf, malloc, free,
//perror, strerror, exit
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <math.h>
# include <stdint.h>
# include <unistd.h>
# include "../.minilibx-linux/mlx.h"
# include "../.minilibx-linux/mlx_int.h"
# include "../.LIBFT/libft.h"

# define WIN_WIDTH 960
# define WIN_HEIGHT 540

typedef enum s_tile
{
	FLOOR,
	WALL,
	DOOR,
	VOID
}	t_tile;

//enum to define player's spawning orientation
typedef enum s_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_dir;

// y and x is the player position
// dir_x and dir_y is the direction of the player
// plane_x and plane_y is the camera plane of the player
typedef struct    s_player
{
    float		x;
    float		y;
    float		dir_x;
    float		dir_y;
    float		plane_x;
    float		plane_y;
	t_dir		dir;
}			t_player;

typedef struct s_point
{
	t_tile		tile;
	int			x;
	int			y;
	t_dir		di;
}				t_point;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bit_per_pixel;
	int			line_length;
	int			endian;
	float		offset_x;
	float		offset_y;
}				t_data;

typedef struct s_vars	t_vars;

typedef void			(*t_fn)(t_vars *vars);

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	float		err;
	t_player	player;
	t_point		**map;
	t_data		data;
	t_fn		f[0xFFFF];
}				t_vars;

//struct used for map parsing
typedef struct s_parse
{
	char 				*map;
	char				**f_map;
	char				*north;
	char				*south;
	char				*west;
	char				*east;
	unsigned int		f_color;
	unsigned int		c_color;
}						t_parse;

int	read_map(char *argv, t_parse *parse);

#endif
