/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:03:53 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/26 14:45:48 by lyphmeno         ###   ########.fr       */
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
	game->wind->height = game->map->height * 64;
	game->wind->width = game->map->width * 64;
	while (game->wind->height > tmph || game->wind->width > tmpw)
	{
		game->wind->height /= 2;
		game->wind->width /= 2;
	}
}

void	render_player(t_game *game)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	while (i < (double)1 / game->map->height * game->wind->height)
	{
		while (j < (double)1 / game->map->width * game->wind->width)
		{
			put_pixel(game->img, (double)game->player->x / game->map->width
				* game->wind->width + j, (double)game->player->y
				/ game->map->height * game->wind->height + i,
				get_texture(game, game->texture->player, i, j));
			j++;
		}
		j = 0;
		i++;
	}
}
