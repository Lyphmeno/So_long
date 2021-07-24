/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 21:28:04 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/24 22:00:59 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_longlib.h"

void	free_error(t_game *game, char *str)
{
	free_game(game);
	exit(printf("%s", str));
}

void	free_game(t_game *game)
{
	free(game->map->map);
	free(game->map);
	free(game->player);
	free(game->mlx);
	free(game->texture->wall);
	free(game->texture->exit);
	free(game->texture->collect);
	free(game->texture->player);
	free(game->texture);
	free(game);
}

void	free_all(t_game *game)
{
	if (game->mlx != NULL)
		free(game->mlx);
	if (game->map != NULL)
		free(game->map);
	if (game->player != NULL)
		free(game->player);
	if (game->texture->wall != NULL)
		free(game->texture->wall);
	if (game->texture->exit != NULL)
		free(game->texture->exit);
	if (game->texture->collect != NULL)
		free(game->texture->collect);
	if (game->texture->player != NULL)
		free(game->texture->player);
	if (game->texture != NULL)
		free(game->texture);
	if (game != NULL)
		free(game);
	exit(printf("Error\nInit error\n"));
}
