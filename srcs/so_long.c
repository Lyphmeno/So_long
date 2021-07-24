/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:38:01 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/24 22:41:08 by lyphmeno         ###   ########.fr       */
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
	free_game(game);
	return (0);
}
