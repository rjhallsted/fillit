/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:36:45 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/01 13:12:34 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
 #include <fcntl.h>
 #include <stdlib.h>
 #include <stdio.h>
  #include <unistd.h>

typedef struct		s_list
{
	char			**shape;
	char			id;
	int				dimensions[2];
	struct s_list	*next;
}					t_list;

char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char    			*read_input(const char *file);

size_t				ft_strlen(const char *str);
int                 crash_report(char *error_type);
void	            ft_putchar(char c);

unsigned int        check_input(char *tetriminos);

#endif
