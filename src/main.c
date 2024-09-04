#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_vars	v;

	v = (t_vars){0};
	v.player = (t_player){0};
	v.text = (t_text){0};
	init_raycasting(&v);
	parsing_liddle(argv[1], &v);
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	load_textures(&v);
	start_image(&v);
	mlx_hook(v.win, DestroyNotify, 0, close_windows, &v);
	mlx_hook(v.win, KeyPress, KeyPressMask, window_action, &v);
	mlx_loop_hook(v.mlx, cub_loop, &v);
	mlx_loop(v.mlx);
	mlx_destroy_image(v.mlx, v.data.img);
	mlx_destroy_window(v.mlx, v.win);
	mlx_destroy_display(v.mlx);
	free(v.mlx);
}
