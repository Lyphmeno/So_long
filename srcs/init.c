/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:27:03 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/23 21:43:36 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_longlib.h"

void	init_map(t_map **map)
{
	*map = (t_map *)ft_calloc(sizeof(t_map), 1);
	ft_memset(*map, 0, sizeof(*map));
	if (*map == NULL)
		exit(printf("Error\nInit error\n"));
}

void	init_data(t_data **data)
{
	*data = (t_data *)ft_calloc(sizeof(t_data), 1);
	ft_memset(*data, 0, sizeof(*data));
	if (*data == NULL)
		exit(printf("Error\nInit error\n"));
}