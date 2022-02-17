/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:12:51 by ecruz-go          #+#    #+#             */
/*   Updated: 2022/02/16 21:12:53 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_square(t_data *data, int color)
{
	int i;
	int j;

	i = 5;
	j = 5;


	while (i < 200)
	{
		j = 5;
		color+= 255;
		while (j < 200)
		{
			my_mlx_pixel_put(data, i, j, color);
			j++;
		}		
		i++;
	}
	
}

void	print_piramid (t_data *data)
{
	int x;
	int y;
	int color;

	x = 5;
	y = 304;
	color = 0x00FF0000;


	while (x < 305)
	{
		// color+= 255;
		while (y < 305)
		{
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}		
		x++;
		y-= x;
	}
}

int main(void)
{
	// int argc, char *argv[]
	t_vars	vars;
	t_data	img;
	int color;
	int		img_width;
	int		img_height;

	color = 000000;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "SO_LONG");

	img.img = mlx_xpm_file_to_image(vars.mlx, "./img/Tileset.png", &img_width, &img_height);
	// img.img = mlx_new_image(vars.mlx, 500, 500);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,	&img.endian);
	// print_square(&img, 000);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	// Cerrar con la X de la ventana
	mlx_hook(vars.win, ON_DESTROY, 17, close_window, &vars);
	// Eventos teclas
	mlx_hook(vars.win, ON_KEYDOWN, 1, key_event, &vars);
	// mlx_loop_hook(vars.mlx, render_next_frame, &img);
	mlx_loop(vars.mlx);
}