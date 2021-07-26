/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:15:38 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/26 13:37:03 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_longlib.h"

void	put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->llength + x * (img->bpp / 8));
	if (color != 0x80FFFF)
		*(int *)dst = color;
}

int	get_texture(t_game *game, t_data *img, int x, int y)
{
	double	i;
	double	j;
	int		color;

	i = y / ((double)1 / game->map->width * game->wind->width) * img->width;
	j = x / ((double)1 / game->map->height * game->wind->height) * img->height;
	color = *(int *)(img->addr + ((int)j * img->llength + (int)i
				* (img->bpp / 8)));
	return (color);
}

void	render_fw(t_game *game, int x, int y)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	while (i < (double)1 / game->map->height * game->wind->height)
	{
		while (j < (double)1 / game->map->width * game->wind->width)
		{
			if (game->map->map[x][y] == '1')
				put_pixel(game->img, (double)y / game->map->width
					* game->wind->width + j, (double)x / game->map->height
					* game->wind->height + i,
					get_texture(game, game->texture->wall, i, j));
			if (game->map->map[x][y] == 'C' || game->map->map[x][y] == '0'
				|| game->map->map[x][y] == 'E')
				put_pixel(game->img, (double)y / game->map->width
					* game->wind->width + j, (double)x / game->map->height
					* game->wind->height + i,
					get_texture(game, game->texture->floor, i, j));
			j++;
		}
		j = 0;
		i++;
	}
}

void	render_ec(t_game *game, int x, int y)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	while (i < (double)1 / game->map->height * game->wind->height)
	{
		while (j < (double)1 / game->map->width * game->wind->width)
		{
			if (game->map->map[x][y] == 'C')
				put_pixel(game->img, (double)y / game->map->width
					* game->wind->width + j, (double)x / game->map->height
					* game->wind->height + i,
					get_texture(game, game->texture->cltb, i, j));
			if (game->map->map[x][y] == 'E')
				put_pixel(game->img, (double)y / game->map->width
					* game->wind->width + j, (double)x / game->map->height
					* game->wind->height + i,
					get_texture(game, game->texture->exit, i, j));
			j++;
		}
		j = 0;
		i++;
	}
}

void	render(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map->map[x] != NULL)
	{
		while (game->map->map[x][y] != '\0')
		{
			render_fw(game, x, y);
			render_ec(game, x, y);
			render_player(game);
			y++;
		}
		y = 0;
		x++;
	}
}
