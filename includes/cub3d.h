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
}    t_dir;

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
	double	wallx;
	double	step;
	double	pos;
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

typedef struct	s_player
{
	t_vect		pos;
	t_vect		dir;
	t_vect		plane;
	t_vect		ray_dir;
	t_vect		side_dist;
	t_vect		delta_dist;
	t_vect		step;
	double			perpwalldist;
	double			movespeed;
	double			rotspeed;
	double			old_dir_x;
	double			old_plane_x;
	double			camera_x;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				hit;
	int				side;
}	t_player;

typedef struct s_point
{
	t_tile		tile;
	t_dir			di;
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
	void			*mlx;
	void			*win;
	int				mouse_unlock;
	int				color_f;
	int				color_c;
	t_vecti		mouse_pos;
	t_player	player;
	t_text		text;
	t_point		**map;
	t_data		data;
	t_fn		f[0xFFFF];
}				t_vars;

//struct used for map parsing
typedef struct s_parse
{
	char 				*map;
	char				**f_map;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
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

int	load_textures(t_vars *v, t_parse *p);

/*----------------PARSING-------------------------------------*/
int parsing(t_parse *parse, t_vars *v, char *map);
int	read_map(char *argv, t_parse *parse);
int    check_file(char *argv);

/*----------------TEMPORAIRE____________________________________*/
void	parsing_liddle(char *argv, t_vars *v);

#endif
