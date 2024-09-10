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
# include "color.h"
# include "inline.h"

//SIZE OF THE SCREEN
# define WIN_WIDTH 960
# define WIN_HEIGHT 540

//typedef struct	s_img
//{
//	XImage			*image;
//	Pixmap			pix;
//	GC				gc;
//	int				size_line;
//	int				bpp;
//	int				width;
//	int				height;
//	int				type;
//	int				format;
//	char			*data;
//	XShmSegmentInfo	shm;
//}	

typedef enum s_tile
{
	DOOR_O,
	DOOR_C,
	FLOOR,
	WALL,
	VOID
}				t_tile;

//enum to define orientation
typedef enum s_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	DOOR
}	t_dir;

typedef struct s_vecti
{
	int	x;
	int	y;
}				t_vecti;

typedef struct s_vect
{
	double	x;
	double	y;
}				t_vect;

typedef struct s_text
{
	int			x;
	int			y;
	int			text_door;
	double		wallx;
	double		step;
	double		pos;
	t_img		*win;
	t_img		*east;
	t_img		*west;
	t_img		*south;
	t_img		*north;
	t_img		*door;
	t_img		*door_a;
	t_img		*door_b;
	t_img		*door_c;
}				t_text;

typedef struct s_mini
{
	double	x;
	double	y;
	t_img	*floor;
	t_img	*player;
	t_img	*wall;
	t_img	*door;
	t_img	*nothing;
} 			t_mini;

typedef struct s_player
{
	t_vect		pos;
	t_vect		dir;
	t_vect		plane;
	t_vect		ray_dir;
	t_vect		side_dist;
	t_vect		delta_dist;
	t_vect		step;
	double		perpwalldist;
	double		movespeed;
	double		rotspeed;
	double		old_dir_x;
	double		old_plane_x;
	double		camera_x;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			hit;
	int			side;
}	t_player;

typedef struct s_point
{
	t_tile			tile;
	t_dir			di;
	int				map_height;
	int				map_length;
}					t_point;

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
	int			mouse_unlock;
	int			color_f;
	int			color_c;
	t_vecti		mouse_pos;
	t_player	player;
	t_text		text;
	t_mini		mini;
	t_point		**map;
	t_data		data;
	t_fn		f[0xFFFF];
}				t_vars;

//struct used for map parsing
typedef struct s_parse
{
	char				*map;
	char				**f_map;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	int					map_length;
	int					map_height;
	bool				player;
	unsigned int		f_color;
	unsigned int		c_color;
}						t_parse;

/*---------------PLAYER MOTIONS------------------------------*/

void	move_forward(t_vars *v);
void	move_backward(t_vars *v);
void	rotate_left(t_vars *v);
void	rotate_right(t_vars *v);
void	move_left(t_vars *v);
void	move_right(t_vars *v);
void	handle_door(t_vars *v);

/*---------------WINDOW ACTIONS------------------------------*/

int		window_action(int keycode, t_vars *vars);
int		close_windows(t_vars *vars);
int		mouse_in_the_midle(t_vars *v);
void	lock_unlock_mouse(t_vars *v);

/*----------------DRAW ON IMAGE------------------------------*/

int		cub_loop(t_vars *v);
void	start_image(t_vars *v);
void	color_ceiling(t_vars *v, int color);
void	color_floor(t_vars *v, int color);
void	clear_image(t_vars *v, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*----------------RAYCASTING---------------------------------*/

void	init_raycasting(t_vars *v);
void	raycasting(t_vars *v);
void	raycast_one(t_vars *v, t_vecti map, t_dir *d);

/*----------------TEXTURES-----------------------------------*/

int		load_textures(t_vars *v, t_parse *p);

/*----------------PARSING-------------------------------------*/
int		parsing(t_parse *parse, t_vars *v, char *map);
int		read_map(char *argv, t_parse *parse);
int		check_file(char *argv);
void	destroy_mlx(t_vars *v);
void	destroy_map(t_vars *v);
int		check_config_error(char **map);
void	free_tab(char **tab);
char	*find_in_map(char **map, char *key);
void	ft_err(char *arg, char *err);
char	**check_color(char **split, char *ceiling_or_floor);
void	atribute_color(char **c, char **f, t_parse *parse);
int		all_map(char *av, t_parse *parse);
int		isolate_map(t_parse *parse);
void	free_parsing(t_parse *parse);
int		map_height(t_parse *parse);
int		map_length(t_parse *parse);
void	fill_tiles(t_parse *parse, t_vars *v, int i);
int		ft_isspace(int c);
int		skip_cmp(char *line, char *cmp, int map);
char	*cpy_and_fill(char *src, int len);
int		check_map_format(char **map, t_parse *parse);
char	*join_free(char *line, char *buffer);
int		check_char(char c);
int		tab_len(char **tab);
bool	overflow(char *s);
void	print_color_error(char *color_one, char *color_two, char c);
void	free_minimap(t_vars *v);

/*----------------MINIMAP-------------------------------------*/
void	draw_minimap(t_vars *v);

#endif
