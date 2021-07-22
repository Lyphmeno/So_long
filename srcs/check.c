/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:48:57 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/22 21:31:11 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_longlib.h"

void	check_errors(t_map *map)
{
	if (map->error != 0)
	{
		if (map->error == 1)
			printf("Map isn't a rectangle\n");
		if (map->error == 2)
			printf("Map contains a character that isn't supposed to be\n");
		if (map->error == 3)
			printf("Wrong map entries\n");
		if (map->error == 4)
			printf("Map not surrounded by walls\n");
		free (map->map);
		free (map);
		exit (0);
	}
}

void	check_borders(t_map *map)
{
	int	i;

	i = 0;
	if (is_not_char(map->map[0], '1') == -1)
		map->error = 4;
	if (is_not_char(map->map[map->height - 1], '1') == -1)
		map->error = 4;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			map->error = 4;
		i++;
	}
}

void	check_entries(t_map *map)
{
	if (map->cltb < 1)
		map->error = 3;
	if (map->exit < 1)
		map->error = 3;
	if (map->ppos != 1)
		map->error = 3;
}

void	valid_entries(char c, t_map *map)
{
	if (c == 'C')
		map->cltb++;
	if (c == 'P')
		map->ppos++;
	if (c == 'E')
		map->exit++;
}

void	valid_line(char	*line, t_map *map)
{
	int	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (is_charset(line[i], MAPCHAR) == 0)
			map->error = 2;
		else
			valid_entries(line[i], map);
		i++;
	}
}
