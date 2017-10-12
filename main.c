/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:24:58 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/12 12:22:30 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

char			*make_map(size_t map_size)
{
	char	*map;
	size_t	i;

	if (!(map = (char *)ft_memalloc(sizeof(char) * (map_size + 1) * map_size)))
		return (NULL);
	i = 0;
	while (i < (map_size + 1) * map_size)
	{
		ft_memset(&map[i], '.', map_size);
		i += map_size;
		ft_memset(&map[i], '\n', 1);
		i++;
	}
	return (map);
}

/*
** Return 2 refers to a file error
** Return 1 refers to a memory allocation failure
*/

static int		error(int error_type)
{
	ft_putstr("error\n");
	return (error_type);
}

int				main(int argc, char **argv)
{
	char	*input;
	char	**piece;

	if (argc == 2)
	{
		if (!(input = read_input(argv[1])) || (!validate_input(input)))
			return (error(2));
		if (!(piece = tetri_split(input)))
			return (error(1));
		if (solution_finder(piece))
			return (0);
	}
	else
		ft_putstr("usage: ./fillit [file]\n");
	return (0);
}

t_coords		*find_placement(char *map, char **piece, t_coords *dim,
					size_t start_at)
{
	t_coords	*coords;
	size_t		i;

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

int				can_place_here(char *map, char **piece, t_coords *crds,
					t_coords *dim)
{
	int y;
	int x;

	y = 0;
	x = 0;
	if (dim->x > (int)g_map_size || dim->y > (int)g_map_size)
		return (0);
	while (y < dim->y && crds->y + y < (int)g_map_size)
	{
		while (x < dim->x && crds->x + x < (int)g_map_size)
		{
			if ((map[(crds->y + y) * (g_map_size + 1) + (crds->x + x)]) != '.'
					&& (*piece)[(y * (dim->x + 1)) + x] == '#')
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
