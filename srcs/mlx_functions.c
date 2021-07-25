/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:03:53 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/25 18:27:00 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_longlib.h"

int	exit_game(t_game *game)
{
	free_error(game, "You left the game\n");
	return (0);
}

void	get_real_size(t_game *game)
{
	int	tmph;
	int	tmpw;

	tmph = 0;
	tmpw = 0;
	mlx_get_screen_size(game->mlx->mlx, &tmpw, &tmph);
	printf("screen size = [%d,%d]\n", tmph, tmpw);
	game->wind->height = game->map->height * 64;
	game->wind->width = game->map->width * 64;
	while (game->wind->height > tmph || game->wind->width > tmpw)
	{
		game->wind->height /= 2;
		game->wind->width /= 2;
	}
}

int	handle_key(int key, t_game *game)
{
	printf("%d\n", key);
	if (key == 65307)
		exit_game(game);
	return (0);
}
