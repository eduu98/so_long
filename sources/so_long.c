/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:12:51 by ecruz-go          #+#    #+#             */
/*   Updated: 2022/03/22 11:55:00 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

/* Starts the mlx, opens a window, and open images */
void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x + IMG_SIZE / 2,
			game->wndw_size.y,
			"so_long");
	mlx_hook(game->window, 17, 0, end_program, game);
	open_images(game);
	game->white_panel = new_panel(game, new_color(254, 254, 254, 0));
	game->red_panel = new_panel(game, new_color(197, 4, 4, 0));
}

/* Sets the frames of all animatios */
static void	anim_setup(t_game *game)
{
	game->player.idle_frames = 17;
	game->player.action_frames = 10;
	game->collects_imgs.anim_frames = 25;
	game->effect.frames = 7;
	game->enemy_imgs.basic_anim = 16;
	game->enemy_imgs.follow_anim = 6;
}
int	game_init(int argc, char **argv, t_game *game)
{
	game->collects = 0;
	game->moves = 0;
	game->boxmap = map_init(argc, argv, game);
	if (game->boxmap == NULL)
		return (0);
	game->og_collects = game->collects;
	anim_setup(game);
	start_game(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!game_init(argc, argv, &game))
		return (0);

	/*
	mlx_hook(game.window, 2, 0, input, (void *)&game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_loop(game.mlx);
	*/

	mlx_hook(game.win, ON_KEYDOWN, 1, key_press, &game);
	// mlx_loop_hook(game.mlx, update, (void *)&game);
	// Cerrar con la X de la ventana
	mlx_hook(game.win, ON_DESTROY, 17, close_program, &game);
	mlx_loop(game.mlx);
	return (0);
}
