/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:19:05 by mel-meka          #+#    #+#             */
/*   Updated: 2023/10/04 15:03:50 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <unistd.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	t_map	map;
	int		i;

	map.biggest_square.size = 0;
	map.lines_len = 0;
	map.line_len = 0;
	if (ac == 1)
	{
		if (!load_map(0, &map))
			write(2, "map error\n", 10);
		else
			map_print(&map);
	}
	else
	{
		i = 1;
		while (i < ac)	
		{
			if (!load_map(av[i], &map))
				write(2, "map error\n", 10);
			else
				map_print(&map);
			reset_map(&map);
			i++;
		}
	}
}
