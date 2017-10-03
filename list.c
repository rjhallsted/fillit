/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 00:03:35 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/03 11:37:11 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

#include <stdio.h>

static t_coords	*find_dimensions(char const *shape)
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

t_list	*new_item(char *shape, char id)
{
	t_list *new;

	if(!(new = ft_memalloc(sizeof(t_list))))
		return (NULL);
	new->shape = ft_strdup(shape);
	new->id = id;
	if (!(new->dim = find_dimensions(shape)))
		return (NULL);
	printf("dims: %dx%d\n", new->dim->x, new->dim->y);
	printf("%s\n", shape);
	new->next = NULL;
	return (new);
}

void	free_item(t_list **item)
{
	free((*item)->shape);
	free((*item)->dim);
	free(*item);
	*item = NULL;
}

void	free_list(t_list **item)
{
	t_list *tmp;

	while (*item)
	{
		tmp = (*item)->next;
		free_item(item);
		*item = tmp;
	}
	item = NULL;
}

