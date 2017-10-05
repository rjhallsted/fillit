/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 00:03:35 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/04 12:02:18 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

#include <stdio.h>

t_coords	*find_dimensions(char const *shape)
{
	t_coords	*coords;

	if (!(coords = ft_memalloc(sizeof(t_coords))))
		return (NULL);
	coords->x = 0;
	coords->y = 0;
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
