/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_longlib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:21:17 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/22 14:36:56 by lyphmeno         ###   ########.fr       */
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

typedef struct s_map
{
    int height;
    int width;
    int col;
    int ex;
    int fd;
    int error;
    char    **map;
} t_map;

#endif
