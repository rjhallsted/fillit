/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:29:49 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/04 12:54:38 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

#include <stdio.h>

char	**make_map(size_t map_size)
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

void	print_map(char **map, size_t map_size)
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

int		main(int argc, char **argv)
{
	char	*input;
	char	**start_piece;
	char 	**map;
	char	id;
	size_t	map_size;
	int		solution_found;

	id = 'A';
    if(argc == 2)
    {
	    if(!(input = read_input(argv[1])))
		{
			ft_putstr("error\n");
			return (2); //2 refers to a file error
		}
        if(!check_input(input))
		{
			ft_putstr("error\n");
			return (2); //2 refers to a file error
		}
		if(!(start_piece = tetri_split(input)))
			return (1);
		solution_found = 0;
		map_size = 1;
		while (!solution_found && map_size < 10)
		{
			map_size++;
			printf("Map size: %d\n", (int)map_size);
			if (!(map = make_map(map_size)))
				return (1); //1 will refer to a memory allocation failure
			solution_found = loop_through_candidates(map, map_size, start_piece, id);
			if (!solution_found)
			{
				print_map(map, map_size);
				ft_free_2d_array((void ***)&map, map_size);
			}
		}
		print_map(map, map_size);
		ft_free_2d_array((void ***)&map, map_size);
	}
	else
		ft_putstr("error\n");
	return (0);
}
