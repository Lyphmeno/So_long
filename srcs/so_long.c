/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:38:01 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/25 18:22:50 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_longlib.h"

int	image_loop(t_game *game)
{
	game->img->img = mlx_new_image(game->mlx->mlx,
			game->wind->width, game->wind->height);
	game->img->addr = mlx_get_data_addr(game->img->img,
			&game->img->bpp, &game->img->llength, &game->img->endian);
	//render(game);
	mlx_put_image_to_window(game->mlx->mlx,
		game->mlx->window, game->img->img, 0, 0);
	mlx_destroy_image(game->mlx->mlx, game->img->img);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 2)
		exit(printf("Too much/Not enough arguments\n"));
	check_argv(argv[1]);
	init_game(&game);
	parsing(argv[1], game);
	init_player(game->map->map, game->player);
	printf("P = [%d,%d]\n", game->player->x, game->player->y);
	game->mlx->mlx = mlx_init();
	init_texture(game);
	mlx_do_key_autorepeatoff(game->mlx->mlx);
	get_real_size(game);
	printf("map screen size = [%d,%d]\n", game->wind->height, game->wind->width);
	game->mlx->window = mlx_new_window(game->mlx->mlx, game->wind->width,
			game->wind->height, "so_long");
	mlx_hook(game->mlx->window, 2, 1L << 0, handle_key, game);
	mlx_hook(game->mlx->window, 33, 1L << 17, exit_game, game);
	mlx_loop_hook(game->mlx->mlx, image_loop, game);
	mlx_loop(game->mlx->mlx);
	free_game(game);
	return (0);
}
