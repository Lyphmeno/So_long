/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:38:01 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/22 16:27:39 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_longlib.h"
void	check_errors(t_map *map)
{
	if (map->error != 0)
	{
		if (map->error == 1)
			printf("Map isn't a rectangle\n");
		exit (EXIT_FAILURE);
	}
}

int	get_size(char *argmap, t_map *map)
{
	char	*tmpline;

	map->fd = open(argmap, O_RDONLY);
	if ((map->fd) == -1)
		return (-1);
	while (get_next_line(map->fd, &tmpline))
	{
		printf("%s\n", tmpline);
		map->height++;
		if (map->height > 1 && ft_strlen(tmpline) != 0) // test de same width pour rectangle
		{
			if (ft_strlen(tmpline) != map->width)
				map->error = 1;
		}
		map->width = ft_strlen(tmpline);
		free(tmpline);
		tmpline = NULL;
	}
	map->height++;
	free(tmpline);
	close(map->fd);
	return (0);
}

int	parsing(char *argmap, t_map *map)
{
	//char	*line;

	get_size(argmap, map);
	check_errors(map);
	printf("H x W = %d x %d\n", map->height, map->width);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	(void)argc;
	map = (t_map *)ft_calloc(sizeof(t_map), 1);
	ft_memset(map, 0, sizeof(map));
	parsing(argv[1], map);
	free(map);
	return (0);
}
