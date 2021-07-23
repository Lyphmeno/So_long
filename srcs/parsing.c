/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:01:33 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/23 22:14:39 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_longlib.h"

void	check_argv(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '.')
		i++;
	if (s[i + 1] != 'b' || s[i + 2] != 'e' || s[i + 3] != 'r')
		exit(printf("Error\nWrong map file\n"));
}

int	copy_map(char *argmap, t_map *map)
{
	char	*tmpline;
	int		gnlvalue;
	int		i;

	i = 0;
	gnlvalue = 0;
	map->height += map->nl;
	map->map = (char **)ft_newarray(map->width + 1, map->height, sizeof(char));
	map->fd = open(argmap, O_RDONLY);
	if ((map->fd) == -1)
		return (-1);
	while (i < map->height)
	{
		gnlvalue = get_next_line(map->fd, &tmpline);
		if (!(gnlvalue == 0 && ft_strlen(tmpline) == 0))
			ft_memcpy(map->map[i], tmpline, sizeof(char) * map->width);
		free(tmpline);
		i++;
	}
	i = 0;
	close(map->fd);
	return (0);
}

int	get_size(char *argmap, t_map *map)
{
	char	*tmpline;
	int		gnlvalue;

	map->fd = open(argmap, O_RDONLY);
	if ((map->fd) == -1)
		return (-1);
	gnlvalue = 1;
	while (gnlvalue > 0)
	{
		gnlvalue = get_next_line(map->fd, &tmpline);
		if (gnlvalue == 0 && ft_strlen(tmpline) == 0)
			map->nl = -1;
		valid_line(tmpline, map);
		if (map->height == 0)
			map->width = ft_strlen(tmpline);
		if (gnlvalue == 1 && ft_strlen(tmpline) == 0)
			map->error = 1;
		if (!(gnlvalue == 0 && ft_strlen(tmpline) == 0))
			if (ft_strlen(tmpline) != map->width)
				map->error = 1;
		map->height++;
		free(tmpline);
	}
	close(map->fd);
	return (0);
}

int	parsing(char *argmap, t_map *map)
{
	int	i;

	i = 0;
	get_size(argmap, map);
	check_entries(map);
	check_errors(map);
	copy_map(argmap, map);
	check_borders(map);
	printf("Height x Width = %d x %d\n", map->height, map->width);
	printf("Exit = %d\n", map->exit);
	printf("Collectibles = %d\n", map->cltb);
	printf("Ppos = %d\n", map->ppos);
	while (i < map->height)
	{
		printf("map[%d] : |%s|\n", i, map->map[i]);
		i++;
	}
	return (0);
}