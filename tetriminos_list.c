/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:33:01 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/01 16:54:57 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const **shape, s_coords dimensions)
{
	t_list *nlink;

	nlink = (s_coords*)malloc(sizeof(s_coords));
	if (!nlink)
		return (NULL);
	if (!*shape)
	{
		nlink->shape = NULL;
		nlink->dimensions = (0, 0);
	}
	else
	{
		nlink->shape = malloc(*shape);
		if (!*shape)
		{
			free(nlink);
			return (NULL);
		}
		ft_memcpy(nlink->shape, *shape, dimensions);
		nlink->dimensions = dimensions;
	}
	nlink->next = NULL;
	return (nlink);
}
