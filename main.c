/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:29:49 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/01 19:00:06 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

char	**make_map(size_t map_size)
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

void	free_map(char ***map, size_t map_size)
{
	size_t i;

	i = 0;
	while (i < map_size)
		free(*map[i++]);
	free(*map);
	*map = NULL;
}

void allocate_list(char **split_input, t_list *piece) {
	int i;

	i = 1;
	*start_piece = split_input[0];
	while(split_input[i])
	{
		piece->next = split_input[i++];
		piece = piece->next;
	}
}

int		main(int argc, char **argv)
{
	char	*input;
	char	**split_input;
	t_list	*start_piece;
	char 	**map;
	size_t	map_size;
	int		solution_found;

    if(argc == 2)
    {
        input = read_input(argv[1]);
        if(!check_input(input))
			ft_putstr("Error\n");
		split_input = tetriminos_split(input);
		allocate_list(split_input, piece->next);
		solution_found = 0;
		map_size = 1;
		while (!solution_found)
		{
			map_size++;
			if (!(map = make_map(map_size)))
				return (1); //1 will refer to a memory allocation failure
			solution_found = loop_through_candidates(map, map_size, start_piece);
		}
		print_map(map, map_size);
		free_map(map, map_size);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
