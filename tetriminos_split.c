/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:04:06 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/04 18:15:23 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include "fillit.h"
#include <stdio.h>
#include "libft.h"

char	*trim_tetri(char const *input)
{
	int i;
	t_coords *coords;
	t_coords *dim;
	int tmp;
	char *tetri;

	i = 0;
	if (!(coords = ft_memalloc(sizeof(t_coords))))
		return (NULL);
	coords->x = 4;
	coords->y = 4;
	if (!(dim = ft_memalloc(sizeof(t_coords))))
		return (NULL);
	dim->x = 0;
	dim->y = 0;
	tmp = 0;
	while (i < 21)
	{
		if (input[i] == '#')
		{
			coords->x = MIN(coords->x, i % 5);
			coords->y  = MIN(coords->y, i / 5);
			tmp = MAX(tmp, i % 5);
			dim->x = tmp - coords->x + 1;
			dim->y = MAX(dim->y, ((i / 5) + 1) - coords->y);
		}
		i++;
	}
	if (!(tetri = ft_strnew((dim->x * dim->y) + dim->y)))
		return (NULL);
	i = 0;
	while (i < dim->y)
	{
		tmp = ((coords->y + i) * 5) + coords->x;
		ft_strncat(tetri, input + tmp, dim->x);
		ft_strncat(tetri, "\n", 1);
		i++;
	}
	free(coords);
	free(dim);
	return (tetri);
}

char **tetri_split(char const *input)
{
	char	**split;
	int		i;
	int		size;

	size = (ft_strlen(input) / 21) + 2;
	if (!(split = (char **)ft_memalloc(sizeof(char *) * size)))
		return (NULL);
	i = 0;
	while (*input && i < size - 1)
	{
		if (!(split[i++] = trim_tetri(input)))
			return (NULL); //also free formers
		input += 21;
	}
	split[i] = NULL;
	return (split);
}
