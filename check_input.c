/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 12:27:37 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/01 15:52:52 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include "fillit.h"

unsigned int     check_input(char *tetriminos)
{
    int i;
    int c;
    int ct;
    int tc;

    ct = 0;
    tc = 0;
    i = 0;
    c = 0;
    if (!tetriminos[i])
        return(crash_report("Empty File\n"));
    while (tetriminos[i])
    {
        if (tetriminos[i] == '#' && tc < 4)
            tc++;
        else if (tetriminos[i] == '#' && tc == 4)
            return(crash_report("Tetriminos too large\n"));
        if (tetriminos[i] == '#' || tetriminos[i] == '.')
            c++;
        else if ((tetriminos[i] == '\n' || tetriminos[i] == '\0') && c == 4)
        {
            c = 0;
            ct++;
        }
        else if (tetriminos[i] == '\n' && c == 0 && ct == 4)
        {
            ct = 0;
            tc = 0;
        }
        else
            return(crash_report("Incorrect Square Size\n"));
        i++;
        if (tetriminos[i] == '\0' && ct != 4)
            return(crash_report("Input File Does Not End Correctly\n"));
    }
    return (1);
}
