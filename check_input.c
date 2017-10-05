/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 12:27:37 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/04 21:13:57 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

unsigned int     check_input(char *tetriminos)
{
    int i;
    int c;
    int ct;
    int tc;
    int cc;

    cc = 0;
    ct = 0;
    tc = 0;
    i = 0;
    c = 0;
    if (!tetriminos[i])
        return (0);
    while (tetriminos[i])
    {
        if (tetriminos[i] == '#')
        {
            if(tetriminos[i+1] == '#')
                cc++;
            if(tetriminos[i-1] == '#')
                cc++;
            if(tetriminos[i+5] == '#' &&
                ((tetriminos[i+1] != '\n' && tetriminos[i+2] != '\n') ||
                (tetriminos[i+2] != '\n' && tetriminos[i+3] != '\n') ||
                (tetriminos[i+3] != '\n' && tetriminos[i+4] != '\n')))
                cc++;
            if(tetriminos[i-5] == '#' &&
                ((tetriminos[i-1] != '\n' && tetriminos[i-2] != '\n') ||
                (tetriminos[i-2] != '\n' && tetriminos[i-3] != '\n') ||
                (tetriminos[i-3] != '\n' && tetriminos[i-4] != '\n')))
                cc++;
            tc++;
            c++;
        }
        else if (tetriminos[i] == '.')
            c++;
        else if ((tetriminos[i] == '\n' || tetriminos[i] == '\0') && c == 4)
        {
            c = 0;
            ct++;
        }
        else if (tetriminos[i] == '\n' && c == 0 && tc == 4)
        {
            if(!(cc == 6 || cc == 8))
                return (0);
            cc = 0;
            ct = 0;
            tc = 0;
        }
        else
            return (0);
        i++;
        if (tetriminos[i] == '\0' && ct != 4)
            return (0);
    }
    if(!(cc == 6 || cc == 8))
        return (0);
    if(tc != 4)
        return (0);
    return (1);
}
