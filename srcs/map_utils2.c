/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:27:37 by mel-meka          #+#    #+#             */
/*   Updated: 2023/10/04 17:58:12 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"map.h"
#include<stdlib.h>
#include<unistd.h>

void	set_map(t_map *map)
{
	map->biggest_square.size = 0;
	map->lines = NULL;
	map->lines_len = 0;
	map->line_len = 0;
}

void	reset_map(t_map *map)
{
	int	j;

	j = 0;
	if (map->lines)
	{	
		while (j < map->lines_len)
		{
			if (map->lines[j])
				free(map->lines[j]);
			j++;
		}
		free(map->lines);
	}
	map->lines = NULL;
	map->lines_len = 0;
	map->line_len = 0;
	map->biggest_square.size = 0;
	map->biggest_square.x = -1;
	map->biggest_square.y = -1;
}

void	map_load_charset(int fd, t_map *map, char *b)
{
	map->empty = *b;
	read(fd, b, 1);
	map->obstacle = *b;
	read(fd, b, 1);
	map->full = *b;
	read(fd, b, 1);
}

int	load_file_header(int fd, t_map *map)
{
	char	b;
	int		b_read;
	int		i;

	b_read = read(fd, &b, 1);
	if (b_read <= 0)
		return (0);
	while (b_read && is_numeric(b))
	{
		map->lines_len = map->lines_len * 10 + (b - '0');
		b_read = read(fd, &b, 1);
	}
	map_load_charset(fd, map, &b);
	if (b != '\n' || !is_valid(map))
		return (0);
	map->lines = malloc(sizeof(int *) * map->lines_len);
	i = 0;
	while (i < map->lines_len)
	{
		map->lines[i] = NULL;
		i++;
	}
	return (1);
}
