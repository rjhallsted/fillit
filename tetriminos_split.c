/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:53:02 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/01 16:00:37 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char **tetriminos_split(char *tetriminos)
{
    char **split_tetriminos = NULL;
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
        }
        split_tetriminos[s][c] = tetriminos[i];
        c++;
        i++;
    }
    return(split_tetriminos);
}
