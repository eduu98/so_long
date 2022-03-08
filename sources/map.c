/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:53:59 by ecruz-go          #+#    #+#             */
/*   Updated: 2022/03/08 12:43:34 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include <stdio.h>
#include <unistd.h>

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
 * Function that creates first and array to allocate thte columns
 * and then reads the map and create a 2 dimension matrix to save it
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
	while (get_next_line(fd, &map[i++]))
		;
	map[i] = NULL;
	close(fd);
	return (map);
}

/* Returns TRUE if the map is valid.
* Printing an error message and returning FALSE if not */
int	valid_map(char **map)
{
	t_mapcheck	mapdata;
	int			valid;

	mapdata = mapcheck(map);
	valid = 1;
	while (map[mapdata.point.y])
	{
		if (ft_strlen(map[mapdata.point.y]) != mapdata.size.x)
			valid = print_error("Map must be rectangular");
		mapdata.point.x = 0;
		while (map[mapdata.point.y][mapdata.point.x])
		{
			if (checks(map, &mapdata) == 0)
				valid = 0;
			mapdata.point.x++;
		}
		mapdata.point.y++;
	}
	if (!mapdata.player || !mapdata.exit || !mapdata.collectable)
		valid = print_error("There must be one 'P' and 'E', and at least one 'C'");
	return (valid);
}

/* Creates -with malloc- a tilemap acording to the
first file of argv. Returns NULL if an error occurs. */
t_tile	**map_init(int argc, char **argv)
{
	char	**map;
	t_tile	**tilemap;

	tilemap = NULL;
	if (!check_file(argc, argv[1]))
		return (NULL);
	map = read_map (argv[1]);
	if (!map)
		return (NULL);
	if (valid_map(map) == 0)
	{
		free_map(map);
		return (NULL);
	}
	/*
	tilemap = generate_tilemap(map, game);
	free_map(map);
	if (!tilemap)
		return (NULL);
	*/
	return (tilemap);
}
