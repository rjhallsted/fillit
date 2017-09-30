/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:42:59 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/30 12:48:09 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//need to write duplicate_list, free_list

#include "libft.h"
#include "fillit.h"

int		loop_through_candidates(char **map, size_t map_size, t_list *piece)
{
	t_list	*start;
	int 	i;
	int		list_len;
	int		found;

	start = duplicate_list(piece);
	i = 0;
	list_len = ft_lstlen(piece);
	found = 0;
	while (i < list_len && !found;)
	{	
		start = list_swap(start, 0, i);
		found = consider_candidate(map, map_size, start);
		i++;
	}
	free_list(start);
	return (found);
}

int 	consider_candidate(char **map, size_t map_size, t_list *piece)
{
	if (reject(map, map_size, piece))
		return (0);
	set_piece(map, map_size, piece);	
	if (accept(map, map_size, piece))
		return (1);
	remove_piece(map, map_size, piece);
	return (loop_through_candidates(map, map_size, piece->next));
}

int		reject(char **map, size_t map_size, t_list *piece)
{
	//check to see if piece obviously wont fit (too wide, too tall);
	//then loop through available starting points, and see if piece can be place there.
}

int		accept(char **map, size_t map_size, t_list *piece)
{
	//check to see if there's any pieces left.
}

void	set_piece(char **map, size_t map_size, t_list *piece)
{
	//place piece in first available location
}

void	remove_piece(char **map, size_t map_size, t_list *piece)
{
	//check piece identifier, and replace occurrences of it in map with `.`
	int i;

	i = 0;
	while (i < map_size * map_size)
	{
		if (map[i / map_size][i % map_size] == piece->id)
			map[i / map_size][i % map_size] == '.';
		i++;
	}
}
