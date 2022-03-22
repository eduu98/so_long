/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:36:21 by ecruz-go          #+#    #+#             */
/*   Updated: 2022/03/22 11:14:06 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Allocates memory to save a boxboard with same size as <map> */
t_box	**alloc_boxboard(char **map)
{
	t_box	**boxboard;
	int		i;
	int		lines;

	lines = 0;
	while (map[lines])
		lines++;
	boxboard = malloc(sizeof(t_box *) * lines + 1);
	if (boxboard == NULL)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		boxboard[i] = malloc(sizeof(t_box) * ft_strlen(*map) + 1);
		if (boxboard == NULL)
		{
			while (i > 0)
				free(boxboard[--i]);
			return (NULL);
		}
		i++;
	}
	return (boxboard);
}

/* Returns the boxtype that corresponds to <definer> */
t_boxtype	define_boxtype(char definer)
{
	if (definer == '1')
		return (WALL);
	if (definer == 'C')
		return (COLLECTABLE);
	if (definer == 'P')
		return (PLAYER);
	if (definer == 'E')
		return (EXIT);
	if (definer == 'H' || definer == 'V')
		return (ENEMY);
	else if (definer == 'F')
		return (FOLLOWER);
	return (EMPTY);
}

/* Set the size, original type and contiguous of the <x><y> box of <boxboard> */
void	setup_box(t_box **boxboard, int x, int y)
{
	boxboard[y][x].og_type = boxboard[y][x].type;
	boxboard[y][x].position.x = x * SPITE_SIZE;
	boxboard[y][x].position.y = y * SPITE_SIZE;
	if (y != 0)
		boxboard[y][x].up = &boxboard[y - 1][x];
	if (boxboard[y + 1] != NULL)
		boxboard[y][x].down = &boxboard[y + 1][x];
	if (x != 0)
		boxboard[y][x].left = &boxboard[y][x - 1];
	boxboard[y][x].right = &boxboard[y][x + 1];
}

/* Add info to the game struct if needed */
void	set_gamevars(t_box *box, t_game *game, char c)
{
	if (box->type == PLAYER)
		game->player.box = box;
	else if (box->type == COLLECTABLE)
		game->collects++;
	else if (box->type == ENEMY || box->type == FOLLOWER)
		add_enemy(game, c, box);
}

/* Returns a t_box table filled according to <map>,
each line ends in a box of type 0,
columns ends in a NULL pointer */
t_box	**generate_boxboard(char **map, t_game *game)
{
	t_box		**boxboard;
	int			x;
	int			y;

	boxboard = alloc_boxboard(map);
	if (!boxboard)
		return (null_error("malloc error on alloc_boxboard()"));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			boxboard[y][x].type = define_boxtype(map[y][x]);
			setup_box(boxboard, x, y);
			set_gamevars(&boxboard[y][x], game, map[y][x]);
			x++;
		}
		boxboard[y][x].type = 0;
		y++;
	}
	boxboard[y] = NULL;
	game->win_size.x = x * SPITE_SIZE;
	game->win_size.y = y * SPITE_SIZE;
	return (boxboard);
}