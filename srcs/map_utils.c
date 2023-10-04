/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 08:45:56 by mel-meka          #+#    #+#             */
/*   Updated: 2023/10/04 17:30:00 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"map.h"

#include<stdlib.h>

int	is_valid(t_map *map)
{
	if (map->empty == map->obstacle || map->empty == map->full)
		return (0);
	if (map->obstacle == map->full)
		return (0);
	return (1);
}

int	char_to_val(t_map *map, char c)
{
	if (c == map->obstacle)
		return (0);
	if (c == map->empty)
		return (1);
	return (-1);
}

void	set_biggest_square(t_map *map, int i, int j)
{
	int	cur_size;

	cur_size = map->lines[j][i];
	if (map->biggest_square.size < cur_size)
	{
		map->biggest_square.x = i - (cur_size - 1);
		map->biggest_square.y = j - (cur_size - 1);
		map->biggest_square.size = cur_size;
	}
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*double_size(char *buffer, int size)
{
	char	*tmp;
	int		new_size;

	new_size = size * 2;
	tmp = malloc(sizeof(char) * (new_size));
	ft_strncpy(tmp, buffer, size);
	free(buffer);
	return (tmp);
}
