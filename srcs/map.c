/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:23:34 by mel-meka          #+#    #+#             */
/*   Updated: 2023/10/04 14:36:24 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "utils.h"

#include<unistd.h>
#include<stdlib.h>
#include <fcntl.h>

int	load_line(char *buffer, t_map *map, int j)
{
	int i;
	int r;
	int	*cur_line;

	map->lines[j] = malloc(sizeof(int) * map->line_len);
	cur_line = map->lines[j];
	i = 0;
	while (i < map->line_len)
	{
		r = char_to_val(map, buffer[i]);
		if (r == -1)
			return (0);
		if (i == 0 || j == 0 || r == 0)
		{
			cur_line[i] = r;
			set_biggest_square(map, i, j);
		}
		else
		{
			cur_line[i] = min3(cur_line[i-1], map->lines[j-1][i], map->lines[j-1][i-1]) + 1;
			set_biggest_square(map, i, j);
		}
		i++;
	}
	if (buffer[i] != '\n')
		return (0);
	return (1);
}

int	read_first_line(int fd, char **buffer)
{
	char b;
	int b_read;
	int i;
	int buf_len;

	i = 0;
	buf_len = 128;
	*buffer = malloc(sizeof(char) * (buf_len));
	b_read = read(fd, &b, 1);
	while (b_read)
	{
		if (buf_len == i)
		{
			buf_len *= 2;
			*buffer = double_size(*buffer, i);
		}
		(*buffer)[i] = b;
		if (b == '\n')
			break ;
		b_read = read(fd, &b, 1);
		i++;
	}
	if (b_read == 0) // didnt break because of \n
		return (0);
	return (i);
}

int	load_lines(int fd, t_map *map)
{
	int		len;
	int		i;
	char	*buffer;
	int		b_read;

	map->line_len = read_first_line(fd, &buffer);
	len = map->line_len;
	if (len == 0)
		return (0);
	i = 0;
	while (i < map->lines_len)
	{
		if (!load_line(buffer, map, i))
			return (0);
		b_read = read(fd, buffer, (len + 1));
		i++;
	}
	if (b_read != 0)
		return (0);
	return (1);
}

int	load_map(char *path, t_map *map)
{
	char	b;
	int		b_read;
	int		fd;
	
	if (path == 0)
		fd = 0;
	else
		fd = open(path, O_RDWR);
	if (fd == -1)
		return (0);
	b_read = read(fd, &b, 1);
	if (b_read <= 0)
		return (0);
	while (b_read && is_numeric(b))
	{
		map->lines_len = map->lines_len * 10 + (b - '0');
		b_read = read(fd, &b, 1);
	}
	map->empty = b;
	b_read = read(fd, &b, 1);
	map->obstacle = b;
	b_read = read(fd, &b, 1);
	map->full = b;
	b_read = read(fd, &b, 1);
	if (b != '\n' || !is_valid(map))
		return (0);
	map->lines = malloc(sizeof(int *) * map->lines_len);
	if (load_lines(fd, map))
	{
		close(fd);
		return (1);
	}
	return (0);
}
