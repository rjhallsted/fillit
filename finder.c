/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 00:03:35 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/05 14:52:44 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

#include <stdio.h>

t_coords		*find_dimensions(char const *shape)
{
	t_coords	*coords;

	if (!(coords = new_coords(0, 0)))
		return (NULL);
	while (*shape)
	{
		if (*shape == '\n')
			coords->y++;
		else if (coords->y == 0)
			coords->x++;
		shape++;
	}
	return (coords);
}

static size_t	piece_count(char **piece)
{
	int i;

	i = 0;
	while (*piece++)
		i++;
	return (i);
}

int				solution_finder(char **piece)
{
	int		solution_found;
	size_t	map_size;
	char	**map;

	solution_found = 0;
	map_size = 1;
	while (!solution_found)
	{
		map_size++;
		if (!(map = make_map(map_size)))
			return (1);
		solution_found = loop_candidates(map, map_size, piece, 'A');
		if (!solution_found)
			ft_free_2d_array((void ***)&map, map_size);
	}
	ft_free_2d_array((void ***)&piece, piece_count(piece));
	print_map(map, map_size);
	ft_free_2d_array((void ***)&map, map_size);
	return (0);
}
