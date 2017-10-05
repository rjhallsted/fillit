/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 12:27:37 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/05 11:36:01 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

unsigned int     check_input(char *tetriminos)
{
    int i;
    int line_len;
    int piece_line_count;
    int pound_count;
    int connection_count;

    connection_count = 0;
    piece_line_count = 0;
    pound_count = 0;
    i = 0;
    line_len = 0;
    if (!tetriminos[i])
        return (0);
    while (tetriminos[i])
    {
        if (tetriminos[i] == '#')
        {
            if(tetriminos[i+1] == '#')
                connection_count++;
            if(tetriminos[i-1] == '#')
                connection_count++;
            if(tetriminos[i+5] == '#' &&
                ((tetriminos[i+1] != '\n' && tetriminos[i+2] != '\n') ||
                (tetriminos[i+2] != '\n' && tetriminos[i+3] != '\n') ||
                (tetriminos[i+3] != '\n' && tetriminos[i+4] != '\n')))
                connection_count++;
            if(tetriminos[i-5] == '#' &&
                ((tetriminos[i-1] != '\n' && tetriminos[i-2] != '\n') ||
                (tetriminos[i-2] != '\n' && tetriminos[i-3] != '\n') ||
                (tetriminos[i-3] != '\n' && tetriminos[i-4] != '\n')))
                connection_count++;
            pound_count++;
            line_len++;
        }
        else if (tetriminos[i] == '.')
            line_len++;
        else if ((tetriminos[i] == '\n' || tetriminos[i] == '\0') && line_len == 4)
        {
            line_len = 0;
            piece_line_count++;
        }
        else if (tetriminos[i] == '\n' && line_len == 0 && pound_count == 4)
        {
            if(!(connection_count == 6 || connection_count == 8))
                return (0);
            connection_count = 0;
            piece_line_count = 0;
            pound_count = 0;
        }
        else
            return (0);
        i++;
        if (tetriminos[i] == '\0' && piece_line_count != 4)
            return (0);
    }
    if(!(connection_count == 6 || connection_count == 8))
        return (0);
    if(pound_count != 4)
        return (0);
    return (1);
}
