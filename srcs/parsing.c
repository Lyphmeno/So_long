/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:01:33 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/27 13:07:33 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_longlib.h"

int	copy_map(char *argmap, t_game *game)
{
	char	*tmpline;
	int		gnlvalue;
	int		i;

	i = 0;
	gnlvalue = 0;
	game->map->height += game->nl;
	game->map->map = (char **)ft_newarray(game->map->width + 1,
			game->map->height + 1, sizeof(char));
	game->fd = open(argmap, O_RDONLY);
	if ((game->fd) == -1)
		return (-1);
	while (i < game->map->height)
	{
		gnlvalue = get_next_line(game->fd, &tmpline);
		if (!(gnlvalue == 0 && ft_strlen(tmpline) == 0))
			ft_memcpy(game->map->map[i], tmpline,
				sizeof(char) * game->map->width);
		free(tmpline);
		i++;
	}
	game->map->map[i] = NULL;
	i = 0;
	close(game->fd);
	return (0);
}

int	get_size(char *argmap, t_game *game)
{
	char	*tmpline;
	int		gnlvalue;

	game->fd = open(argmap, O_RDONLY);
	if ((game->fd) == -1)
		free_error(game, "Error\nCan't open map\n");
	gnlvalue = 1;
	while (gnlvalue > 0)
	{
		gnlvalue = get_next_line(game->fd, &tmpline);
		if (gnlvalue == 0 && ft_strlen(tmpline) == 0)
			game->nl = -1;
		valid_line(tmpline, game);
		if (game->map->height == 0)
			game->map->width = ft_strlen(tmpline);
		if (gnlvalue == 1 && ft_strlen(tmpline) == 0)
			game->error = 1;
		if (!(gnlvalue == 0 && ft_strlen(tmpline) == 0))
			if (ft_strlen(tmpline) != game->map->width)
				game->error = 1;
		game->map->height++;
		free(tmpline);
	}
	close(game->fd);
	return (0);
}

int	parsing(char *argmap, t_game *game)
{
	get_size(argmap, game);
	check_entries(game);
	check_errors(game);
	copy_map(argmap, game);
	check_borders(game);
	return (0);
}
