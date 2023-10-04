/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 05:28:40 by mel-meka          #+#    #+#             */
/*   Updated: 2023/10/04 11:16:08 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

#include"map.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	val_to_char(t_map *map, int v)
{
	if (v == 0)
		return (map->obstacle);
	return (map->empty);
}

int	is_in_square(t_map *map, int i, int j)
{
	int	r;
	int x;
	int y;
	int size;

	x = map->biggest_square.x;
	y = map->biggest_square.y;
	size = map->biggest_square.size;

	r = (i >= x && i < x + size);
	r = r && (j >= y && j < y + size);
	return (r);
}

void	map_print(t_map *map)
{
	int i;
	int j;
	int **lines;
	lines = map->lines;
	j = 0;
	while (j < map->lines_len)
	{
		i = 0;
		while (i < map->line_len)
		{
			if (is_in_square(map, i, j))
				ft_putchar(map->full);
			else
				ft_putchar(val_to_char(map, lines[j][i]));
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
