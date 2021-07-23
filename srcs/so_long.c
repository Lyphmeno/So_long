/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:38:01 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/23 22:15:29 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_longlib.h"

int	print_key(int key, int *test)
{
	printf("%d\n", key);
	if (key == 65307)
		exit(0);
	*test = 1;
	return (0);
}

int	render_img(t_data *img, void *mlx)
{
	int		img_width;
	int		img_height;
	
	img->img = mlx_xpm_file_to_image(mlx, "/home/lyphmeno/42/So_long/zemour.xpm", &img_width, &img_height);
	if (img->img == NULL)
		return (-1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_data	*img;
	void	*mlx;
	void	*mlx_win;

	(void)argc;
	if (argc != 2)
		exit(printf("Too much/Not enough arguments\n"));
	printf("argv = %s\n", argv[1]);
	check_argv(argv[1]);
	init_map(&map);
	init_data(&img);
	parsing(argv[1], map);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 500, "So_long");
	render_img(img, mlx);
	//mlx_key_hook(mlx_win, print_key, &test);
	mlx_hook(mlx_win, 33, 1L << 17, 0, mlx);
	mlx_loop(mlx);
	(void)mlx_win;
	free(map->map);
	free(map);
	return (0);
}
