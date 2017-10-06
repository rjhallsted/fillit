/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:56:21 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/05 16:41:45 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "fillit.h"

char	*read_input(const char *file)
{
	int		fd;
	int		read_stat;
	int		i;
	char	tmp[26 * 21];
	char	buffer[1];

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	while ((read_stat = read(fd, buffer, 1)))
	{
		tmp[i++] = buffer[0];
		if (i > (26 * 21))
			return (NULL);
	}
	tmp[i] = '\0';
	if ((close(fd)) == -1)
		return (NULL);
	return (ft_strdup(tmp));
}
