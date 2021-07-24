/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_longlib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:21:17 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/24 22:23:52 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONGLIB_H
# define SO_LONGLIB_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include "minilibx_opengl_20191021/mlx.h"
# define MAPCHAR "10CPE"

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
}				t_mlx;

typedef struct s_map
{
	int			height;
	int			width;
	int			cltb;
	int			exit;
	int			ppos;
	char		**map;
}				t_map;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_texture
{
	t_data		*wall;
	t_data		*exit;
	t_data		*collect;
	t_data		*player;
}				t_texture;

typedef struct s_game
{
	int			error;
	int			nl;
	int			fd;
	t_mlx		*mlx;
	t_map		*map;
	t_player	*player;
	t_texture	*texture;
}				t_game;

void	check_argv(char *s);
void	check_malloc(t_game *game);
void	init_player(char **map, t_player *player);
void	init_game(t_game **game);
void	free_error(t_game *game, char *str);
void	free_game(t_game *game);
void	free_all(t_game *game);
int		copy_map(char *argmap, t_game *game);
int		get_size(char *argmap, t_game *game);
int		parsing(char *argmap, t_game *game);
void	check_errors(t_game *game);
void	check_entries(t_game *game);
void	check_borders(t_game *game);
void	valid_entries(char c, t_game *game);
void	valid_line(char *line, t_game *game);

#endif
