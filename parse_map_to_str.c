/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolyans <fpolyans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 08:25:01 by fpolyans          #+#    #+#             */
/*   Updated: 2017/07/19 23:16:16 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

void	parse_map_to_str(char *file_name, int file_size, int first_newline)
{
	int		ret;
	int		i;

	i = 0;
	/* write g_map_data to str */
	free(g_buf);
	g_map_data = (char*)malloc(first_newline);
	g_fd = open(file_name, O_RDWR);
	ret = read(g_fd, g_map_data, first_newline);
	/* write map to str */
	g_buf = (char*)malloc(sizeof(char) * file_size + 1);
	ret = read(g_fd, g_buf, file_size);
	g_buf[ret] = '\0';
	close(g_fd);
}
