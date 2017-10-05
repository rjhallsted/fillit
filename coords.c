/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:27:50 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/05 14:29:00 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

t_coords	*new_coords(int x, int y)
{
	t_coords *new;

	if (!(new = ft_memalloc(sizeof(t_coords))))
		return (NULL);
	new->x = x;
	new->y = y;
	return (new);
}
