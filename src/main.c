#include "../includes/cub3d.h"

int	init_mlx(t_vars *v)
{
	v->mlx = mlx_init();
	if (!v->mlx)
		return (1);
	v->win = mlx_new_window(v->mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	if (!v->win)
		return (mlx_destroy_display(v->mlx), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	v;
	t_parse	parse;

	(void)argc;
	if (argc != 2)
		return (ft_err(NULL, "invalid arguments number"), 1);
	if (check_file(argv[1]))
		return (1);
	v = (t_vars){0};
	v.player = (t_player){0};
	parse = (t_parse){0};
	v.text = (t_text){0};
	v.mini = (t_mini){0};
	if (init_mlx(&v))
		return (ft_err(NULL, "mlx loading failed"), 1);
	if (parsing(&parse, &v, argv[1]))
		return (1);
	init_raycasting(&v);
	mlx_hook(v.win, DestroyNotify, 0, close_windows, &v);
	mlx_hook(v.win, KeyPress, KeyPressMask, window_action, &v);
	mlx_loop_hook(v.mlx, cub_loop, &v);
	mlx_loop(v.mlx);
	mlx_destroy_image(v.mlx, v.data.img);
	destroy_mlx(&v);
	return (destroy_map(&v), 0);
}
