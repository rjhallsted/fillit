/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:04:06 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/01 17:08:49 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **tetriminos_split(char *tetriminos)
{
    char split_tetriminos[24][21];
    int i;
    int s;
    int c;

    i = 0;
    s = 0;
    c = 0;
    while(tetriminos[i])
    {
        if(i == 20 || i == (20 + (21 * s)))
        {
            s++;
            c = 0;
            i++;
        }
        split_tetriminos[s][c] = tetriminos[i];
        c++;
        i++;
    }
    return(**split_tetriminos);
}
