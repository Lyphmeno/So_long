/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:38:01 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/22 21:34:23 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_longlib.h"

int	copy_map(char *argmap, t_map *map)
{
	char	*tmpline;
	int		i;

	i = 0;
	map->map = (char **)ft_newarray(map->width + 1, map->height, sizeof(char));
	map->fd = open(argmap, O_RDONLY);
	if ((map->fd) == -1)
		return (-1);
	while (i < map->height)
	{
		get_next_line(map->fd, &tmpline);
		ft_memcpy(map->map[i], tmpline, sizeof(char) * map->width);
		free(tmpline);
		i++;
	}
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
		valid_line(tmpline, map);
		if (map->height == 0)
			map->width = ft_strlen(tmpline);
		if (ft_strlen(tmpline) != map->width)
			map->error = 1;
		map->height++;
		printf("tmp[%d] : |%s|\n", map->height, tmpline);
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
	copy_map(argmap, map);
	check_borders(map);
	check_errors(map);
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

int	main(int argc, char **argv)
{
	t_map	*map;

	(void)argc;
	if (argc != 2)
		exit(printf("Too much/Not enough arguments\n"));
	map = (t_map *)ft_calloc(sizeof(t_map), 1);
	ft_memset(map, 0, sizeof(map));
	parsing(argv[1], map);
	free(map->map);
	free(map);
	return (0);
}
