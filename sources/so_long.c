/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:12:51 by ecruz-go          #+#    #+#             */
/*   Updated: 2022/03/01 13:24:24 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int game_init(int argc, char **argv)
{
	map_init(argc, argv);	
	return (0);
}

int main(int argc, char **argv)
{
	t_game	game;

	if (!game_init(argc, argv))
		return (0);
	mlx_hook(game.win, ON_KEYDOWN, 1, key_press, &game);
	// mlx_loop_hook(game.mlx, update, (void *)&game);
	// Cerrar con la X de la ventana
	mlx_hook(game.win, ON_DESTROY, 17, close_program, &game);
	mlx_loop(game.mlx);
	return (0);
}