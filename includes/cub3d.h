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
	FLOOR,
	WALL,
	DOOR,
	VOID
}				t_tile;

//enum to define orientation
typedef enum s_dir
{
    NORTH,
    SOUTH,
    EAST,
    WEST
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
	double	wallx;
	double	step;
	double	pos;
	t_img		*win;
	t_img		*east;
	t_img		*west;
	t_img		*south;
	t_img		*north;
	t_img		*canva;

}				t_text;

// y and x is the player position
// dir_x and dir_y is the direction of the player
// plane_x and plane_y is the camera plane of the player
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
}			t_player;

typedef struct s_point
{
	t_tile		tile;
	int				x;
	int				y;
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
	float			err;
	t_player	player;
	t_text		text;
	t_point		**map;
	t_data		data;
	t_fn			f[0xFFFF];
}				t_vars;

/*---------------PLAYER MOTIONS------------------------------*/

void	move_forward(t_vars *v);
void	move_backward(t_vars *v);
void	rotate_left(t_vars *v);
void	rotate_right(t_vars *v);
void	move_left(t_vars *v);
void	move_right(t_vars *v);

/*---------------WINDOW ACTIONS------------------------------*/

int	window_action(int keycode, t_vars *vars);
int	close_windows(t_vars *vars);

/*----------------IMAGE MANAGEMENT-----------------------------*/

void	start_image(t_vars *v);
void	color_ceiling(t_vars *v, int color);
void	color_floor(t_vars *v, int color);
void	clear_image(t_vars *v, int color);

/*----------------RAYCASTING-----------------------------------*/

void	raycasting(t_vars *v);

/*----------------RAYCASTING-----------------------------------*/

int    load_sprites(t_vars *v);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	parsing_liddle(char *argv, t_vars *v);
char    *read_map(char *argv);

#endif
