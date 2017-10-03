/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:42:59 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/03 12:14:55 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

int		loop_through_candidates(char **map, size_t map_size, t_list *piece)
{
	int 	i;
	int		list_len;
	int		found;

	i = 0;
	list_len = ft_lstlen(piece);
	found = 0;
	while (i < list_len && !found)
	{	
		piece = ft_lst_swap(&piece, 0, i);
		found = consider_candidate(map, map_size, piece);
		if (!found)
		{
			remove_piece(map, map_size, piece);
			piece = ft_lst_swap(&piece, 0, i);
			i++;
		}
	}
	return (found);
}

int 	consider_candidate(char **map, size_t map_size, t_list *piece)
{
	t_coords *coords;

	if (!(coords = find_first_placement(map, map_size, piece)))
	{
		free(coords);
		return (0);
	}
	set_piece(map, piece, coords);
	free(coords);
	if (accept(piece))
		return (1);
	return (loop_through_candidates(map, map_size, piece->next));
}

int		accept(t_list *piece)
{
	return (ft_lstlen(piece) == 1);
}

void	set_piece(char **map, t_list *piece, t_coords *coords)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < piece->dim->y)
	{
		while (x < piece->dim->x)
		{
			if (piece->shape[(y * (piece->dim->x + 1)) + x] == '#')
				map[coords->y + y][coords->x + x] = piece->id;
			x++;
		}
		x = 0;
		y++;
	}
}

void	remove_piece(char **map, size_t map_size, t_list *piece)
{
	size_t i;

	i = 0;
	while (i < map_size * map_size)
	{
		if (map[i / map_size][i % map_size] == piece->id)
			map[i / map_size][i % map_size] = '.';
		i++;
	}
}

t_coords *find_first_placement(char **map, size_t map_size, t_list *piece)
{
	t_coords	*coords;
	size_t		i;;
	
	if (!(coords = (t_coords *)malloc(sizeof(t_coords))))
		return (NULL);
	i = 0;
	while (i < map_size * map_size)
	{
		coords->y = i / map_size;
		coords->x = i % map_size;
		if (can_place_here(map, map_size, piece, coords))
			return (coords);
		i++;
	}
	return (NULL);	
}

int		can_place_here(char **map, size_t map_size, t_list *piece, t_coords *coords)
{
	int y;
	int x;

	y = 0;
	x = 0;
	if (piece->dim->x > (int)map_size || piece->dim->y > (int)map_size)
		return (0);
	while (y < piece->dim->y && coords->y + y < (int)map_size)
	{
		while (x < piece->dim->x && coords->x + x < (int)map_size)
		{
			if (map[coords->y + y][coords->x + x] != '.' && piece->shape[(y * (piece->dim->x + 1)) + x] == '#')
				return (0);
			x++;
		}
		if (x < piece->dim->x)
			return (0);
		x = 0;
		y++;
	}
	if (y < piece->dim->y)
		return (0);
	return (1);
}
