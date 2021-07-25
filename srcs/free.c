/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 21:28:04 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/25 18:26:07 by lyphmeno         ###   ########.fr       */
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
	mlx_destroy_image(game->mlx->mlx, game->texture->floor->img);
	mlx_destroy_image(game->mlx->mlx, game->texture->wall->img);
	mlx_destroy_image(game->mlx->mlx, game->texture->exit->img);
	mlx_destroy_image(game->mlx->mlx, game->texture->cltb->img);
	mlx_destroy_image(game->mlx->mlx, game->texture->player->img);
	mlx_destroy_window(game->mlx->mlx, game->mlx->window);
	mlx_do_key_autorepeaton(game->mlx->mlx);
	mlx_destroy_display(game->mlx->mlx);
	free(game->mlx->mlx);
	free(game->mlx);
	free(game->img);
	free(game->wind);
	free(game->texture->floor);
	free(game->texture->wall);
	free(game->texture->exit);
	free(game->texture->cltb);
	free(game->texture->player);
	free(game->texture);
	free(game);
}

void	free_all(t_game *game)
{
	if (game->mlx != NULL)
		free(game->mlx);
	if (game->img != NULL)
		free(game->img);
	if (game->map != NULL)
		free(game->map);
	if (game->player != NULL)
		free(game->player);
	if (game->wind != NULL)
		free(game->wind);
	if (game->texture->floor != NULL)
		free(game->texture->floor);
	if (game->texture->wall != NULL)
		free(game->texture->wall);
	if (game->texture->exit != NULL)
		free(game->texture->exit);
	if (game->texture->cltb != NULL)
		free(game->texture->cltb);
	if (game->texture->player != NULL)
		free(game->texture->player);
	if (game->texture != NULL)
		free(game->texture);
	if (game != NULL)
		free(game);
	exit(printf("Error\nInit error\n"));
}
