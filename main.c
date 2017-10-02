/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:29:49 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/02 12:30:08 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

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

t_list	*allocate_list(char **split_input) {
	t_list	*start;
	t_list	*piece;
	int 	i;
	
	if(!(start = new_item(split_input[0], 'A')))
		return (NULL);
	piece = start;
	i = 1;
	while(split_input[i])
	{
		if(!(piece->next = new_item(split_input[i], 'A' + i)))
		{
			free_list(&start);
			return (NULL);
		}
		i++;
		piece = piece->next;
	}
	return (start);
}

int		main(int argc, char **argv)
{
	char	*input;
	t_list	*start_piece;
	char 	**map;
	size_t	map_size;
	int		solution_found;

    if(argc == 2)
    {
	    if(!(input = read_input(argv[1])))
		{
			ft_putstr("Error\n");
			return (2); //2 refers to a file error
		}
        if(!check_input(input))
		{
			ft_putstr("Error\n");
			return (2); //2 refers to a file error
		}
		if(!(start_piece = allocate_list(tetriminos_split(input))))
			return (1);
		solution_found = 0;
		map_size = 1;
		while (!solution_found)
		{
			map_size++;
			if (!(map = make_map(map_size)))
				return (1); //1 will refer to a memory allocation failure
			solution_found = loop_through_candidates(map, map_size, start_piece);
		}
		free_list(&start_piece);
		print_map(map, map_size);
		ft_free_2d_array((void ***)&map, map_size);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
