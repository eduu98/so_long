/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:53:59 by ecruz-go          #+#    #+#             */
/*   Updated: 2022/02/23 18:16:57 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * Checks if the file is readeable
 * and has the correct extension
 */
int	check_file(int nargs, char *path)
{
	char	*ext;
	int		fd;

	if (nargs == 1)
		return (print_error("No arguments"));
	if (nargs > 2)
		print_warning("only the first file would be used");
	ext = ft_strrchr(path, '.');
	if (ext == NULL || ft_strncmp(".ber", ext, 4) != 0)
		return (print_error("Map should be a .ber file"));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	return (1);
}

/**
 * Creates -with malloc- a 2D char map as found in file
 */
char	**read_map(char *file)
{
	char	**map;
	int		fd;
	int		i;

	map = alloc_columns(file);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_file(fd, &map[i++]))
		;
	map[i] = NULL;
	close(fd);
	return (map);
}

/* Creates -with malloc- a tilemap acording to the
first file of argv. Returns NULL if an error occurs. */
t_tile	**map_init(int argc, char **argv)
{
	// char	**map;  , t_game *game
	t_tile	**tilemap;

	tilemap = NULL;

	if (!check_file(argc, argv[1]))
		return (NULL);
	/*
	map = read_map (argv[1]);
	if (!map)
		return (NULL);
	if (valid_map(map) == 0)
	{
		ft_free_chartable(map);
		return (NULL);
	}
	tilemap = generate_tilemap(map, game);
	ft_free_chartable(map);
	if (!tilemap)
		return (NULL);
	*/
	return (tilemap);
}