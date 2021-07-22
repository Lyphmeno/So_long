/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_longlib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:21:17 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/22 21:05:29 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONGLIB_H
# define SO_LONGLIB_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include "minilibx_opengl_20191021/mlx.h"
# define MAPCHAR "10CPE"

typedef struct s_map
{
    int height;
    int width;
    int cltb;
    int exit;
    int ppos;
    int fd;
    int error;
    char    **map;
} t_map;

void	check_errors(t_map *map);
void	check_entries(t_map *map);
void	check_borders(t_map *map);
void	valid_entries(char c, t_map *map);
void	valid_line(char	*line, t_map *map);

#endif
