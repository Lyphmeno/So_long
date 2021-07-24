/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:48:57 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/24 22:02:59 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_longlib.h"

void	check_errors(t_game *game)
{
	if (game->error != 0)
	{
		printf("Error\n");
		if (game->error == 1)
			printf("Map isn't a rectangle\n");
		if (game->error == 2)
			printf("Map contains a character that isn't supposed to be\n");
		if (game->error == 3)
			printf("Wrong map entries\n");
		free_game(game);
		exit (0);
	}
}

void	check_borders(t_game *game)
{
	int	i;

	i = 0;
	if (is_not_char(game->map->map[0], '1') == -1)
		game->error = 4;
	if (!(ft_strlen(game->map->map[game->map->height - 1])))
	{
		if (is_not_char(game->map->map[game->map->height - 2], '1') == -1)
			game->error = 4;
	}
	else
		if (is_not_char(game->map->map[game->map->height - 1], '1') == -1)
			game->error = 4;
	while (i < game->map->height)
	{
		if (game->map->map[i][0] != '1' ||
			game->map->map[i][game->map->width - 1] != '1')
			game->error = 4;
		i++;
	}
	if (game->error == 4)
	{
		free_error(game, "Error\nMap not surrounded by walls\n");
	}
}

void	check_entries(t_game *game)
{
	if (game->map->cltb < 1)
		game->error = 3;
	if (game->map->exit < 1)
		game->error = 3;
	if (game->map->ppos != 1)
		game->error = 3;
}

void	valid_entries(char c, t_game *game)
{
	if (c == 'C')
		game->map->cltb++;
	if (c == 'P')
		game->map->ppos++;
	if (c == 'E')
		game->map->exit++;
}

void	valid_line(char	*line, t_game *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (is_charset(line[i], MAPCHAR) == 0)
			game->error = 2;
		else
			valid_entries(line[i], game);
		i++;
	}
}
