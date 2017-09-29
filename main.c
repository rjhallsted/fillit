/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:48:47 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/28 15:15:32 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

char	**make_map(int map_size)
{
	char **map;
	int i;	

	if (!(map = ft_memalloc(sizeof(char *) * map_size)))
		return (NULL);
	i = 0;
	while (i < map_size)
	{
		if (!(map[i] = ft_strnew(map_size)))
		{
			ft_free_2d_array(map, i);
			return (NULL);
		}
		i++;
	}
	return (map);
}

int		main(int argc, char **argv)
{
	//file reading stuff here.
	//start_piece will be set by file reading stuff
	t_list *start_piece;

	char 	**map;
	int		map_size;
	int		solution_found;

	solution_found = 0;
	map_size = 2;
	while (!solution_found)
	{
		if (!(map = make_map(map_size)))
			return (1); //1 will refer to a memory allocation failure
		solution_found = loop_through_candidates(map, map_size, start_piece);
		map_size++;
	}
	//print solution here
}
