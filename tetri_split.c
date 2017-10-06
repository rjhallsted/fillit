/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:04:06 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/05 19:04:59 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

static t_coords	*set_dims(t_coords *dim, t_coords *coords, int i, int tmp)
{
	dim->x = tmp - coords->x + 1;
	dim->y = MAX(dim->y, ((i / 5) + 1) - coords->y);
	return (dim);
}

static t_coords	*set_coords(t_coords *coords, int i)
{
	coords->x = MIN(coords->x, i % 5);
	coords->y = MIN(coords->y, i / 5);
	return (coords);
}

static char		*build_piece(t_coords *coords, t_coords *dim,
					char const *input)
{
	char	*tetri;
	int		tmp;
	int		i;

	if (!(tetri = ft_strnew((dim->x * dim->y) + dim->y)))
		return (NULL);
	i = -1;
	while (++i < dim->y)
	{
		tmp = ((coords->y + i) * 5) + coords->x;
		ft_strncat(tetri, input + tmp, dim->x);
		ft_strncat(tetri, "\n", 1);
	}
	return (tetri);
}

static char		*trim_tetri(char const *input)
{
	int			i;
	t_coords	*coords;
	t_coords	*dim;
	int			tmp;
	char		*tetri;

	if (!(coords = new_coords(4, 4)))
		return (NULL);
	if (!(dim = new_coords(0, 0)))
		return (NULL);
	tmp = 0;
	i = -1;
	while (++i < 21)
		if (input[i] == '#')
		{
			coords = set_coords(coords, i);
			tmp = MAX(tmp, i % 5);
			dim = set_dims(dim, coords, i, tmp);
		}
	if (!(tetri = build_piece(coords, dim, input)))
		return (NULL);
	free(coords);
	free(dim);
	return (tetri);
}

char			**tetri_split(char const *input)
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
		{
			ft_free_2d_array((void ***)&split, i - 2);
			return (NULL);
		}
		input += 21;
	}
	split[i] = NULL;
	return (split);
}
