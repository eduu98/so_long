/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:19:02 by ecruz-go          #+#    #+#             */
/*   Updated: 2022/03/16 13:23:42 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <unistd.h>

/**
 * First, checks the lines of the file,
 * then creates an array with the length enouugth
 * to save all the columns from the maps
 */
char	**alloc_columns(char *file)
{
	char	**map;
	int		lines;
	int		fd;
	int		readed;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (null_error("Open error, the file may not exist"));
	lines = 1;
	readed = read(fd, &c, 1);
	while (readed != 0)
	{
		if (readed < 0)
			return (null_error("Reading error, the file may not exist"));
		if (c == '\n')
			lines++;
		readed = read(fd, &c, 1);
	}
	close(fd);
	map = malloc(sizeof(char *) * lines + 1);
	if (map == NULL)
		return (null_error("Malloc error on alloc_map()"));
	return (map);
}

/* Initialize the data needed to check if the map is valid */
t_mapcheck	mapcheck(char **map)
{
	t_mapcheck	data;

	while (map[data.size.y])
		data.size.y++;
	data.size.x = ft_strlen(map[0]);
	data.player = 0;
	data.exit = 0;
	data.collectable = 0;
	data.point.y = 0;
	data.point.x = 0;
	return (data);
}

/* Checks to do to each indivial box of the map.
* When it founds one, pritns an error and returns FALSE. */
int	checks(char **map, t_mapcheck *data)
{
	int	x;
	int	y;

	x = data->point.x;
	y = data->point.y;
	if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C' && map[y][x] != 'E'
		&& map[y][x] != 'P' && map[y][x] != 'H' && map[y][x] != 'V' && map[y][x] != 'F')
		return (print_error("invalid map character"));
	if (map[y][x] == 'P' && data->player == 0)
		data->player = 1;
	else if (map[y][x] == 'P' && data->player == 1)
		return (print_error("must be only one player 'P'"));
	if (map[y][x] == 'E')
		data->exit = 1;
	if (data->point.y == 0 || data->point.x == 0
		|| data->point.y == data->size.y - 1 || data->point.x == data->size.x - 1)
		if (map[y][x] != '1')
			return (print_error("map must be surrounded by walls '1'"));
	if (map[y][x] == 'C')
		data->collectable = 1;
	return (1);
}

/* Free the matrix map */
void	free_map(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
