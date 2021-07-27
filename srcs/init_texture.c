/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:08:10 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/27 13:07:24 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_longlib.h"

void	init_texture_img(t_game *game)
{
	game->texture->floor->img = mlx_xpm_file_to_image(game->mlx->mlx,
			"./texture/dirt.xpm", &game->texture->floor->width,
			&game->texture->floor->height);
	game->texture->wall->img = mlx_xpm_file_to_image(game->mlx->mlx,
			"./texture/wood.xpm", &game->texture->wall->width,
			&game->texture->wall->height);
	game->texture->exit->img = mlx_xpm_file_to_image(game->mlx->mlx,
			"./texture/portal.xpm", &game->texture->exit->width,
			&game->texture->exit->height);
	game->texture->cltb->img = mlx_xpm_file_to_image(game->mlx->mlx,
			"./texture/apple.xpm", &game->texture->cltb->width,
			&game->texture->cltb->height);
	game->texture->player->img = mlx_xpm_file_to_image(game->mlx->mlx,
			"./texture/creeper.xpm", &game->texture->player->width,
			&game->texture->player->height);
	if (!(game->texture->wall->img || game->texture->exit->img
			|| game->texture->cltb->img || game->texture->player->img
			|| game->texture->floor->img))
		free_error(game, "Error\nTexture problem\n");
}

void	init_texture_addr(t_game *game)
{
	game->texture->floor->addr = mlx_get_data_addr(game->texture->floor->img,
			&game->texture->floor->bpp, &game->texture->floor->llength,
			&game->texture->floor->endian);
	game->texture->wall->addr = mlx_get_data_addr(game->texture->wall->img,
			&game->texture->wall->bpp, &game->texture->wall->llength,
			&game->texture->wall->endian);
	game->texture->exit->addr = mlx_get_data_addr(game->texture->exit->img,
			&game->texture->exit->bpp, &game->texture->exit->llength,
			&game->texture->exit->endian);
	game->texture->cltb->addr = mlx_get_data_addr(game->texture->cltb->img,
			&game->texture->cltb->bpp, &game->texture->cltb->llength,
			&game->texture->cltb->endian);
	game->texture->player->addr = mlx_get_data_addr(game->texture->player->img,
			&game->texture->player->bpp, &game->texture->player->llength,
			&game->texture->player->endian);
}

void	init_texture(t_game *game)
{
	init_texture_img(game);
	init_texture_addr(game);
}
