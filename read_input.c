/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:56:21 by sjuery            #+#    #+#             */
/*   Updated: 2017/09/28 21:13:14 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *read_input(const char *file) {
   int  fd;

   char *buffer;

   if ((fd = open(file, O_RDONLY)) == -1)
      printf("Error");

   int size = lseek(fd, 0, SEEK_END);
   lseek(fd, 0, SEEK_SET);
   buffer = (char*)malloc(size+1);
   read(fd, buffer, size);
   close(fd);

   return buffer;
}
