/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:10:58 by mel-meka          #+#    #+#             */
/*   Updated: 2023/10/04 18:02:31 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_square {
	int	x;
	int	y;
	int	size;
}	t_square;

typedef struct s_map
{
	int			**lines;
	int			lines_len;
	int			line_len;
	char		empty;
	char		obstacle;
	char		full;
	t_square	biggest_square;
}	t_map;

int		load_map(char *path, t_map *map);
void	map_print(t_map *map);

int		is_valid(t_map *map);
int		char_to_val(t_map *map, char c);
void	set_biggest_square(t_map *map, int i, int j);

void	ft_strncpy(char *dest, char *src, int n);
char	*double_size(char *buffer, int size);

void	reset_map(t_map *map);
void	set_map(t_map *map);
int		load_file_header(int fd, t_map *map);

int		is_numeric(char c);
int		min3(int a, int b, int c);

#endif
