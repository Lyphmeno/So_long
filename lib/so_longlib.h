/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_longlib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:21:17 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/26 15:33:36 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONGLIB_H
# define SO_LONGLIB_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include "minilibx-linux/mlx.h"
# define MAPCHAR "10CPE"
//# define UP 119
# define UP 122
# define DOWN 115
//# define LEFT 97
# define LEFT 113
# define RIGHT 100

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
}				t_mlx;

typedef struct s_wind
{
	int			width;
	int			height;
}				t_wind;

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
	int			bpp;
	int			llength;
	int			endian;
	int			width;
	int			height;
}				t_data;

typedef struct s_player
{
	int			x;
	int			y;
	int			cltb;
}				t_player;

typedef struct s_texture
{
	t_data		*floor;
	t_data		*wall;
	t_data		*exit;
	t_data		*cltb;
	t_data		*player;
}				t_texture;

typedef struct s_game
{
	int			count;
	int			error;
	int			nl;
	int			fd;
	t_data		*img;
	t_wind		*wind;
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
void	init_texture_img(t_game *game);
void	init_texture_addr(t_game *game);
void	init_texture(t_game *game);
void	get_real_size(t_game *game);
int		exit_game(t_game *game);
int		handle_key(int key, t_game *game);
void	render(t_game *game);
void	put_pixel(t_data *img, int x, int y, int color);
int		get_texture(t_game *game, t_data *img, int x, int y);
void	render_fw(t_game *game, int x, int y);
void	render_ec(t_game *game, int x, int y);
void	render_player(t_game *game);
void	player_move_ud(int key, t_game *game);
void	player_move_lr(int key, t_game *game);

#endif
