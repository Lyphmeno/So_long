/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_longlib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:21:17 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/23 21:59:59 by lyphmeno         ###   ########.fr       */
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
    int nl;
    char    **map;
} t_map;

typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_data;

void	check_argv(char *s);
void	init_map(t_map **map);
void	init_data(t_data **data);

int	parsing(char *argmap, t_map *map);
int	get_size(char *argmap, t_map *map);
int	copy_map(char *argmap, t_map *map);

void	check_errors(t_map *map);
void	check_entries(t_map *map);
void	check_borders(t_map *map);
void	valid_entries(char c, t_map *map);
void	valid_line(char	*line, t_map *map);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
