/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:13:13 by ecruz-go          #+#    #+#             */
/*   Updated: 2022/03/04 14:19:06 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>

/* All valid input keys */
enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};
/* All valid hook events */
enum e_hookevent{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
/* All posibilities for a tile */
typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
	FOLLOWER = 'F'
}	t_tiletype;
/* Basic struct to store coordinates */
typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;
/* Struct for each tile */
typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		og_type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;
/* Principal struct with the main content of the game*/
typedef struct	s_game {
	void		*mlx;
	void		*win;
	t_vector	win_size;
}	t_game;
/* Struct for checking the map */
typedef struct s_mapcheck
{
	t_vector	size;
	t_vector	point;
	int			player;
	int			exit;
	int			collectable;
}				t_mapcheck;

// Control de las teclas
int	key_press(int keycode, t_game *vars);
int	close_program(t_game *vars);

// Map Management
t_tile	**map_init(int argc, char **argv);
static char	**alloc_columns(char *file);
static t_mapcheck	mapcheck(char **map);
static int	checks(char **map, t_mapcheck *data);
// MESSAGES
void	print_warning(char *message);
int		print_error(char *message);
void	*null_error(char *message);
#endif
