/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 00:03:35 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/02 11:38:38 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static t_coords	*find_dimensions(char const *shape)
{
	t_list	*coords;

	if (!(coords = ft_memalloc(sizeof(t_coords))))
		return (NULL);
	coords->x = 0;
	coords->y = 0;
	while (*shape)
	{
		if (*shape == '\n')
			coords->y++;
		else if (coords->y == 0 &&)
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
	new->next = NULL;
	return (new);
}

void	free_item(t_list **item)
{
	free((*item)->shape);
	free((*item)->coords);
	free(*item);
	*item = NULL;
}

void	free_list(t_list **item)
{
	t_list *tmp;

	while (*item)
	{
		tmp = *item->next;
		free_item(item);
		*item = tmp;
	}
	item = NULL;
}

