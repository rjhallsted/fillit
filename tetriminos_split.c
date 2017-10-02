/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:04:06 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/02 11:12:45 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        if(c == 21 || c == (21 + (21 * s)))
        {
            s++;
            c = 0;
        }
        while(tetriminos[i] == ".")
            i++;
        split_tetriminos[s] = malloc(sizeof(tetriminos));
        split_tetriminos[s][c] = tetriminos[i];
        printf("%d", split_tetriminos[s][c]);
        c++;
        i++;
    }
    return(split_tetriminos);
}
