/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:56:21 by sjuery            #+#    #+#             */
/*   Updated: 2017/09/29 11:47:52 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char    *read_input(const char *file)
{
    int         fd;
    int         read_stat;
    int         i;
    char        tmp[545];
    char        buffer[1];

    i = 0;
    if ((fd = open(file, O_RDONLY)) == -1)
        printf("Error");

    while ((read_stat = read(fd, buffer, 1)))
    {
        tmp[i++] = buffer[0];
        if (i > 545)
            printf("Error");
    }
    tmp[i] = '\0';
    if (close(fd) == -1)
        printf("Error");
    return (ft_strdup(tmp));
}
