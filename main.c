/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolyans <fpolyans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 16:29:32 by fpolyans          #+#    #+#             */
/*   Updated: 2017/09/28 12:06:58 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

void read_first_file(int *arg_fd, char **file_name, int *ret, int *byte_counter, int *first_newline)
{
	int		first;
	int		i;

	i = 0;
	first = 1;
	g_buf = (char*)malloc(sizeof(char) * 1);
	*arg_fd = open(*file_name, O_RDWR);
	g_fd = open("buffer.txt", O_RDWR);
	while((*ret = read(*arg_fd, g_buf, 1)))
	{
		*byte_counter += ft_strlen(g_buf);
		write(g_fd, g_buf, 1);
		if(g_buf[0] == '\n' && first == 1)
		{
			*first_newline = *byte_counter;
			first = 0;
		}
	}
	g_buf[*ret] = '\0';
	close(g_fd);
}

int		main(int ac, char **av)
{
	int		i;
	int		arg_fd;
	int		ret;
	int		byte_counter;
	int		first_newline;

	i = 1;
	byte_counter = 0;
	if (ac > 1)
	{
		/* read from arguments, in a loop */
		while (av[i])
		{
			read_first_file(&arg_fd, &av[i], &ret, &byte_counter, &first_newline);
			/* write map to a string */
			parse_map_to_str(av[i], byte_counter, first_newline);
			ft_putstr(g_buf);
			/* error handling, validify map */
			if (validate_map())
			{
				ft_putstr("map error\n");
				return (0);
			}
			i++;
		}
	}
	return (1);
}
