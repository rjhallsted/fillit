/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:42:59 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/05 15:23:34 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

extern		size_t g_map_size;

int			loop_candidates(char **map, char **piece, char id)
{
	int 		i;
	int			found;
	int			tmp;
	t_coords	*start_at;

	i = 0;
	found = 0;
	if (!(start_at = find_placement(map, piece, 0)))
		return (0);
	while (start_at && !found)
	{
		found = consider(map, piece, start_at, id);
		if (!found)
		{
			remove_piece(map, id);
			tmp = (start_at->y * g_map_size) + start_at->x + 1;
			free(start_at);
			if (!(start_at = find_placement(map, piece, tmp)))
				return (0);
		}
		else
			free(start_at);
	}
	return (found);
}

int			consider(char **map, char **piece, t_coords *coords, char id)
{
	set_piece(map, piece, coords, id);
	if (*(piece + 1) == NULL)
		return (1);
	return (loop_candidates(map, piece + 1, id + 1));
}

void		set_piece(char **map, char **piece, t_coords *coords, char id)
{
	int			x;
	int			y;
	t_coords	*dim;

	x = 0;
	y = 0;
	dim = find_dimensions(*piece);
	while (y < dim->y)
	{
		while (x < dim->x)
		{
			if ((*piece)[(y * (dim->x + 1)) + x] == '#')
			{
				map[coords->y + y][coords->x + x] = id;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void		remove_piece(char **map, char id)
{
	size_t i;

	i = 0;
	while (i < g_map_size * g_map_size)
	{
		if (map[i / g_map_size][i % g_map_size] == id)
			map[i / g_map_size][i % g_map_size] = '.';
		i++;
	}
}

t_coords	*find_placement(char **map, char **piece, size_t start_at)
{
	t_coords	*coords;
	size_t		i;
	t_coords	*dim;

	dim = find_dimensions(*piece);
	if (!(coords = (t_coords *)malloc(sizeof(t_coords))))
		return (NULL);
	i = start_at;
	while (i < g_map_size * g_map_size)
	{
		coords->y = i / g_map_size;
		coords->x = i % g_map_size;
		if (can_place_here(map, piece, coords, dim))
			return (coords);
		i++;
	}
	return (NULL);
}

int			can_place_here(char **map, char **piece, t_coords *coords, t_coords *dim)
{
	int y;
	int x;

	y = 0;
	x = 0;
	if (dim->x > (int)g_map_size || dim->y > (int)g_map_size)
		return (0);
	while (y < dim->y && coords->y + y < (int)g_map_size)
	{
		while (x < dim->x && coords->x + x < (int)g_map_size)
		{
			if (map[coords->y + y][coords->x + x] != '.' &&
				(*piece)[(y * (dim->x + 1)) + x] == '#')
				return (0);
			x++;
		}
		if (x < dim->x)
			return (0);
		x = 0;
		y++;
	}
	if (y < dim->y)
		return (0);
	return (1);
}
