/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:12:59 by ecruz-go          #+#    #+#             */
/*   Updated: 2022/02/23 17:32:45 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <unistd.h>

int	close_program(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

/**
 * Manages the imput of the program
 * Its called everytime a key is pressed
 */
int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
        close_program(game);
	return (0);
}
