/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:04:06 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/02 14:55:26 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include "fillit.h"

char **tetriminos_split(char *tetriminos)
{
    char **split_tetriminos;
    int i;
    int s;
    int c;

    i = 0;
    s = 0;
    c = 0;
    split_tetriminos = malloc(sizeof(char *) * 572);
    while(tetriminos[i])
    {
        if(c >= 4)
        {
            s++;
            c = 0;
        }
        if (tetriminos[i] == '.' && tetriminos[i+1] == '#')
            i++;
        if (tetriminos[i] == '.' && tetriminos[i+1] == '.' && tetriminos[i+2] == '.' && tetriminos[i+3] == '.')
            i += 4;
        split_tetriminos[s] = malloc(sizeof(tetriminos));
        split_tetriminos[s][c] = tetriminos[i];
        i++;
    }
    return(split_tetriminos);
}
