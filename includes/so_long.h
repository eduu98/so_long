/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:13:13 by ecruz-go          #+#    #+#             */
/*   Updated: 2022/02/23 18:17:14 by ecruz-go         ###   ########.fr       */
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

// Control de las teclas
int	key_press(int keycode, t_game *vars);
int	close_program(t_game *vars);

// Gestion del mapa
t_tile	**map_init(int argc, char **argv);
char	*get_file(int fd, int size, int len)
// MESSAGES
void	print_warning(char *message);
int		print_error(char *message);
#endif
