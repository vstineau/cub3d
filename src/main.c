#include "../includes/cub3d.h"
#include <X11/X.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_vars	v;

	v = (t_vars){0};
	v.player = (t_player){0};
	v.player.movespeed = 0.2;
	v.player.rotspeed = 0.09;
	v.player.pos.x = 5;
	v.player.pos.y = 5;
	v.player.dir.x = 0.0;
	v.player.dir.y = -1.0;
	v.player.plane.x = 0.66;
	v.player.plane.y = 0.66;
	parsing_liddle(argv[1], &v);
	for (int j =0; j < 24 ; j++)
	{
		for(int i = 0; i < 24 ; i++)
			printf("%d", v.map[j][i].tile);
		printf("\n");
	}
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	start_image(&v);
	//color_ceiling(&v, P_WHITE);
	//color_floor(&v, P_WHITE);
	raycasting(&v);
	mlx_put_image_to_window(v.mlx, v.win, v.data.img, 0, 0);
	mlx_hook(v.win, DestroyNotify, 0, close_windows, &v);
	mlx_hook(v.win, KeyRelease, KeyRelease, window_action, &v);
	mlx_loop(v.mlx);
	mlx_destroy_image(v.mlx, v.data.img);
	mlx_destroy_window(v.mlx, v.win);
	mlx_destroy_display(v.mlx);
	free(v.mlx);
}
