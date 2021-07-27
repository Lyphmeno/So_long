/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:42:02 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/27 13:07:08 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_longlib.h"

void	player_move_lr(int key, t_game *game)
{
	if (key == RIGHT)
	{
		if (game->map->map[game->player->y][game->player->x + 1] != '1')
		{	
			game->player->x++;
			game->count++;
		}
	}
	if (key == LEFT)
	{
		if (game->map->map[game->player->y][game->player->x - 1] != '1')
		{
			game->player->x--;
			game->count++;
		}
	}
}

void	player_move_ud(int key, t_game *game)
{
	if (key == UP)
	{
		if (game->map->map[game->player->y - 1][game->player->x] != '1')
		{	
			game->player->y--;
			game->count++;
		}
	}
	if (key == DOWN)
	{
		if (game->map->map[game->player->y + 1][game->player->x] != '1')
		{	
			game->player->y++;
			game->count++;
		}
	}
}

int	handle_key(int key, t_game *game)
{
	if (key == 65307)
		exit_game(game);
	player_move_ud(key, game);
	player_move_lr(key, game);
	if (game->map->map[game->player->y][game->player->x] == 'C')
	{
		game->map->map[game->player->y][game->player->x] = '0';
		game->player->cltb++;
	}
	if (game->map->map[game->player->y][game->player->x] == 'E'
		&& game->player->cltb == game->map->cltb)
		free_error(game, "GG\n");
	return (0);
}
