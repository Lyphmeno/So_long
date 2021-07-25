/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:27:03 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/25 18:23:39 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_longlib.h"

void	init_player(char **map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player->x = j;
				player->y = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	check_argv(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '.')
		i++;
	if (s[i + 1] != 'b' || s[i + 2] != 'e' || s[i + 3] != 'r')
		exit(printf("Error\nWrong map file\n"));
}

void	check_malloc(t_game *game)
{
	if (game->img == NULL || game->mlx == NULL || game->map == NULL
		|| game->player == NULL || game->texture == NULL
		|| game->wind == NULL || game->texture->wall == NULL
		|| game->texture->exit == NULL || game->texture->floor == NULL
		|| game->texture->cltb == NULL || game->texture->player == NULL)
		free_all(game);
}

void	init_game(t_game **game)
{
	*game = (t_game *)ft_calloc(sizeof(t_game), 1);
	if (*game == NULL)
		exit(printf("Error\nGame init error\n"));
	(*game)->img = (t_data *)ft_calloc(sizeof(t_data), 1);
	(*game)->mlx = (t_mlx *)ft_calloc(sizeof(t_mlx), 1);
	(*game)->wind = (t_wind *)ft_calloc(sizeof(t_wind), 1);
	(*game)->map = (t_map *)ft_calloc(sizeof(t_map), 1);
	(*game)->player = (t_player *)ft_calloc(sizeof(t_player), 1);
	(*game)->texture = (t_texture *)ft_calloc(sizeof(t_texture), 1);
	if ((*game)->texture == NULL)
		free_game(*game);
	(*game)->texture->floor = (t_data *)ft_calloc(sizeof(t_data), 1);
	(*game)->texture->wall = (t_data *)ft_calloc(sizeof(t_data), 1);
	(*game)->texture->exit = (t_data *)ft_calloc(sizeof(t_data), 1);
	(*game)->texture->cltb = (t_data *)ft_calloc(sizeof(t_data), 1);
	(*game)->texture->player = (t_data *)ft_calloc(sizeof(t_data), 1);
	check_malloc(*game);
	ft_memset((*game)->map, 0, sizeof((*game)->map));
}
