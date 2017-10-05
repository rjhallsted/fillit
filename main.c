/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:24:58 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/05 14:24:59 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

#include <stdio.h>

char		**make_map(size_t map_size)
{
	char	**map;
	size_t	i;

	if (!(map = ft_memalloc(sizeof(char *) * map_size)))
		return (NULL);
	i = 0;
	while (i < map_size)
	{
		if (!(map[i] = ft_strnew(map_size)))
		{
			ft_free_2d_array((void ***)&map, i);
			return (NULL);
		}
		ft_memset(map[i], '.', map_size);
		i++;
	}
	return (map);
}

void		print_map(char **map, size_t map_size)
{
	size_t i;

	i = 0;
	while (i < map_size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

/*
** Return 2 refers to a file error
** Return 1 refers to a memory allocation failure
*/

static int	error(int error_type)
{
	ft_putstr("error\n");
	return (error_type);
}

int			main(int argc, char **argv)
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
			return (1);
	}
	else
		ft_putstr("error\n");
	return (0);
}
