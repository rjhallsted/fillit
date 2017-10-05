/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 00:03:35 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/05 15:23:57 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

extern			size_t g_map_size;

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
	char	**map;

	solution_found = 0;
	g_map_size = 1;
	while (!solution_found)
	{
		g_map_size++;
		if (!(map = make_map(g_map_size)))
			return (1);
		solution_found = loop_candidates(map, piece, 'A');
		if (!solution_found)
			ft_free_2d_array((void ***)&map, g_map_size);
	}
	ft_free_2d_array((void ***)&piece, piece_count(piece));
	print_map(map, g_map_size);
	ft_free_2d_array((void ***)&map, g_map_size);
	return (0);
}
